#include "Sdl_main.h"

int main(int argc,char* args[]) {

	int loop = 1;

	init();

	while(loop==1){

		loop = menu();

	}

	cleanup();

	return 0;
}
