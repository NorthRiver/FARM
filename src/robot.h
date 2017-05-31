#include <String.h>
#include "socket.h"

/**
* @struct Robot Contient toutes les infos des robots
* @param ip l'ip du robot
* @param posx La postion en X du robot
* @param posY la position en y du robot
* @param verifiedPosX La position verifiée du robot en X
* @param verifiedPosY la position verifiée du robot en Y
* @param ballon 1 si a le ballon, 0 sinon
*/
typedef struct RobotJ
{
  char ip[10];
  int posX;
  int posY;
  int verifiedPosX;
  int verifiedPosY;
  int ballon;
} Robot;

//GET

/** @brief Get/Set
* @param r Le robot
* @return La position en X du robot
*/
int getPosX(Robot * r);

/** @brief Get/Set
* @param r Le robot
* @return La position en Y du robot
*/
int getPosY(Robot * r);


/** @brief Get/Set
* @param r Le robot
* @return La position erifiee en X du robot
*/
int getVerifiedPosX(Robot * r);

/** @brief Get/Set
* @param r Le robot
* @return La position Verifiee en Y du robot
*/
int getVerifiedPosY(Robot * r);

/** @brief Get/Set
* @param r Le robot
* @return Si le robot a le ballon retourne 1, 0 sinon
*/
int getBallon(Robot * r);

/** @brief Get/Set
* @param r Le robot
* @return L'ip du Robot
*/
char * getIp(Robot * r);

//SET

/** @brief Get/Set
* @param r Le robot
* @param val Nouvelle valeur
*/
void setPosX(Robot * r, int val);

/** @brief Get/Set
* @param r Le robot
* @param val Nouvelle valeur
*/
void setPosY(Robot * r, int val);


/** @brief Get/Set
* @param r Le robot
* @param val Nouvelle valeur
*/
void setVerifiedPosX(Robot * r, int val);

/** @brief Get/Set
* @param r Le robot
* @param val Nouvelle valeur
*/
void setVerifiedPosY(Robot * r, int val);

/** @brief Get/Set
* @param r Le robot
* @param val Nouvelle valeur
*/
void setBallon(Robot * r, int val);

/** @brief Get/Set
* @param r Le robot
* @param nip Nouvelle ip
*/
void setIp(Robot * r, char * nip);

/**
* @brief Met a jour les données de chaques robots placés dans ce tableau de robots
* @param r Un tableau d'adresse de robots
*/
void majRobot(Robot * r[6]);
