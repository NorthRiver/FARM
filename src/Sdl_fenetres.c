#include "Sdl_fenetres.h"


// ---- FONCTIONS ---- //

int menu() {
	// SDL_Surface* screenSurface;
	// SDL_Surface* texteAjout;
	// SDL_Surface* texteInv;
	// SDL_Rect pos;


	// // Fond d'écran
	// screenSurface = SDL_GetWindowSurface(getwindow());
	// SDL_Surface *fond_ecran = SDL_LoadBMP("data/images/fond_ecran.bmp");
	// SDL_Rect pos_fond_ecran;
	// pos_fond_ecran.x = 0; pos_fond_ecran.y = 0;
	// SDL_BlitSurface(fond_ecran,NULL,screenSurface,&pos_fond_ecran);

	// // Boutons menu
	// SDL_Rect buttEnreg; SDL_Rect buttInv;
	// buttEnreg.x=40; buttEnreg.y=40; buttEnreg.w=350; buttEnreg.h=400;
	// buttInv.x=400; buttInv.y=40; buttInv.w=350; buttInv.h=400;

	// SDL_FillRect(screenSurface,&buttEnreg,SDL_MapRGB(screenSurface->format,192, 57, 43));
	// SDL_FillRect(screenSurface,&buttInv,SDL_MapRGB(screenSurface->format,211, 84, 0));

	// // Texte boutons
	// SDL_Color couleurBlanc = {255, 255, 255};
	// texteAjout = TTF_RenderUTF8_Blended(getpolice(), "Ajout d'un aliment", couleurBlanc);
	// texteInv = TTF_RenderUTF8_Blended(getpolice(), "Mon stock", couleurBlanc);

	// int larg = texteAjout->w;
	// int haut = texteAjout->h;
	// pos.x=buttEnreg.x + ((buttEnreg.w-larg)/2); pos.y=buttEnreg.y + ((buttEnreg.h-haut)/2);

	// SDL_BlitSurface(texteAjout,NULL,screenSurface,&pos);

	// larg = texteInv->w;
	// haut = texteInv->h;
	// pos.x =buttInv.x + ((buttInv.w-larg)/2); pos.y=buttInv.y + ((buttInv.h-haut)/2);
	// SDL_BlitSurface(texteInv,NULL,screenSurface,&pos);

	// SDL_UpdateWindowSurface(getwindow());

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