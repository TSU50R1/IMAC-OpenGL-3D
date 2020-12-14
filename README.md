# IMAC-OpenGL-3D
Projet OpenGL IMAC2

Pour pouvoir utiliser la bibliothèque assimp:

telecharger assimp (version 5.0.1 pour ce projet)

untar dans `~/assimp`

Dans `~/assimp/assimp-5.0.1` faire
`mkdir build`
`cd build`
`cmake .. -G 'Unix Makefiles'`
`make`
`make DESTDIR=~/assimp install` (met directement au bon endroit normalement)
