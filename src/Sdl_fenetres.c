#include "Sdl_fenetres.h"


// ---- FONCTIONS ---- //


int menu(){
    SDL_Surface *screenSurface;
    SDL_Surface *textMap;
    SDL_Surface *textScore;
    SDL_Surface *textTime;
    SDL_Rect pos;

    // Fond d'écran
    screenSurface = SDL_GetWindowSurface(getwindow());
    SDL_Surface *fond_ecran = SDL_LoadBMP("data/images/fond_ecran.bmp");
    SDL_Rect pos_fond_ecran;
    pos_fond_ecran.x = 0; pos_fond_ecran.y = 0;
    SDL_BlitSurface(fond_ecran, NULL, screenSurface, &pos_fond_ecran);
    // Cadre grille
    SDL_Rect cadreGrille; SDL_Rect buttInv;
    cadreGrille.x = 75; cadreGrille.y = 40; cadreGrille.w = 375; cadreGrille.h = 250;

    SDL_FillRect(screenSurface, &cadreGrille, SDL_MapRGB(screenSurface->format, 32, 23, 71));

    // Texte
    SDL_Color couleurBlanc = { 255, 255, 255 };
    textMap = TTF_RenderUTF8_Blended(getpolice(), "Map", couleurBlanc);

    int larg = textMap->w;
    int haut = textMap->h;
    pos.x = cadreGrille.x + ((cadreGrille.w - larg) / 2); pos.y = cadreGrille.y + 5;
    SDL_BlitSurface(textMap, NULL, screenSurface, &pos);

    textScore = TTF_RenderUTF8_Blended(getpolice(), "Score", couleurBlanc);

    larg = textMap->w;
    haut = textMap->h;
    pos.x = pos.x + 370; pos.y = pos.y + 30;
    SDL_BlitSurface(textScore, NULL, screenSurface, &pos);

    textTime = TTF_RenderUTF8_Blended(getpolice(), "Time", couleurBlanc);

    larg = textMap->w;
    haut = textMap->h;
    pos.y = pos.y + 180;
    SDL_BlitSurface(textTime, NULL, screenSurface, &pos);

//Placement des cases
    SDL_Rect cases;
    cases.x = 0; cases.y = 0; cases.w = 30; cases.h = 30;

    int i, j;
    for (i = 0; i < 12; i++) {
        cases.x = i * 30 + 15;
        for (j = 0; j < 8; j++) {
            cases.y = j * 30 + 15;
            SDL_FillRect(screenSurface, &cases, SDL_MapRGB(screenSurface->format, 10, 23, 71));
        }
    }

    SDL_UpdateWindowSurface(getwindow());

    SDL_Event event;
    int loop = 1;
    while (loop == 1) {
        SDL_WaitEvent(&event);
        switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
            case SDLK_ESCAPE:
                loop = 0;
                return 0;
                break;
            }
            break;
        }
    } // end while event

    printf("\nErreur, sortie de boucle non-désirée (fonction menu())");
    return -1;
} // end fontion menu()
