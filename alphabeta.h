#ifndef ALPHABETA_H_INCLUDED
#define ALPHABETA_H_INCLUDED

/*
 int minimax(Position pere[6][7],int joueur,int indma,int colonne,int p){//Commencer la boucle avec indma=indice de min
	int jaid=joueur%2+1;
	int alpha,beta,i,j,retour;

	Position fils1[6][7];

	if (puissance(pere,joueur) || p==0){
		return heuristique(pere,joueur,colonne);
	}
	else if(is_free(pere)) return -1;
	else{
		if(joueur==indma){
			retour=0;
			for(i=1;i<8;i++){
				make_fils(pere,fils1,i,joueur);
				retour=max(retour,minimax(fils1,jaid,indma,i,p-1));
			}

			return retour;
		}
		else{
			retour=0;
			for(i=1;i<8;i++){
				make_fils(pere,fils1,i,jaid);
				retour=min(retour,minimax(fils1,joueur,indma,i,p-1));
			}

			return retour;

		}
	}

}
 */




int alphabeta(Position pere[6][7],int joueur,int indma,int colonne,int p){//Commencer la boucle avec indma=indice de min

	int jaid=joueur%2+1;
	int i,j;
	double retour,alpha,beta;
	Position fils1[6][7];
	alpha=0;
	beta=1000000000;

	if (puissance(pere,joueur) || p==0){
		if(joueur==indma)arret=1;
		return heuristique(pere,joueur,colonne);
	}
	else if(is_free(pere)) return -1;
	else{
		if(joueur==indma){
			retour=-5;
			for(i=1;i<8;i++){
				make_fils(pere,fils1,i,joueur);
				retour=max(retour,alphabeta(fils1,jaid,indma,i,p-1));
				if(retour>beta)return retour;
				alpha=max(alpha,retour);
			}

		}
		else{
			retour=1000000000;
			for(i=1;i<8;i++){
				make_fils(pere,fils1,i,jaid);
				retour=min(retour,alphabeta(fils1,joueur,indma,i,p-1));
				if(alpha>retour)return retour;
				beta=min(beta,retour);
			}



  		}
		return retour;
	}

}


int choix_colonne_alphabeta(Position Tab[6][7],int joueur){
	int c,Max=0,Minimax;
		int indma,indice;
		Position fils[6][7],fils2[6][7];;
		indma=joueur%2+1;
		nbre_noeuds=0;
		arret=0;
		int jaid=indma;
		for(c=1;c<8;c++){
			make_fils(Tab,fils,c,joueur);
			Minimax=alphabeta(fils,joueur,indma,c,3);///Profondeur optimale=4
			make_fils(Tab,fils2,c,jaid);
			if(puissance(fils2,jaid)==1){
				Minimax+=100000000;
			}
			if(puissance3(fils2,jaid)==1){
				Minimax+=1000000;
			}
			if(Minimax>Max){
				Max=Minimax;
				indice=c;
			}
		}
		return indice;

}

int placer_pion_m3(Position Tab[6][7],int joueur){

	int j=0;
	char couleur[2];
	couleur[0]='R';
	couleur[1]='B';
	int Etat[2]={1,2};

		int c=choix_colonne_alphabeta(Tab,joueur)-1;
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








#endif // ALPHABETA_H_INCLUDED
