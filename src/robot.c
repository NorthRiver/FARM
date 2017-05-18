#include "robot.h"
/**
* @struct Robot Contient toutes les infos des robots
* @param ip l'ip du robot
* @param posx La postion en X du robot
* @param posY la position en y du robot
* @param verifiedPosX La position verifiée du robot en X
* @param verifiedPosY la position verifiée du robot en Y
* @param ballon 1 si a le ballon, 0 sinon
*/
typedef struct RobotV
{
  char ip[10];
  int posX;
  int posY;
  int verifiedPosX;
  int verifiedPosY;
  int ballon;
} Robot;

int getPosX(Robot * r){
	return r.posX;
}

int getPosY(Robot * r){
	return r.posY;
}

int getVerifiedPosX(Robot * r){
	return r.verifiedPosX;
}

int getVerifiedPosY(Robot * r){
	return r.verifiedPosY;
}

int getBallon(Robot * r){
	return r.ballon;
}

char * getIp(Robot * r){
	return r.ip;
}

void setPosX(Robot * r, int val){
	r.posX = val;
}

void setPosY(Robot * r, int val){
	r.posY = val;
}

void setVerifiedPosX(Robot * r, int val){
	r.verifiedPosX = val;
}

void setVerifiedPosY(Robot * r, int val){
	r.verifiedPosX = val;
}

void setBallon(Robot * r, int val){
	r.ballon = val;
}

void setIp(Robot * r, char * nip){
	r.ip = nip;
}

int main(void){
	Robot r = malloc(sizeof(Robot));
	r.ip="162.38.11.96";
	return 0;
}

void majRobot(Robot * r[6]){
	int i=0;
	for(i; i<6; i++){
		//TODO Fonction socket sur r[i]
		/*    //décomposer les données en tokens
    char *tok = strtok(buffer, "/");
    printf("IDROBOT = %s\n", tok);
    char *idbut = tok;
    tok = strtok(NULL, "/");
    printf("IDBALLON = %s\n", tok);
    tok = strtok(NULL, "/");
    printf("COULBALLON = %s\n", tok);*/
	}
}