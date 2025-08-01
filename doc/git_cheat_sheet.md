Profileinstellungen:
Check:
git config user.name
git config user.email
git config --global --list (gibt einen schönen Überblick)

Ändern:
git config --global user.name "user"
git config --global user.email "email"

Initialisierungsdateien haben normalerweise den Namen gitconfg.
Sie liegen im Userordner oder in der git-Installation unter etc.

Private Repositories brauchen einen Personal Access Tokens (PAT).
Private:
git clone https://token@github.com/account/repo.git
Public:
git clone https://github.com/account/repo.git

Git - Organisation:
Working Directory
Staging Area
Repository
Remote Branch

Cheat Sheet:
git --version;zum Schauen, ob git vom System gefunden wird
git clone;So kann man z.B. ein repo von GitHub holen.
git init;Lokales Repo erstellen - Man muss im Projekt - Arbeitsordner sein!
git commit -m "message";Verschieben von Dateien aus der Staging Area in das Repository
git status;1) Zur Klärung: Ist man in einem Repo, 2) Stand der Files in git
git log;Chronologische Auflistung aller commits aufrufen
git diff;
git remote -v;Nachschauen, was am Remote Branch anders ist
git remote add origin https://[url.git];lokales Repository auf remote branch kopieren
git remote rename <old> <new>;Umbenennen eines remote branches
git remote remove <name>;Löschen eines remote branches
git push;Kopieren der Änderungen vom lokalen Repository auf den Remote Branch
git push -u origin main[/master];Kopieren der Änderungen vom lokalen Repository auf den Remote Branch (explizite Form)
git pull;Kopieren der Änderungen vom Remote Branch auf das lokale Repository

STAGING
=======
git add;File(s) in die Staging Area befördern ("git add .": alle)
git add <file> - Stage a file
git add --all or git add -A - Stage all changes
git status - See what is staged
This will unstage all files you might have staged with git add:
git restore --staged <file> - Unstage a file
git reset
This will revert all local uncommitted changes (should be executed in repo root):

Unstage
=======
git reset HEAD -- <file>
or
git reset HEAD -- <directoryName>
Your modifications will be kept. When you run git status the file will once again show up as modified but not yet staged.

DATEIEN AUSNEHMEN
=================
Zu .gitignore hinzufügen ODER
z.B.: git update-index --assume-unchanged Asap2Toolset/MCDrms.dll

Damit werden Changes für die Datei nicht mehr angezeigt bis man den Effekt mit --no-assume-unchanged rückgängig macht.

TAGGING
=======
Das ist wie das Setzen eines Labels in PTC - nur für Commits!

git tag <tagname> - Create a lightweight tag
git tag -a <tagname> -m "message" - Create an annotated tag
git tag <tagname> <commit-hash> - Tag a specific commit
git tag - List tags
git show <tagname> - Show tag details

Push to Remote
==============
git push origin <tagname>
git push --tags

Delete Tags
===========
git tag -d <tagname>
git push origin --delete tag <tagname>

STASHING
========
git stash - Stash your changes
git stash push -m "message" - Stash with a message
git stash list - List all stashes
git stash branch <branchname> - Create a branch from a stash

Untracked files (new files not yet added to Git) are not stashed by default.
To stash untracked files too, use git stash -u (or --include-untracked).

BRANCHES
========
git branch -m master main // Branch von master nach main umbenennen

***

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

https://magna.sharepoint.com/:w:/r/teams/LAN-PRO-CHILI/TeamsChili/SCC%20Platform/Guidelines/Drafts/SCC%20Work%20Instruction%20-%20Development%20with%20gitlab.docx?d=wdb43973558974fddba473ecee786b6f4&csf=1&web=1&e=hbdpTX

Workshop, GitHub - 2025-02-26
=============================
Doc. im Sharepoint: https://magna.sharepoint.com/:f:/r/sites/GBL-EU-SWBB/Shared%20Documents/General/Work/GitHub%20Workshop?csf=1&web=1&e=5GDQ2f
Teams: SWBB Workshop

- Locking nicht verwenden!

https://cbea.ms/git-commit/

1. Separate subject from body with a blank line
2. Limit the subject line to 50 characters
3. Capitalize the subject line
4. Do not end the subject line with a period
5. Use the imperative mood in the subject line
6. Wrap the body at 72 characters
7. Use the body to explain what and why vs. how

https://education.github.com/git-cheat-sheet-education.pdf

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

GitLAB:
- Man brauch kein CP erstellen, wenn man mit einem Merge Request arbeitet. - Ein WI genügt.
- Wenn man weit vom Master entfernt ist, ist ein Pull-Request von Master/Origin in den aktuellen Branch erforderlich!
- Merge Request abschließen:
    - Reviewer muss auf Approved setzen!
    - CP muss geschlossen sein.
    - Jenkins please merge (in Kommentarfenster)
