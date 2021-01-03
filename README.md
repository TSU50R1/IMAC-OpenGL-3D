# IMAC-OpenGL-3D

IMACITY
===
Projet d'OpenGL IMAC 2 par Laurine Capdeville, Léa Rostoker et Daphné Chamot-Rooke

TUTO
=====

**PREREQUIS**

- cmake
- SDL, SDL2
- ASSIMP
- GLEW
- GLFW3
- libconfini

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


**COMPILATION**


`IMAC-OpenGL-3D/cmake-build-debug$ cmake ..`

`IMAC-OpenGL-3D/cmake-build-debug$ make`

`IMAC-OpenGL-3D/cmake-build-debug$ cd ./bin`

`IMAC-OpenGL-3D/cmake-build-debug/bin$ ./Imacity`



**ASSIMP**

Pour pouvoir utiliser la bibliothèque assimp:  

telecharger assimp (version 5.0.1 pour ce projet)  

untar dans `~/assimp`  

Dans `~/assimp/assimp-5.0.1` faire  
`mkdir build`  
`cd build`  
`cmake .. -G 'Unix Makefiles'`  
`make`  
`make DESTDIR=~/assimp install` (met directement au bon endroit normalement)  


**LIBCONFINI**

Pour le parsing de .ini  
Récupérer le zip ici : https://github.com/madmurphy/libconfini  
Installer libtool pour pouvoir compiler : `sudo apt-get install libtool-bin`  
faire : `./configure   `  
si ça ne marche pas : `./bootstrap` puis `./configure `  
puis : `make`  
et enfin : `make install-strip` et si ça ne marche pas  `sudo make install-strip`



