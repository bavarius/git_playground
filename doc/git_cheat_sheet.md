# git Cheat Sheet

## Profile Settings
### Check:
git config user.name
git config user.email
git config --global --list // gives a good overview

### Change:
git config --global user.name "user"
git config --global user.email "email"

## Create Local Repository
git init

## Information
- git version
- git status
- git log // show history of all commits

## Staging
git add
git add <file>
git add . | git add --all | git add -A // Stage all changes

### unstage
git restore --staged <file> // Unstage a file
git reset // This will revert all local uncommitted changes (should be executed in repo root)
git reset HEAD --<file>
or
git reset HEAD --<directoryName>
Your modifications will be kept. When you run git status the file will once again show up as modified but not yet staged.

## Exclude Files/Folders from git
- add to .gitignore
- git update-index --assume-unchanged Asap2Toolset/MCDrms.dll
    This will suppress changes for the specified file until this is reverted by --no-assume-unchanged.

## Tagging
Set a label to a commit.

- git tag <tagname> - Create a lightweight tag
- git tag -a <tagname> -m "message" - Create an annotated tag
- git tag <tagname> <commit-hash> - Tag a specific commit
- git tag - List tags
- git show <tagname> - Show tag details

### Push to Remote
- git push origin <tagname>
- git push --tags

### Delete Tags
- git tag -d <tagname>
- git push origin --delete tag <tagname>

## Stashing
- git stash // Stash your changes
- git stash push -m "message" - Stash with a message
- git stash list // List all stashes
- git stash branch <branchname> // Create a branch from a stash

Untracked files (new files not yet added to Git) are not stashed by default.
To stash untracked files too, use git stash -u (or --include-untracked).

## Branches
- git branch -m master main // Rename master to main

## Commit
### Conventions
https://cbea.ms/git-commit/

1. Separate subject from body with a blank line
2. Limit the subject line to 50 characters
3. Capitalize the subject line
4. Do not end the subject line with a period
5. Use the imperative mood in the subject line
6. Wrap the body at 72 characters
7. Use the body to explain what and why vs. how

***

Cheat Sheet:
git commit -m "message";Verschieben von Dateien aus der Staging Area in das Repository
git diff;
git remote -v;Nachschauen, was am Remote Branch anders ist
git remote add origin https://[url.git];lokales Repository auf remote branch kopieren
git remote rename <old> <new>;Umbenennen eines remote branches
git remote remove <name>;Löschen eines remote branches
git push;Kopieren der Änderungen vom lokalen Repository auf den Remote Branch
git push -u origin main[/master];Kopieren der Änderungen vom lokalen Repository auf den Remote Branch (explizite Form)
git pull;Kopieren der Änderungen vom Remote Branch auf das lokale Repository

git checkout .
You can also revert uncommitted changes only to particular file or directory:

git checkout [some_dir|file.txt]
Yet another way to revert all uncommitted changes (longer to type, but works from any subdirectory):

git reset --hard HEAD
This will remove all local untracked files, so only git tracked files remain:

git clean -fdx
WARNING: -x will also remove all ignored files, including ones specified by .gitignore! You may want to use -n for preview of files to be deleted.

To sum it up: executing commands below is basically equivalent to fresh git clone from original source (but it does not re-download anything, so is much faster):

git reset
git checkout .
git clean -fdx
Typical usage for this would be in build scripts, when you must make sure that your tree is absolutely clean - does not have any modifications or locally created object files or build artefacts, and you want to make it work very fast and to not re-clone whole repository every single time.

Um alle Dateien auf den letzten Commit-Stand eines Branches zu setzen, kannst du den folgenden Git-Befehl verwenden:

git reset --hard HEAD
Dieser Befehl setzt das Arbeitsverzeichnis und den Index auf den Zustand des letzten Commits zurück. Wenn du einen bestimmten Branch auf den letzten Commit-Stand setzen möchtest, kannst du zuerst zu diesem Branch wechseln und dann den obigen Befehl ausführen:

git checkout <branch-name>
git reset --hard HEAD
Falls du den Branch auf den Zustand eines bestimmten Commits zurücksetzen möchtest, kannst du den Commit-Hash angeben:

git reset --hard <commit-hash>
Bitte beachte, dass der --hard Parameter alle nicht gespeicherten Änderungen in deinem Arbeitsverzeichnis entfernt. Stelle sicher, dass du alle wichtigen Änderungen gesichert hast, bevor du diesen Befehl ausführst.

Zurück auf HEAD:
git checkout master
danach:
git pull

***

## GitLab - MPT-specific
- No need to create a change package (CP) when creating a Merge Request in GitLab! It's enough to have a work item (WI).

### Branching Strategy
- There shall be a branch for every feature or bugfix.
- Change shall be periodically pulled from master.
- Rebasing shall be done from master to the feature branch. Merge will be done by git2PTC-script.

### Merge Requests
- In order to close a Merge Request the reviewer has to set it to "Approved".
- There must not be any open CP attached to the corresponding WI.
- Jenkins please merge (into comment field)

## Links
- https://education.github.com/git-cheat-sheet-education.pdf
