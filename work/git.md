- git diff branches
`git diff --name-status master ch`
- git diff file
`git difftool --tool=vimdiff README.md`
- git diff file between branches
`git diff master:README.md ch:README.md`
- git pull vs git rebase:
  - The git pull command downloads the latest version history of files from the remote repository to the local repository, but this command also performs a merge operation and updates the content of your working directory
  - The git rebase command takes all the changes from a branch and applies them to the current branch. This is a process called patching

