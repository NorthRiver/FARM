
/** Recuperer le dernier Botte de la base en parametre
*@param nomBotte Nom du Botte a explorer
*@return Le dernier Botte sur la base
*/
char * getLastBotte(char * nomBotte);

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

/** Verifie si le dernier Botte est plus récent que la date passée en parametre
*@param nomBotte Nom du Botte a explorer
*@param dateDernierBotteLu La date qu'il faut dépasserc
*/
bool newBotte (char * nomBotte, char * dateDernierBotteLu);
