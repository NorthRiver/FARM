#include "robot.h"

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