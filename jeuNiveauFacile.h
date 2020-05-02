/*
 * jeuNiveauFacile.h
 *
 *  Created on: 4 avr. 2020
 *      Author: razing
 */

#ifndef JEUNIVEAUFACILE_H_
#define JEUNIVEAUFACILE_H_

int placer_pion_m3(Position Tab[6][7],int joueur);


int placer_pion_m1(Position Tab[6][7],int joueur){

	int j=0,i=0;
	char couleur[2];
	couleur[0]='R';
	couleur[1]='B';
	int Etat[2]={1,2};
	srand(time(NULL));
	while(i==0){

		int c=rand()%7+1;
		c=c-1;   //c=fnctionAI(Tab,couleur);
		j=0;
		while(j<6){
			if(Tab[j][c].color=='N'){
			Tab[j][c].color = couleur[joueur-1];
			Tab[j][c].etat = Etat[joueur-1];
				return 0;

			}
			else {j++;}

		}

	}
	return 1;

}
int placer_pion_m2(Position Tab[6][7],int joueur){

	int j=0;
	char couleur[2];
	couleur[0]='R';
	couleur[1]='B';
	int Etat[2]={1,2};

		int c=choix_colonne_minimax(Tab,joueur)-1;
		//printf("\n******La colonne choisie est: %i",c);
		//getchar();
		j=0;
		while(j<6){
			if(Tab[j][c].color=='N'){
			Tab[j][c].color = couleur[joueur-1];
			Tab[j][c].etat = Etat[joueur-1];
				return 0;
			}
			else {j++;}

		}

	return 1;

}

typedef struct pions{
    SDL_Rect pos;
}Pions;

