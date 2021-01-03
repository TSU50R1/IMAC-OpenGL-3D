# IMAC-OpenGL-3D

IMACITY
===
Projet d'OpenGL IMAC 2 par Laurine Capdeville, Léa Rostoker et Daphné Chamot-Rooke

TUTO
=====

**PREREQUIS**

- cmake
- SDL, SDL2 (paquets ubuntu libsdl1.2-dev libsdl2-dev)
- ASSIMP (libassimp-dev)
- GLEW (paquets libglew-dev libglew glew-utils)
- GLFW3 (paquets libglfw3 libglfw3-dev libglfw3-doc)
- libconfini (voir plus bas)


**COMPILATION**

`IMAC-OpenGL-3D$ mkdir cmake-build-debug`

`IMAC-OpenGL-3D/cmake-build-debug$ cmake ..`

`IMAC-OpenGL-3D/cmake-build-debug$ make`

**EXECUTION** 

`IMAC-OpenGL-3D/cmake-build-debug$ cd ./bin`

`IMAC-OpenGL-3D/cmake-build-debug/bin$ ./Imacity`



**ASSIMP**

Pour pouvoir utiliser la bibliothèque assimp:  
créer un repertoire assimp `mkdir ~/assimp`

télécharger assimp (version 5.0.1 pour ce projet):

`cd ~/assimp`

`wget https://github.com/assimp/assimp/archive/v5.0.1.tar.gz`

untar dans `~/assimp` : `tar xvzf v5.0.1.tar.gz`

Dans `~/assimp/assimp-5.0.1` faire  

`mkdir build`  

`cd build`  

`cmake --prefix=./ .. -G 'Unix Makefiles'`  

`make`  

`make DESTDIR=~/assimp install` (met directement au bon endroit normalement)  

Pour une raison inconnue, l'option --prefix dans cmake n'est pas prise en compte ...
On fait ça manuellement :

`cd ~/assimp`

`mv usr/local/* .`


**LIBCONFINI**

Dans lib/confini:

`./configure --disable-doc  --disable-examples --includedir=$PWD/../../include --libdir=$PWD --docdir=$PWD/etc`

`make`

`make install`

OLD:
Pour le parsing de .ini  

Les binaires sont dans l'arborescence et si vous êtes sous linux, il n'y a normalement rien à faire de plus.

Si vous devez malgré tout recompiler :

dans `lib/confini`:

`./configure --libdir=$PWD/.. -includedir=$PWD/../../include --docdir=$PWD/tmp --disable-doc --disable-examples`

`make`

`make install`

Pour une installation système (pas une bonne idée, il faudrait faire le ménage de libconfini dans notre arborescence d'abord) :

Récupérer le zip ici : https://github.com/madmurphy/libconfini  

Installer libtool pour pouvoir compiler : `sudo apt-get install libtool-bin`  

faire : `./configure   `  

si ça ne marche pas : `./bootstrap` puis `./configure `  

puis : `make`  

et enfin : `make install-strip` et si ça ne marche pas  `sudo make install-strip`


**GLFW**

`sudo apt-get update`   

`sudo apt-get install libglfw3 libglfw3-dev`

