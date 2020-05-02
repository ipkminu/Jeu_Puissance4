#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED


int Menu(Position Tab[6][7],SDL_Surface* screen);
int jouer_facile(SDL_Surface*);
int Aide(SDL_Surface*);
int parametres(SDL_Surface*);
void choix_niveau(Position Tab[6][7],SDL_Surface *screen);


int Menu(Position Tab[6][7],SDL_Surface *screen){
    SDL_Surface *fond=SDL_LoadBMP("fond.bmp");
    if(!fond){
        printf("\nERROR");
    }
    SDL_Surface *bouton_jouer=SDL_LoadBMP("bouton_jouer.bmp");
    if(!bouton_jouer){
        printf("\nERROR");
    }
    SDL_Surface *bouton_aide=SDL_LoadBMP("bouton_aide.bmp");
    if(!bouton_aide){
        printf("\nERROR");
    }
    SDL_Surface *bouton_parametres=SDL_LoadBMP("bouton_parametres.bmp");
    if(!bouton_parametres){
        printf("\nERROR");
    }
    SDL_SetColorKey(bouton_jouer, SDL_SRCCOLORKEY, SDL_MapRGB(bouton_jouer->format, 0, 0, 0));
    SDL_SetColorKey(bouton_aide, SDL_SRCCOLORKEY, SDL_MapRGB(bouton_aide->format, 0, 0, 0));
    SDL_SetColorKey(bouton_parametres, SDL_SRCCOLORKEY, SDL_MapRGB(bouton_parametres->format, 0, 0, 0));

    int continuer=0;
    SDL_Event event;
    SDL_Rect pos_fond,pos_jouer,pos_aide;
    SDL_Rect pos_parametres;
    pos_fond.x=0;
    pos_fond.y=0;
    pos_jouer.x=(screen->w-bouton_jouer->w)/2;
    pos_jouer.y=100;
    pos_aide.x=(screen->w-bouton_aide->w)/2;
    pos_aide.y=300;
    pos_parametres.x=(screen->w-bouton_parametres->w)/2;
    pos_parametres.y=500;
    while(continuer==0){
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_MOUSEBUTTONDOWN:
                    switch (event.button.button)
                    {
                    case SDL_BUTTON_LEFT:

                        if (event.button.x>=pos_jouer.x && event.button.x<=pos_jouer.x+609
                            && event.button.y>=100 && event.button.y<=268)
                        {

                            //continuer=1;
                            choix_niveau(Tab,screen);

                            //jeu(Tab,screen,1);
                        }
                        else if (event.button.x>=pos_aide.x && event.button.x<=pos_aide.x+609
                            && event.button.y>=(268+32) && event.button.y<=438)
                        {

                            //continuer=1;
                            Aide(screen);
                        }
                        else if (event.button.x>=pos_jouer.x && event.button.x<=pos_jouer.x+609
                            && event.button.y>=(438+32) && event.button.y<=638)
                        {

                            parametres(screen);
                        }



                        break;


                    }
                    break;
                case SDL_QUIT:
                    continuer =1;
                    break;

            }

        }


        SDL_BlitSurface(fond,0,screen,&pos_fond);
        SDL_BlitSurface(bouton_jouer,0,fond,&pos_jouer);
        SDL_BlitSurface(bouton_aide,0,fond,&pos_aide);
        SDL_BlitSurface(bouton_parametres,0,fond,&pos_parametres);
        SDL_Flip(screen);
    }
    SDL_WM_SetCaption("Jeu Puissance4", NULL);
    SDL_FreeSurface(fond);
    SDL_FreeSurface(bouton_jouer);
    SDL_FreeSurface(bouton_aide);
    SDL_FreeSurface(bouton_parametres);

    return 0;
}
int Aide(SDL_Surface *screen){
    SDL_Surface *fond=SDL_LoadBMP("fond.bmp");
    if(!fond){
        printf("\nError");
    }
    SDL_Surface *bouton_retour=SDL_LoadBMP("bouton_retour.bmp");
    if(!bouton_retour){
        printf("\nError");
    }
    SDL_SetColorKey(bouton_retour, SDL_SRCCOLORKEY, SDL_MapRGB(bouton_retour->format, 255, 255, 255));
    SDL_Surface *texte=SDL_LoadBMP("texte.bmp");
    if(!texte){
        printf("\nError");
    }
    SDL_SetColorKey(texte, SDL_SRCCOLORKEY, SDL_MapRGB(texte->format, 0, 0, 0));
    
    int continuer=0;
    SDL_Event event;
    SDL_Rect pos_bouton_retour,pos_fond,pos_texte;
    pos_fond.x=0;
    pos_fond.y=0;
    pos_bouton_retour.x=0;
    pos_bouton_retour.y=0;
    pos_texte.x=(fond->w-texte->w)/2;
    pos_texte.y=(fond->h-texte->h)/2;
    while(continuer==0){
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_MOUSEBUTTONDOWN:
                    switch(event.button.button){
                        case SDL_BUTTON_LEFT:
                            if (event.button.x>=0 && event.button.x<=92
                                && event.button.y>=0 && event.button.y <=105)
                            {

                                continuer=1;

                                continue;

                            }

                            break;

                    }
                    break;
                case SDL_QUIT:
                    continuer=1;
                    exit(EXIT_SUCCESS);
                    break;


            }

        }
        SDL_WM_SetCaption("Jeu Puissance4", NULL);
        SDL_BlitSurface(fond,0,screen,&pos_fond);
        SDL_BlitSurface(bouton_retour,0,fond,&pos_bouton_retour);
        SDL_BlitSurface(texte,0,fond,&pos_texte);
        SDL_Flip(screen);
    }





    SDL_WM_SetCaption("Jeu Puissance4", NULL);
    SDL_FreeSurface(fond);
    SDL_FreeSurface(bouton_retour);
    SDL_FreeSurface(texte);
    return 0;
}
int parametres(SDL_Surface *screen){
    SDL_Surface *fond =SDL_LoadBMP("fond.bmp");
    if(!fond){
        printf("\nError");
    }

    SDL_Surface *bouton_retour=SDL_LoadBMP("bouton_retour.bmp");
    if(!bouton_retour){
        printf("\nError");
    }
    SDL_SetColorKey(bouton_retour, SDL_SRCCOLORKEY, SDL_MapRGB(bouton_retour->format, 0, 0, 0));
    int continuer=0;
    SDL_Rect pos_bouton_retour,pos_fond;
    pos_fond.x=0;
    pos_fond.y=0;
    pos_bouton_retour.x=0;
    pos_bouton_retour.y=0;
    while(continuer==0){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            switch(event.type)
            {
            case SDL_MOUSEBUTTONDOWN:
                switch (event.button.button)
                {
                case SDL_BUTTON_LEFT:
                    if (event.button.x>=0 && event.button.x<=92
                        && event.button.y>=0 && event.button.y <=105)
                    {

                        continuer=1;
                        continue;

                    }

                    break;


                }
                break;
            case SDL_QUIT:
                continuer=1;
                exit(EXIT_SUCCESS);
                break;


            }


        }
        SDL_BlitSurface(fond,0,screen,&pos_fond);
        SDL_BlitSurface(bouton_retour,0,fond,&pos_bouton_retour);
        SDL_Flip(screen);
    }

    SDL_WM_SetCaption("Jeu Puissance4", NULL);
    SDL_FreeSurface(fond);
    SDL_FreeSurface(bouton_retour);
    return 0;
}



