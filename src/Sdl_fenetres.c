#include "Sdl_fenetres.h"
#include "partie.h"


// ---- FONCTIONS ---- //

int loading(){
    SDL_Surface *screenSurface;
    SDL_Surface *textMap;
    SDL_Rect pos;

    // Fond d'écran
    screenSurface = SDL_GetWindowSurface(getwindow());
    SDL_Surface *fond_ecran = SDL_LoadBMP("data/images/fond_ecran.bmp");
    SDL_Rect pos_fond_ecran;

    pos_fond_ecran.x = 0; pos_fond_ecran.y = 0;
    SDL_BlitSurface(fond_ecran, NULL, screenSurface, &pos_fond_ecran);
    // Texte
    SDL_Color couleurBlanc = { 255, 255, 255 };
    textMap = TTF_RenderUTF8_Blended(getpolice(), "En attente de joueurs", couleurBlanc);

    int larg = textMap->w;
    pos.x = pos_fond_ecran.x + ((pos_fond_ecran.w - larg) / 2); pos.y = pos_fond_ecran.y - 35;
    SDL_BlitSurface(textMap, NULL, screenSurface, &pos);

//Placement des cases

    SDL_Event event;
    int loop = 1;
    bool allRobot = 0;
    while (loop == 1 && !allRobot) {
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
        allRobot = isThereAllTheRobots(NBJ * 2);
    }
    return 2; //On avance le programme
}

int partie(){
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
    SDL_Rect cadreGrille;
    cadreGrille.x = 75; cadreGrille.y = 75; cadreGrille.w = 375; cadreGrille.h = 250;

    SDL_FillRect(screenSurface, &cadreGrille, SDL_MapRGB(screenSurface->format, 10, 0, 0));

    // Texte
    SDL_Color couleurBlanc = { 255, 255, 255 };
    textMap = TTF_RenderUTF8_Blended(getpolice(), "Map", couleurBlanc);

    int larg = textMap->w;
    pos.x = cadreGrille.x + ((cadreGrille.w - larg) / 2); pos.y = cadreGrille.y - 35;
    SDL_BlitSurface(textMap, NULL, screenSurface, &pos);

    textScore = TTF_RenderUTF8_Blended(getpolice(), "Score", couleurBlanc);

    larg = textMap->w;
    pos.x = pos.x + 370; pos.y = pos.y + 30;
    SDL_BlitSurface(textScore, NULL, screenSurface, &pos);

    textTime = TTF_RenderUTF8_Blended(getpolice(), "Time", couleurBlanc);

    larg = textMap->w;
    pos.y = pos.y + 180;
    SDL_BlitSurface(textTime, NULL, screenSurface, &pos);

//Placement des cases
    SDL_Rect cases;

    cases.x = 0; cases.y = 0; cases.w = 30; cases.h = 30;

    int i, j;
    for (i = 0; i < 12; i++) {
        cases.x = i * 31 + 77;
        for (j = 0; j < 8; j++) {
            cases.y = j * 31 + 77;
            SDL_FillRect(screenSurface, &cases, SDL_MapRGB(screenSurface->format, 50, 23, 71));
        }
    }

    SDL_UpdateWindowSurface(getwindow());

//On initialise la partie et les robots

    Partie * laPartie = malloc(sizeof(Partie));
    setScoreBleu(laPartie, 0);
    setScoreRouge(laPartie, 0);
    setTemps(laPartie, 900); //15min
    char * redTeamRaw = getRedTeam();
    char * blueTeamRaw = getBlueTeam();
    char *tok = strtok(redTeamRaw, "/");
    char *tok2 = strtok(blueTeamRaw, "/");
    Robot * r = malloc(sizeof(Robot));
    setPosY(r, 0);
    setPosX(r, 0);
    setVerifiedPosY(r, 0);
    setVerifiedPosX(r, 0);
    setBallon(r, 0);
    setIp(r, tok);
    pushRobotRouge(laPartie, r);
    tok = strtok(NULL, "/");
    setIp(r, tok);
    pushRobotRouge(laPartie, r);
    tok = strtok(NULL, "/");
    setIp(r, tok);
    pushRobotRouge(laPartie, r);

    setIp(r, tok2);
    pushRobotBleu(laPartie, r);
    tok2 = strtok(NULL, "/");
    setIp(r, tok2);
    pushRobotBleu(laPartie, r);
    tok2 = strtok(NULL, "/");
    setIp(r, tok2);
    pushRobotBleu(laPartie, r);
// On est pret, on lance la partie
    isGameLaunch(1);
    clock_t temps;

    SDL_Event event;
    int loop = 1;
    while (loop == 1) {// boucle du programme
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

        //On demande leur position aux robots
        int k = 0;
        for (k = 0; k < NBJ; k++) {
            //On met le robot rouge a jour
            char * res; Robot ** rbj = getRobotRouge(laPartie);
            res = socketRecupRobot(getIp(rbj [k]));

            // char *tok = strtok(res, "/");
            // printf("ipRobot = %s\n", tok);
            // char *ipR = tok;
            //
            // tok = strtok(NULL, "/");
            // char *posR = tok;
            // printf("position = %s\n", tok);
            // char * tokp = strtok(posR, "_");
            // //To do : passage du decoupage en int pour les fonction plus basses
            // tok = strtok(NULL, "/");
            // char *vPosR = tok;
            // printf("positions verifiées = %s\n", tok);

            // setPosX(rbj [k], px);
            // setPosX(rbj [k], py);
            // setPosX(rbj [k], pvx);
            // setPosX(rbj [k], pvy);
            // setBallon(rbj [k], b);
            //To do dupliquer pour les bleux
        }
        // on met a jour le score :
        setScoreBleu(laPartie, getScoreBleu(laPartie) + newGoal('b'));
        setScoreRouge(laPartie, getScoreRouge(laPartie) + newGoal('r'));
        postCurrentScore(getScoreRouge(laPartie), getScoreBleu(laPartie));
        //On met a jour le temps
        setTemps(laPartie, ((int)getTemps(laPartie) - (int)(temps / CLOCKS_PER_SEC)));
        if (getTemps(laPartie) < 0) {
            //Partie finie, on le publie et on quite le programme
            isGameLaunch(0);
            return 0;
        }
    }

    printf("\nErreur, sortie de boucle non-désirée (fonction menu())");
    return -1;
}
