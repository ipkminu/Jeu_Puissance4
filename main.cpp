#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

int nbre_noeuds=0;
int arret;
#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include <math.h>
#include "fonction.h"
#include "minimax.h"
#include "jeuNiveauFacile.h"
#include "AFFICHAGE.h"
#include "alphabeta.h"


int main ( int argc, char** argv )
{
    // initialize SDL video
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }

    atexit(SDL_Quit);
    SDL_Surface* screen = SDL_SetVideoMode(900, 700, 16,
                                           SDL_HWSURFACE|SDL_DOUBLEBUF);
    if ( !screen )
    {
        printf("Unable to set 640x480 video: %s\n", SDL_GetError());
        return 1;
    }
    //SDL_WM_SetIcon(IMG_Load("sdl_icone.png"), NULL);
    Position Tab[6][7];
   //jeu(Tab,screen);
    Menu(Tab,screen);


    return 0;
}