void choix_niveau(Position Tab[6][7],SDL_Surface *screen){

	    SDL_Surface *fond=SDL_LoadBMP("fond.bmp");
    if(!fond){
        printf("\nERROR");
    }
    SDL_Surface *bouton_jouer=SDL_LoadBMP("bouton_facile.bmp");
    if(!bouton_jouer){
        printf("\nERROR");
    }
    SDL_Surface *bouton_aide=SDL_LoadBMP("bouton_moyen.bmp");
    if(!bouton_aide){
        printf("\nERROR");
    }
    SDL_Surface *bouton_parametres=SDL_LoadBMP("bouton_difficile.bmp");
    if(!bouton_parametres){
        printf("\nERROR");
    }
    SDL_SetColorKey(bouton_jouer, SDL_SRCCOLORKEY, SDL_MapRGB(bouton_jouer->format, 0, 0, 0));
    SDL_SetColorKey(bouton_aide, SDL_SRCCOLORKEY, SDL_MapRGB(bouton_aide->format, 0, 0, 0));
    SDL_SetColorKey(bouton_parametres, SDL_SRCCOLORKEY, SDL_MapRGB(bouton_parametres->format, 0, 0, 0));
        SDL_Surface *bouton_retour=SDL_LoadBMP("bouton_retour.bmp");
    if(!bouton_retour){
        printf("\nError");
    }
    SDL_SetColorKey(bouton_retour, SDL_SRCCOLORKEY, SDL_MapRGB(bouton_retour->format, 0, 0, 0));

    int continuer=0;
    SDL_Event event;
    SDL_Rect pos_fond,pos_jouer,pos_aide,pos_bouton_retour;
    SDL_Rect pos_parametres;
    pos_fond.x=0;
    pos_fond.y=0;
    pos_jouer.x=(screen->w-bouton_jouer->w)/2;
    pos_jouer.y=100;
    pos_aide.x=(screen->w-bouton_aide->w)/2;
    pos_aide.y=300;
    pos_parametres.x=(screen->w-bouton_parametres->w)/2;
    pos_parametres.y=500;
    pos_bouton_retour.x=0;
    pos_bouton_retour.y=0;
    while(continuer==0){
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_MOUSEBUTTONDOWN:
                    switch (event.button.button)
                    {
                    case SDL_BUTTON_LEFT:

                        if (event.button.x>=pos_jouer.x && event.button.x<=pos_jouer.x+609
                            && event.button.y>=100 && event.button.y<=268)
                        {

                            //continuer=1;
                        	system("clear");
                            jeu(Tab,screen,1);
                        }
                        else if (event.button.x>=pos_aide.x && event.button.x<=pos_aide.x+609
                            && event.button.y>=(268+32) && event.button.y<=438)
                        {

                            //continuer=1;
                        	system("clear");
                            jeu(Tab,screen,2);
                        }
                        else if (event.button.x>=pos_jouer.x && event.button.x<=pos_jouer.x+609
                            && event.button.y>=(438+32) && event.button.y<=638)
                        {
                        	system("clear");
                            jeu(Tab,screen,3);
                        }
                        else if (event.button.x>=0 && event.button.x<=92
                            && event.button.y>=0 && event.button.y <=105)
                        {

                            continuer=1;


                        }




                        break;


                    }
                    break;
                case SDL_QUIT:
                    continuer =1;
                    exit(EXIT_SUCCESS);
                    break;

            }

        }


        SDL_BlitSurface(fond,0,screen,&pos_fond);
        SDL_BlitSurface(bouton_retour,0,fond,&pos_bouton_retour);
        SDL_BlitSurface(bouton_jouer,0,fond,&pos_jouer);
        SDL_BlitSurface(bouton_aide,0,fond,&pos_aide);
        SDL_BlitSurface(bouton_parametres,0,fond,&pos_parametres);
        SDL_Flip(screen);
    }
    SDL_WM_SetCaption("Jeu Puissance4", NULL);
    SDL_FreeSurface(fond);
    SDL_FreeSurface(bouton_jouer);
    SDL_FreeSurface(bouton_aide);
    SDL_FreeSurface(bouton_parametres);
    SDL_FreeSurface(bouton_retour);



}





























#endif // AFFICHAGE_H_INCLUDED