void jeu(Position Tab[6][7],SDL_Surface* screen,int niveau){
    /********************Definition des variables d'usage****/
    int i,j;
    int continuer=0,tour;
    int n=0,joueur,premier,jaid;
    int compt_h=0,compt_m=0;
	char c;
	int success=0;
	///CHargement des elements SDL
    SDL_Event event;
    Pions gril[6][7]; ///Il faudra initialiser les coordonnées associée a la grille en pîxel
    SDL_Rect pos_grille;
    SDL_Surface *pion_jaune=SDL_LoadBMP("pion_jaune.bmp");
    for(i=0;i<6;i++){
        for(j=0;j<7;j++){
            if(i==0){gril[i][j].pos.y=636;}
            if(i==1){gril[i][j].pos.y=636-i*(pion_jaune->h+2);}
            if(i==2){gril[i][j].pos.y=636-i*(pion_jaune->h+2);}
            if(i==3){gril[i][j].pos.y=638-i*(pion_jaune->h+2);}
            if(i==4){gril[i][j].pos.y=639-i*(pion_jaune->h+2);}
            if(i==5) {gril[i][j].pos.y=640-i*(pion_jaune->h+2);}

            if(j==0){gril[i][j].pos.x=21;}
            if(j==1){gril[i][j].pos.x=21+j*(pion_jaune->w);}
            if(j==2){gril[i][j].pos.x=21+j*(pion_jaune->w);}
            if(j==3){gril[i][j].pos.x=23+j*(pion_jaune->w);}
            if(j==4){gril[i][j].pos.x=24+j*(pion_jaune->w);}
            if(j==5){gril[i][j].pos.x=25+j*(pion_jaune->w);}
            if(j==6){gril[i][j].pos.x=26+j*(pion_jaune->w);}

         ///Definition des coordonnées
        }
    }
    SDL_Surface *grille=SDL_LoadBMP("grille.bmp");
    if(!grille){
        printf("\nERROR");
    }
    SDL_SetColorKey(grille,SDL_SRCCOLORKEY,SDL_MapRGB(grille->format,0,0,0));
    SDL_Surface *pion_rouge=SDL_LoadBMP("pion_rouge.bmp");
    if(!pion_rouge){
        printf("\nERROR");
    }
    SDL_SetColorKey(pion_rouge,SDL_SRCCOLORKEY,SDL_MapRGB(pion_rouge->format,0,0,0));

    if(!pion_jaune){
        printf("\nERROR");
    }
    SDL_SetColorKey(pion_jaune,SDL_SRCCOLORKEY,SDL_MapRGB(pion_jaune->format,0,0,0));
    SDL_Surface *choix_couleurs=SDL_LoadBMP("choix_couleurs.bmp");
    if(!choix_couleurs){
        printf("\nERROR");
    }
    SDL_SetColorKey(choix_couleurs,SDL_SRCCOLORKEY,SDL_MapRGB(choix_couleurs->format,0,0,0));
    SDL_Surface *fond=SDL_LoadBMP("fond.bmp");
    if(!fond){
        printf("\nERROR");
    }
    SDL_Surface *bouton_retour=SDL_LoadBMP("bouton_retour.bmp");
    SDL_SetColorKey(bouton_retour,SDL_SRCCOLORKEY,SDL_MapRGB(bouton_retour->format,0,0,0));
    ///*********************************

    SDL_Rect pos_choix_couleurs,pos_fond,pos_bouton_retour;
    pos_grille.x=20;
    pos_grille.y=fond->h-grille->h;
    pos_choix_couleurs.x=20+grille->w+20;
    pos_choix_couleurs.y=40;  ///20+grille-
    pos_fond.x=0;
    pos_fond.y=0;
    pos_bouton_retour.x=0;
    pos_bouton_retour.y=0;
	init_game(Tab);
	while(n==0){
		//printf("\nChoisissez une couleur: R ou B :");
		//scanf("%c",&c);
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_MOUSEBUTTONDOWN:
                switch (event.button.button)
                {
                case SDL_BUTTON_LEFT:
                    if (event.button.y<=40+choix_couleurs->h && event.button.y>=40
                        && event.button.x>=(pos_choix_couleurs.x) && event.button.x<=(pos_choix_couleurs.x+choix_couleurs->w/2))
                    {
                        c='R';
                        n=1;
                    }
                    else if(event.button.y<=40+choix_couleurs->h && event.button.y>=40
                        && event.button.x<=(pos_choix_couleurs.x+choix_couleurs->w) && event.button.x>=(pos_choix_couleurs.x+choix_couleurs->w/2))
                    {
                        c='B';
                        n=1;
                    }
                    if (event.button.x>=0 && event.button.x<=92
                        && event.button.y>=0 && event.button.y <=105)
                     {
                       n=1;
                       continuer=1;


                     }
                    break;

                }
                break;
            case SDL_QUIT:
            	exit(EXIT_SUCCESS);
                  break;
            }
        }


        SDL_WM_SetCaption("Jeu Puissance4", NULL);
		SDL_BlitSurface(fond,0,screen,&pos_fond);
        SDL_BlitSurface(choix_couleurs,0,fond,&pos_choix_couleurs);
        SDL_BlitSurface(bouton_retour,0,fond,&pos_bouton_retour);
        SDL_Flip(screen);
        if(c=='R' || c=='r'){
			joueur=1;
			n=1;
		}
		else if(c=='B' || c=='b'){
			joueur=2;
			n=1;
		}

	}
	SDL_WM_SetCaption("Jeu Puissance4", NULL);
    SDL_FreeSurface(choix_couleurs);

	srand(time(NULL));
	premier=rand()%2+1;

	if(joueur==1)jaid=2;
	else if(joueur==2)jaid=1;
    if(premier==joueur){tour=0;}
    else if(premier!=joueur){tour=1;}
    ///*********************************

    SDL_Surface *success_rouge=SDL_LoadBMP("success_rouge.bmp");

    SDL_Surface *success_jaune=SDL_LoadBMP("success_jaune.bmp");
    if(!success_rouge || !success_jaune){
        printf("[nERROR");
    }
    SDL_SetColorKey(success_rouge,SDL_SRCCOLORKEY,SDL_MapRGB(success_rouge->format,0,0,0));
    SDL_SetColorKey(success_jaune,SDL_SRCCOLORKEY,SDL_MapRGB(success_jaune->format,0,0,0));

    SDL_Rect pos_success;
    pos_success.x=(screen->w-success_jaune->w)/2;
    pos_success.y=(screen->h-success_jaune->h)/2;

    while(continuer==0){
        while(SDL_PollEvent(&event)){
            if(event.type== SDL_MOUSEBUTTONDOWN){
                if(event.button.button== SDL_BUTTON_LEFT){
                    if(tour==0 && event.button.x>=21 && event.button.x<=21+60 && event.button.y<=700
                        && event.button.y>=700-grille->h ){
                        tour=placer_pion(Tab,joueur,1);

                        if(tour==1){
                        	compt_h++;
                        }
                    }
                    if(tour==0 &&event.button.x>=81 && event.button.x<=81+60 && event.button.y<=700
                        && event.button.y>=700-grille->h){
                        tour=placer_pion(Tab,joueur,2);
                         if(tour==1){
                        	compt_h++;
                        }
                    }
                    if(tour==0 &&event.button.x>=141 && event.button.x<=141+60 && event.button.y<=700
                        && event.button.y>=700-grille->h){
                        tour=placer_pion(Tab,joueur,3);
                         if(tour==1){
                        	compt_h++;
                        }
                    }
                    if(tour==0 && event.button.x>=23+180 && event.button.x<=23+180+60 && event.button.y<=700
                        && event.button.y>=700-grille->h){
                        tour=placer_pion(Tab,joueur,4);
                         if(tour==1){
                        	compt_h++;
                        }
                    }
                    if(tour==0 &&event.button.x>=24+240 && event.button.x<=24+240+60 && event.button.y<=700
                        && event.button.y>=700-grille->h){
                        tour=placer_pion(Tab,joueur,5);
                         if(tour==1){
                        	compt_h++;
                        }
                    }
                    if(tour==0 && event.button.x>=25+300 && event.button.x<=25+300+60 && event.button.y<=700
                        && event.button.y>=700-grille->h){
                        tour=placer_pion(Tab,joueur,6);
                        if(tour==1){
                        	compt_h++;
                        }
                    }
                    if(tour==0 && event.button.x>=26+360 && event.button.x<=26+360+60 && event.button.y<=700
                        && event.button.y>=700-grille->h){
                        tour=placer_pion(Tab,joueur,7);
                        if(tour==1){
                        	compt_h++;
                        }
                    }
                    if(puissance(Tab,joueur)==1){
                        success=1;
                        tour=2;
                        //continuer=1;
                        ///Appeler fonction fin de jeu
                    }
                    if(tour==1){
                        if(niveau==1){tour=placer_pion_m1(Tab,jaid);}
                    	if(niveau==2){tour=placer_pion_m2(Tab,jaid);}
                    	if(niveau==3){tour=placer_pion_m3(Tab,jaid);}
                    	printf("\nNombre de noeuds Parcourus: %i ",nbre_noeuds);
                    	//if(niveau==3){tour=placer_pion_m3(Tab,jaid);}
                    	if(tour==0){
                        	compt_m++;
                        }

                    }
                    if(puissance(Tab,jaid)==1){
                        success=2;
                        tour=2;
                        //continuer=1;
                        ///Appeler fonction fin de jeu
                    }
                    if (event.button.x>=0 && event.button.x<=92
                        && event.button.y>=0 && event.button.y <=105)
                    {

                        continuer=1;


                    }

                }

            }
            if(event.type==SDL_QUIT){
                continuer=1;
                exit(EXIT_SUCCESS);
            }

        }
    SDL_WM_SetCaption("Jeu Puissance4", NULL);
    SDL_BlitSurface(fond,0,screen,&pos_fond);
    SDL_BlitSurface(grille,0,fond,&pos_grille);
    SDL_BlitSurface(bouton_retour,0,fond,&pos_bouton_retour);


    for(i=0;i<6;i++){
        for(j=0;j<7;j++){
            if(Tab[i][j].color=='R'){
                 SDL_BlitSurface(pion_rouge,0,fond,&gril[i][j].pos);
            }
            else if(Tab[i][j].color=='B'){
                 SDL_BlitSurface(pion_jaune,0,fond,&gril[i][j].pos);
            }


        }

    }
    if(success==1){
        if(joueur==1)SDL_BlitSurface(success_rouge,0,fond,&pos_success);
        else SDL_BlitSurface(success_jaune,0,fond,&pos_success);
    }
    else if(success==2){
       if(jaid==1)SDL_BlitSurface(success_rouge,0,fond,&pos_success);
       else SDL_BlitSurface(success_jaune,0,fond,&pos_success);
    }


    SDL_Flip(screen);
    if((compt_h+compt_m)==42){
        continuer=1;
        ///appeler Une procedure demandant si l'utilisateur veut quitter ou s'il veut retourner au menu
    }

    }
SDL_FreeSurface(fond);
SDL_FreeSurface(grille);
SDL_FreeSurface(pion_rouge);
SDL_FreeSurface(pion_jaune);
SDL_FreeSurface(success_rouge);
SDL_FreeSurface(success_jaune);
SDL_FreeSurface(bouton_retour);


}

#endif /* JEUNIVEAUFACILE_H_ */
