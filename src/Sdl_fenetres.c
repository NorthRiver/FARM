#include "Sdl_fenetres.h"


// ---- FONCTIONS ---- //

int menu() {
	SDL_Surface* screenSurface;
	SDL_Surface* texteAjout;
	SDL_Rect pos;

	// Fond d'écran
	screenSurface = SDL_GetWindowSurface(getwindow());
	SDL_Surface *fond_ecran = SDL_LoadBMP("data/images/fond_ecran.bmp");
	SDL_Rect pos_fond_ecran;
	pos_fond_ecran.x = 0; pos_fond_ecran.y = 0;
	SDL_BlitSurface(fond_ecran,NULL,screenSurface,&pos_fond_ecran);

	// Cadre grille
	SDL_Rect cadreGrille; SDL_Rect buttInv;
	cadreGrille.x=40; cadreGrille.y=40; cadreGrille.w=400; cadreGrille.h=400;

	SDL_FillRect(screenSurface,&cadreGrille,SDL_MapRGB(screenSurface->format,49, 36, 104));

	// Texte boutons
	SDL_Color couleurBlanc = {255, 255, 255};
	texteAjout = TTF_RenderUTF8_Blended(getpolice(), "Map", couleurBlanc);

	int larg = texteAjout->w;
	int haut = texteAjout->h;
	pos.x=cadreGrille.x + ((cadreGrille.w-larg)/2); pos.y=cadreGrille.y + ((cadreGrille.h-haut)/2);

	SDL_BlitSurface(texteAjout,NULL,screenSurface,&pos);


	SDL_UpdateWindowSurface(getwindow());

	SDL_Event event;
	int loop = 1;
	while(loop == 1) {
		int x = -1; int y = -1;

	    SDL_WaitEvent(&event);
	    switch(event.type)
	    {
	        case SDL_KEYDOWN:
	            switch(event.key.keysym.sym)
	            {
	            	case SDLK_ESCAPE:
	                    loop= 0;
	                    return 0;
	                    break;
	                }
	                break;
	    }


	} // end while event

	printf("\nErreur, sortie de boucle non-désirée (fonction menu())");
	return -1;
} // end fontion menu()
