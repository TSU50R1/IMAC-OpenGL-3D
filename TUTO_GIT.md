# IMAC-OpenGL-3D

**GIT**

Pour clôner le projet : se déplacer dans le dossier de son choix dans une invite de commande puis taper 

`git clone https://github.com/TSU50R1/IMAC-OpenGL-3D.git`

**Pour ajouter des fichiers :**

`git add ./dossier/fichier`

`git commit -m "commentaire" `

`git push`


**Pour changer de branche :**

créer une branche `git branch Branche`

changer de branche `git checkout Branche`

**Pour ajouter des fichiers depuis un nouveau dossier**

se placer dans le dossier en question `git init`

`git remote add origin https://github.com/TSU50R1/IMAC-OpenGL-3D.git`

`git branch Branche`

`git add -A`

`git commit -m "commentaire"`

`git push --set-upstream origin Branche`

**Pour merge**

Se placer dans la branche où on veut merge `git merge Branche-a-merge`

Pour annuler `git merge --abort`

**Si on veut abandonner ses modifications locales avant de pull**

`git stash`


