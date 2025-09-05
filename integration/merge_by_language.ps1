& git fetch --all --prune

# Targets to collect into
$targets = @('c++','java','python','main')

# gather local and remote branch lists
$localBranches = ((& git for-each-ref --format='%(refname:short)' refs/heads/) -split "`n") | Where-Object { $_ }
$remoteBranches = ((& git for-each-ref --format='%(refname:short)' refs/remotes/) -split "`n") | Where-Object { $_ }

Write-Host "Local branches: $($localBranches -join ', ')"
Write-Host "Remote branches: $($remoteBranches -join ', ')"

foreach ($target in $targets) {
    Write-Host "`n===== Target branch: $target ====="

    # Ensure local target exists; prefer origin/<target> then any remote that ends with /<target>
    if (-not ($localBranches -contains $target)) {
        $preferredRemote = $null
        if ($remoteBranches -contains "origin/$target") { $preferredRemote = "origin/$target" }
        elseif ($remoteBranches -contains "mainbranch/$target") { $preferredRemote = "mainbranch/$target" }
        else {
            # try any remote that ends with /<target>
            $match = $remoteBranches | Where-Object { $_ -match "/$([Regex]::Escape($target))$" } | Select-Object -First 1
            if ($match) { $preferredRemote = $match }
        }

        if ($preferredRemote) {
            Write-Host "Creating local '$target' from '$preferredRemote'"
            & git checkout -B $target $preferredRemote
        } else {
            Write-Host "Creating local '$target' from current HEAD"
            & git checkout -B $target
        }
        # refresh local branches list
        $localBranches = ((& git for-each-ref --format='%(refname:short)' refs/heads/) -split "`n") | Where-Object { $_ }
    } else {
        Write-Host "Checking out existing '$target'"
        & git checkout $target
    }

    # Build pattern for matching source branches: contains target name (case-insensitive)
    $pattern = [Regex]::Escape($target)

    # Candidate sources: local branches and remote branches that mention the target but are not the target itself
    $sources = @()
    $sources += $localBranches | Where-Object { $_ -and $_ -ne $target -and ($_ -match $pattern) }
    $sources += $remoteBranches | Where-Object { $_ -and ($_ -notmatch 'HEAD$') -and ($_ -notmatch '/'+[Regex]::Escape($target)+'$') -and ($_ -match $pattern) }
    $sources = $sources | Select-Object -Unique

    if (-not $sources) {
        Write-Host "No source branches found for target '$target'. Skipping."
        continue
    }

    Write-Host ("Found source branches for {0}: {1}" -f $target, ($sources -join ', '))

    foreach ($src in $sources) {
        Write-Host "`n-- Adding from source: $src --"
        # List files tracked in source
        $filesRaw = & git ls-tree -r --name-only $src
        if ($LASTEXITCODE -ne 0) {
            Write-Host "  Failed to list files for $src. Skipping."
            continue
        }
        $files = $filesRaw -split "`n" | Where-Object { $_ -and $_ -ne '.gitignore' }

        $addedAny = $false
        foreach ($file in $files) {
            $path = $file -replace '/', '\\'
            if (-not (Test-Path $path)) {
                Write-Host "  Adding: $file"
                & git checkout $src -- "$file"
                if ($LASTEXITCODE -ne 0) {
                    Write-Host "    Failed to checkout $file from $src"
                    continue
                }
                & git add -- "$file"
                $addedAny = $true
            } else {
                Write-Host "  Exists: $file (skipping)"
            }
        }

        if ($addedAny) {
            & git commit -m "Add files from '$src' into '$target' (no overwrite)"
            if ($LASTEXITCODE -ne 0) {
                Write-Host "  Commit failed for additions from $src. Resolve and commit manually."
            } else {
                Write-Host "  Committed additions from $src."
            }
        } else {
            Write-Host "  No new files to add from $src."
        }
    }

    Write-Host "Finished processing target: $target"
}

Write-Host "`nAll done. Review each target branch and push when ready (e.g., git push origin main)."
