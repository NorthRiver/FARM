#include "Sdl_main.h"

int main(int argc, char* args[]) {
    int menuSelect = 1;

    init();



    while (menuSelect != 0) {
        if (menuSelect == 1) {
            menuSelect = loading();
        }
        else if (menuSelect == 2) {
            menuSelect = partie();
        }
    }

    cleanup();

    return 0;
}
