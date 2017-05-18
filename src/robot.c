#include "robot.h"

int getPosX(Robot * r){
	return r->posX;
}

int getPosY(Robot * r){
	return r->posY;
}

int getVerifiedPosX(Robot * r){
	return r->verifiedPosX;
}

int getVerifiedPosY(Robot * r){
	return r->verifiedPosY;
}

int getBallon(Robot * r){
	return r->ballon;
}

char * getIp(Robot * r){
	return r->ip;
}

void setPosX(Robot * r, int val){
	r->posX = val;
}

void setPosY(Robot * r, int val){
	r->posY = val;
}

void setVerifiedPosX(Robot * r, int val){
	r->verifiedPosX = val;
}

void setVerifiedPosY(Robot * r, int val){
	r->verifiedPosX = val;
}

void setBallon(Robot * r, int val){
	r->ballon = val;
}

void setIp(Robot * r, char * nip){
	r->ip = nip;
}

int main(void){
	Robot r;
	&r->ip="162.38.111.96";
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