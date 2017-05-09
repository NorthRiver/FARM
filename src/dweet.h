
/** Recuperer le dernier dweet de la base en parametre
*@param nomDweet Nom du dweet a explorer
*@return Le dernier dweet sur la base
*/
char * getLastDweet(char * nomDweet);

/** Recuperer les dweets de la base en parametre
*@param nomDweet Nom du dweet a explorer
*@return Tous les dweets sur la base
*/
char * getDweet(char * nomDweet);


/** Poste un dweet vers la base en parametre avec les donnée en parametres
*@param nomDweet Nom du dweet a explorer
*@param data Une chaine de caractere des donnes a dweeter.
*/
void sendDweet(char * nomDweet, char * data);

/** Verifie si le dernier dweet est plus récent que la date passée en parametre
*@param nomDweet Nom du dweet a explorer
*@param dateDernierDweetLu La date qu'il faut dépasserc
*/
bool newDweet (char * nomDweet, char * dateDernierDweetLu);