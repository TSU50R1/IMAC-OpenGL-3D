# IMAC-OpenGL-3D
Projet OpenGL IMAC2

<<<<<<< HEAD

Pour clôner le projet : se déplacer dans le dossier de son choix dans une invite de commande puis taper 

````git clone https://github.com/TSU50R1/IMAC-OpenGL-3D.git```` 


Pour ajouter des fichiers :

````git add ./dossier/fichier````

````git commit -m "commentaire" ````

````git push````
=======
Pour pouvoir utiliser la bibliothèque assimp:  

telecharger assimp (version 5.0.1 pour ce projet)  

untar dans `~/assimp`  

Dans `~/assimp/assimp-5.0.1` faire  
`mkdir build`  
`cd build`  
`cmake .. -G 'Unix Makefiles'`  
`make`  
`make DESTDIR=~/assimp install` (met directement au bon endroit normalement)  
>>>>>>> origin/master
