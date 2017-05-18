#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "robot.h"

int main(void){
	Robot r;
	setIp(&r,"162.38.111.96");
	char * res;
	res = socketRecupRobot("162.38.111.96");

	return 0;
}