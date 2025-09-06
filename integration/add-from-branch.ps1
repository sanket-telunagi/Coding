param(
    [Parameter(Mandatory=$true, Position=0)]
    [string]$SourceBranch,
    [switch]$DryRun
)

Write-Host "Add-only: copying new files from branch '$SourceBranch' into 'main'"

# Ensure we have latest remote refs
& git fetch --all --prune

# Make sure main exists locally and is up-to-date
if (-not (& git show-ref --verify --quiet refs/heads/main)) {
    if (& git show-ref --verify --quiet refs/remotes/origin/main) {
        Write-Host "Creating local 'main' from 'origin/main'"
        & git checkout -B main origin/main
    } else {
        Write-Host "No main branch found; creating 'main' from current HEAD"
        & git checkout -B main
    }
} else {
    Write-Host "Checking out local 'main'"
    & git checkout main
    Write-Host "Pulling latest origin/main"
    & git pull origin main
}

# List files tracked in source branch
$filesRaw = & git ls-tree -r --name-only $SourceBranch 2>$null
if ($LASTEXITCODE -ne 0 -or -not $filesRaw) {
    Write-Host "Failed to list files for branch '$SourceBranch' or branch does not exist. Aborting."
    exit 1
}

$files = $filesRaw -split "`n" | Where-Object { $_ -and $_ -ne '.gitignore' }

$toAdd = @()
foreach ($f in $files) {
    $localPath = $f -replace '/', '\\'
    if (-not (Test-Path $localPath)) {
        $toAdd += $f
    }
}

if (-not $toAdd) {
    Write-Host "No new files to add from '$SourceBranch'."
    exit 0
}

Write-Host "Files to add from '$SourceBranch' (count: $($toAdd.Count)):`n"
$toAdd | ForEach-Object { Write-Host "  $_" }

if ($DryRun) {
    Write-Host "Dry run complete. No files were checked out or committed."
    exit 0
}

# Checkout each new file from the source branch and stage it
$addedAny = $false
foreach ($f in $toAdd) {
    Write-Host "Checking out: $f"
    & git checkout $SourceBranch -- "$f"
    if ($LASTEXITCODE -eq 0) {
        & git add -- "$f"
        $addedAny = $true
    } else {
        Write-Host "  Failed to checkout $f from $SourceBranch"
    }
}

if ($addedAny) {
    & git commit -m "Add files from $SourceBranch (no overwrite)"
    if ($LASTEXITCODE -ne 0) {
        Write-Host "Commit failed. Resolve issues and commit manually."
        exit 1
    }
    Write-Host "Pushing updated main to origin"
    & git push origin main
} else {
    Write-Host "No files were added/staged."
}

Write-Host "Done."
