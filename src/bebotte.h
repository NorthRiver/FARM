#include "cJSON.h"

/** Recuperer les Bottes de la base en parametre
*@param nomBotte Nom du Botte a explorer
*@return Tous les Bottes sur la base
*/
char * getBotte(char * nomBotte);


/** Poste un Botte vers la base en parametre avec les donnée en parametres
*@param nomBotte Nom du Botte a explorer
*@param data Une chaine de caractere des donnes a Botteer.
*/
void sendBotte(char * nomBotte, char * data);



//Bon pour ce qui est au dessus c'est pas forcément nécessaire, mais voici les fonctions dont j'ai besoin :

//POST

/** @brief Envoi sur beetbotte des positions et informations sur la possesion du ballon par un robot
* @param ipRobot Chaine de caratere comportant l'ip du robot dont la positions est communiquée
* @param x Position en x entre 1 et 12
* @param y Poisition en y entre 1 et 8
* @param isVerified Vrai si la position est verifié par le serveur de position, false sinon
* @param possedeBallon Vrai si le joueur dit avoir un ballon, false sinon
* @param team 'r' si equipe rouge 'b' si bleu
*/
void postRobotPosition(char * ipRobot, int x, int y, bool isVerified, bool possedeBallon, char team);

/** @brief Poste le score actuel
* @param scoreRouge Entier correspondant au score actuel des rouges
* @param scoreBleu Entier correspondant au score actuel des bleus
*/
void postCurrentScore(int scoreRouge, int scoreBleu);

/** @brief Poste le temps restant en seconde avant la fin de partie
* @param tempsRestantEnSeconde le nob de seconde restante
*/
void postTempsRestant(int tempsRestantEnSeconde);

/** @brief Envoi si la partie est lancé ou non
* @param partieLancee Vrai si la partie a démarrée, faux sinon
*/
void postIsGameLaunch(bool partieLancee);


//GET

/** @brief Renvoi l'adresse IP des robots ayant marques des buts depuis le debut de la partie separe par des '/'
* @return Une liste d'ip
*/
char * getGoal();

/** @brief Renvoi vrai si le nb de robot passé en parametre se sont déclarés sur la partie
* @param nbRobot Le nombre de robot attendu dans la partie (default 6)
* @return True si ils sont tous la, faux sinon
*/
bool isThereAllTheRobots(int nbRobot);

/** @brief Retourne une chaine avec toutes les ips des robots de l'équipe rouge séparés par des '/'
* @return Une liste d'ip
*/
char * getRedTeam ();

/** @brief Retourne une chaine avec toutes les ips des robots de l'équipe bleu séparés par des '/'
* @return Une liste d'ip
*/
char * getBlueTeam ();
