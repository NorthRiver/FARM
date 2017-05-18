#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "robot.h"

int main(void){
	Robot r;
	setIp(&r,"162.38.111.96");
	char * res;
	res = socketRecupRobot("162.38.111.96");

	char *tok = strtok(res, "/");
    printf("ipRobot = %s\n", tok);
    char *ipR = tok;

    tok = strtok(NULL, "/");
    char *posR = tok;
    printf("position = %s\n", tok);
    
    tok = strtok(NULL, "/");
    char *vPosR = tok;
    printf("positions verifiées = %s\n", tok);

	return 0;
}