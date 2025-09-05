# Save this as .\integration\merge-preserve-gitignore.ps1 and run from repo root
& git fetch --all --prune

# This script will add files from all local branches into main without deleting or overwriting
# existing files on main. It skips .gitignore. It commits per-branch additions.

# Ensure we are on main (create from origin/main if needed)
& git show-ref --verify --quiet refs/heads/main
if ($LASTEXITCODE -ne 0) {
  # try to create local main from origin/main
  & git show-ref --verify --quiet refs/remotes/origin/main
  if ($LASTEXITCODE -eq 0) {
    Write-Host "Creating local 'main' from 'origin/main'"
    & git checkout -B main origin/main
  } else {
    Write-Host "No local or remote 'main' found. Creating new 'main' from current HEAD"
    & git checkout -B main
  }
} else {
  Write-Host "Checking out existing 'main'"
  & git checkout main
}

# get list of local branches, excluding main
$branches = (& git for-each-ref --format='%(refname:short)' refs/heads/) -split "`n" | Where-Object { $_ -and $_ -ne 'main' }

if (-not $branches) {
  Write-Host "No local branches found to add from. Exiting."
  return
}

foreach ($b in $branches) {
  Write-Host "`n=== Processing branch: $b ==="

  # Get list of files tracked in branch $b
  $filesRaw = & git ls-tree -r --name-only $b
  if ($LASTEXITCODE -ne 0) {
    Write-Host "Failed to list files for branch $b. Skipping."
    continue
  }
  $files = $filesRaw -split "`n" | Where-Object { $_ -and $_ -ne '.gitignore' }

  $addedAny = $false
  foreach ($file in $files) {
    # skip directories (ls-tree returns files only) and skip if file already exists in working tree
    if (-not $file) { continue }
    # Normalize path for Test-Path
    $path = $file -replace '/', '\'
    if (-not (Test-Path $path)) {
      Write-Host "Adding new file: $file from branch $b"
      & git checkout $b -- $file
      if ($LASTEXITCODE -ne 0) {
        Write-Host "  Failed to checkout $file from $b."
        continue
      }
      & git add $file
      $addedAny = $true
    } else {
      Write-Host "Skipping existing file: $file (already in main)"
    }
  }

  if ($addedAny) {
    & git commit -m "Add files from branch '$b' (no overwrites)"
    if ($LASTEXITCODE -ne 0) {
      Write-Host "Failed to commit additions from $b. You may need to commit manually."
    } else {
      Write-Host "Committed additions from $b."
    }
  } else {
    Write-Host "No new files to add from $b."
  }
}

Write-Host "`nDone. All branches processed. Review 'main' and push when ready: git push origin main" 