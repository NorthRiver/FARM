# Projet Polytech - Informatique & gestion 3 - FARM (FAR Monitoring)

Communication avec le serveur de but ainsi qu'avec les robots joueurs

- Tristan RIVIERE
- Clément LOUBIERE

Arborescence

data : Dossier où sont stockées les données
src : Dossier des fichier C et des entetes
obj	: Dossier des fichier compilés .o
bin : Dossier comportant l'executable du projet
doc : Dossier comportant la documentation
doc/html : Documentation doxygen (voir index.html)
monitoring : Serveur monitoring à déployer sur les robots joueurs

Dépendances
Installation des librairies : 
- libsdl2-dev 
- libsdl2-image-dev 
- libsdl2-ttf-dev 
- libsdl2-mixer-dev
- libsdl2-gfx-dev
- doxygen 

Compilation
make maj  - Va Mettre à jour le projet puis le compiler et enfin l'executer
make - compile le projet
make clean - Vide les objet et l'executable
make doxygen - Génère la documentation du projet
make start - Démarre le projet (Note : peut aussi être executé ainsi : ./bin/FARM.exe)
