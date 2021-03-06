#include "Sdl_fenetres.h"



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
    int allRobot = 0;
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
        allRobot = isThereAllRobots(NBJ * 2);
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
    printf("\nStructure de partie crée [\033[32mOK]\033[0m]\n");
    setScoreBleu(laPartie, 0);
    printf("Initialisation des score à 0 [\033[32mOK]\033[0m]\n");
    setScoreRouge(laPartie, 0);
    setnbRobotRouge(laPartie, 0);
    setnbRobotBleu(laPartie, 0);
    setTemps(laPartie, 300); //5min
    printf("Initilisation du temps à 5 min [\033[32mOK]\033[0m]\n");
    char * redTeamRaw = getRedTeam();
    char * blueTeamRaw = getBlueTeam();
    printf("[\033[33mDEBUG\033[0m] RedTeam %s\n", redTeamRaw);
    printf("[\033[33mDEBUG\033[0m] BlueTeam %s\n", blueTeamRaw);
    char *tok = strtok(redTeamRaw, "/");
    char * pos1r = strtok(NULL, "/");
    char * pos2r = strtok(NULL, "/");
    char *tok2 = strtok(blueTeamRaw, "/");
    char * pos1b = strtok(NULL, "/");
    char * pos2b = strtok(NULL, "/");
    Robot * r1 = malloc(sizeof(Robot)); Robot * r2 = malloc(sizeof(Robot)); Robot * r3 = malloc(sizeof(Robot)); Robot * r4 = malloc(sizeof(Robot)); Robot * r5 = malloc(sizeof(Robot)); Robot * r6 = malloc(sizeof(Robot));

    setPosY(r1, 0);
    setPosX(r1, 0);
    setVerifiedPosY(r1, 0);
    setVerifiedPosX(r1, 0);
    setBallon(r1, 0);

    setPosY(r2, 0);
    setPosX(r2, 0);
    setVerifiedPosY(r2, 0);
    setVerifiedPosX(r2, 0);
    setBallon(r2, 0);

    setPosY(r3, 0);
    setPosX(r3, 0);
    setVerifiedPosY(r3, 0);
    setVerifiedPosX(r3, 0);
    setBallon(r3, 0);

    setPosY(r4, 0);
    setPosX(r4, 0);
    setVerifiedPosY(r4, 0);
    setVerifiedPosX(r4, 0);
    setBallon(r4, 0);

    setPosY(r5, 0);
    setPosX(r5, 0);
    setVerifiedPosY(r5, 0);
    setVerifiedPosX(r5, 0);
    setBallon(r5, 0);

    setPosY(r6, 0);
    setPosX(r6, 0);
    setVerifiedPosY(r6, 0);
    setVerifiedPosX(r6, 0);
    setBallon(r6, 0);
    setIp(r1, tok);

    pushRobotRouge(laPartie, r1);

    setIp(r2, pos1r);
    pushRobotRouge(laPartie, r2);
    setIp(r3, pos2r);
    pushRobotRouge(laPartie, r3);
    setIp(r4, tok2);
    pushRobotBleu(laPartie, r4);
    setIp(r5, pos1b);
    pushRobotBleu(laPartie, r5);
    printf("%s", getIp(r2));
    setIp(r6, pos2b);
    pushRobotBleu(laPartie, r6);
// On est pret, on lance la partie
    postIsGameLaunch(1);
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
            char * res; Robot ** rbj = malloc(sizeof(Robot*) * 3);
            rbj = getRobotRouge(laPartie);
            printf("[\033[33mDEBUG\033[0m] Demande d'acces au robot %s \n", getIp(rbj [k]));

            res = socketRecupRobot(getIp(rbj [k]));
            char *ip = strtok(res, "/");
            char * pos1a = strtok(NULL, "/");
            char * pos1b = strtok(NULL, "/");

            char * tokp = strtok(pos1a, "_");
            int px = atoi(tokp);
            tokp = strtok(NULL, "_");
            int py = atoi(tokp);

            tokp = strtok(NULL, "_");
            int b = atoi(tokp);
            char *vPosR = strtok(pos1b, "_");

            int pvx = atoi(vPosR);

            vPosR = strtok(NULL, "_");
            int pvy = atoi(vPosR);

            setPosX(rbj [k], px);
            setPosY(rbj [k], py);
            setVerifiedPosX(rbj [k], pvx);
            setVerifiedPosY(rbj [k], pvy);

            setBallon(rbj [k], b);
            printf("\nMise à jour des robots rouges [\033[32mOK]\033[0m]\n");

            char * res2; Robot ** rbj2 = getRobotBleu(laPartie);
            res2 = socketRecupRobot(getIp(rbj2 [k]));
            char *ip2 = strtok(res2, "/");
            char * pos1a2 = strtok(NULL, "/");
            char * pos1b2 = strtok(NULL, "/");

            char * tokp2 = strtok(pos1a2, "_");
            int px2 = atoi(tokp2);
            tokp2 = strtok(NULL, "_");
            int py2 = atoi(tokp2);
            tokp2 = strtok(NULL, "_");
            int b2 = atoi(tokp2);

            char *vPosR2 = strtok(pos1b2, "_");
            int pvx2 = atoi(vPosR2);
            vPosR2 = strtok(NULL, "_");
            int pvy2 = atoi(vPosR2);

            setPosX(rbj2 [k], px2);
            setPosY(rbj2 [k], py2);
            setVerifiedPosX(rbj2 [k], pvx2);
            setVerifiedPosY(rbj2 [k], pvy2);
            setBallon(rbj2 [k], b2);
            printf("\nMise à jour des robots bleu [\033[32mOK]\033[0m]\n");
        }
        // on met a jour le score :
        //setScoreBleu(laPartie, getScoreBleu(laPartie) + newGoal('b'));
        //setScoreRouge(laPartie, getScoreRouge(laPartie) + newGoal('r'));
        postCurrentScore(getScoreRouge(laPartie), getScoreBleu(laPartie));
        //On met a jour le temps
        setTemps(laPartie, ((int)getTemps(laPartie) - (int)(temps / CLOCKS_PER_SEC)));
        if (getTemps(laPartie) < 0) {
            //Partie finie, on le publie et on quite le programme
            postIsGameLaunch(0);
            return 0;
        }
    }

    printf("\nErreur, sortie de boucle non-désirée (fonction menu())");
    return -1;
}
