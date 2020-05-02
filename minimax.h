#ifndef MINIMAX
#define MINIMAX

int alphabeta(Position pere[6][7],int joueur,int indma,int colonne,int p);

int placer(Position Tab[6][7],int joueur,int colonne){
	int j,c;

	char couleur[2];
	couleur[0]='R';
	couleur[1]='B';
	int Etat [2]={1,2};
	j=0;
	c=colonne-1;
	while(j<6){
		if(Tab[j][c].etat==0){
			Tab[j][c].color = couleur[joueur-1];
			Tab[j][c].etat = Etat[joueur-1];
			return 1;

		}
		else {j++;}

	}

	return 0;
}
void copie(Position Tab[6][7],Position T[6][7]){
	int i,j;

	for(i=0;i<6;i++){
		for(j=0;j<7;j++){
			Tab[i][j]=T[i][j];
		}
	}

}
void make_fils(Position pere[6][7],Position fils[6][7],int col,int joueur){
	copie(fils,pere);
	if(placer(fils,joueur,col)==0)init_game(fils);
	else {
		if(arret==0) nbre_noeuds++;
		if(puissance(fils,joueur)==1)arret=1;
	}
}



int heuristique(Position Tableau[6][7],int joueur,int colonne){
	Position  Tab[6][7],Tab2[6][7];
	int i,j,compte,noteFinale;
	char couleur[2]={'R','B'};
	int jad,note[3]={0,0,0};
	jad=joueur%2+1;
	copie(Tab,Tableau);
	placer(Tab,joueur,colonne);
	//1
	compte=0;
	for(i=0;i<6;i++){
		for(j=0;j<4;j++){
			if(Tab[i][j].color!=couleur[jad-1] && Tab[i][j+1].color!=couleur[jad-1]
		      && Tab[i][j+2].color!=couleur[jad-1] && Tab[i][j+3].color!=couleur[jad-1]){

				if(Tab[i][j].color==couleur[joueur-1])compte++;
				if(Tab[i][j+1].color==couleur[joueur-1])compte++;
                if(Tab[i][j+2].color==couleur[joueur-1])compte++;
                if(Tab[i][j+3].color==couleur[joueur-1])compte++;

				if(compte==2){note[0]++;}
				if(compte==3){note[1]++;}
				if(compte==4){note[2]++;}
				}
			}
		}


	//3

	//4
	compte=0;
	for(i=0;i<3;i++){
		for(j=0;j<7;j++){
			if(Tab[i][j].color!=couleur[jad-1] && Tab[i+1][j].color!=couleur[jad-1]
			&& Tab[i+2][j].color!=couleur[jad-1] && Tab[i+3][j].color!=couleur[jad-1]){

				if(Tab[i][j].color==couleur[joueur-1])compte++;
				if(Tab[i+1][j].color==couleur[joueur-1])compte++;
			    if(Tab[i+2][j].color==couleur[joueur-1])compte++;
			    if(Tab[i+3][j].color==couleur[joueur-1])compte++;
				if(compte==2){note[0]++;}
				if(compte==3){note[1]++;}
				if(compte==4){note[2]++;}
			}
		}
	}
	//5

	//6
	compte=0;
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			if(Tab[i][j].color!=couleur[jad-1] && Tab[i+1][j+1].color!=couleur[jad-1]
			&& Tab[i+2][j+2].color!=couleur[jad-1] && Tab[i+3][j+3].color!=couleur[jad-1]){

				if(Tab[i][j].color==couleur[joueur-1])compte++;
				if(Tab[i+1][j+1].color==couleur[joueur-1])compte++;
				if(Tab[i+2][j+2].color==couleur[joueur-1])compte++;
				if(Tab[i+3][j+3].color==couleur[joueur-1])compte++;
				if(compte==2){note[0]++;}
				if(compte==3){note[1]++;}
				if(compte==4){note[2]++;}
			}
		}
	}
	//7
	compte=0;
	for(i=0;i<3;i++){
		for(j=3;j<7;j++){
			if(Tab[i][j].color!=couleur[jad-1] && Tab[i+1][j-1].color!=couleur[jad-1]
			&& Tab[i+2][j-2].color!=couleur[jad-1] && Tab[i+3][j-3].color!=couleur[jad-1]){

				if(Tab[i][j].color==couleur[joueur-1])compte++;
				if(Tab[i+1][j-1].color==couleur[joueur-1])compte++;
		        if(Tab[i+2][j-2].color==couleur[joueur-1])compte++;
		        if(Tab[i+3][j-3].color==couleur[joueur-1])compte++;
				if(compte==2){note[0]++;}
				if(compte==3){note[1]++;}
				if(compte==4){note[2]++;}
			}
		}
	}
	//8
	int jaid=joueur%2+1;
	noteFinale=0;
	copie(Tab2,Tableau);
	placer(Tab2,jaid,colonne);
	if(puissance(Tab2,jaid)==1){
		noteFinale=10000000;
	}

		noteFinale+=note[0]*5+note[1]*1000+note[2]*1000000;

	return noteFinale;
}



double maximum(double a,double b,double c,double d,double e,double f,double g){
	double Max=-1,tab[7]={a,b,c,d,e,f,g};
	int i;
	for(i=0;i<7;i++){
		if(tab[i]>=0 && tab[i]>=Max) Max=tab[i];
	}
	return Max;
}
double minimum(double a,double b,double c,double d,double e,double f,double g){
	double Min=1000000000,tab[7]={a,b,c,d,e,f,g};
	int i;
	for(i=0;i<7;i++){
		if(tab[i]>=0 && tab[i]<=Min) Min=tab[i];
	}

	return Min;
}

int is_free(Position Tab[6][7]){
	int i,j;
	for(i=0;i<6;i++){
		for(j=0;j<7;j++){
		if(Tab[i][j].etat!=0)return 0;

		}
	}


return 1;
}




int minimax(Position pere[6][7],int joueur,int indma,int colonne,int p){//Commencer la boucle avec indma=indice de min
	int jaid=joueur%2+1;

	Position fils1[6][7],fils2[6][7],fils3[6][7],fils4[6][7],fils5[6][7],fils6[6][7],fils7[6][7];
	double a,b,c,d,e,f,g;
	if (puissance(pere,joueur) || p==0){
		if(joueur==indma)arret=1;
		return heuristique(pere,joueur,colonne);
	}
	else if(is_free(pere)) return -1;
	else{
		if(joueur==indma){
			make_fils(pere,fils1,1,joueur);
			make_fils(pere,fils2,2,joueur);
			make_fils(pere,fils3,3,joueur);
			make_fils(pere,fils4,4,joueur);
			make_fils(pere,fils5,5,joueur);
			make_fils(pere,fils6,6,joueur);
			make_fils(pere,fils7,7,joueur);
			a=minimax(fils1,jaid,indma,1,p-1); b=minimax(fils2,jaid,indma,2,p-1);
			c=minimax(fils3,jaid,indma,3,p-1); d=minimax(fils4,jaid,indma,4,p-1);
			e=minimax(fils5,jaid,indma,5,p-1); f=minimax(fils6,jaid,indma,6,p-1); g=minimax(fils7,jaid,indma,7,p-1);
			return maximum(a,b,c,d,e,f,g);
		}
		else{
			make_fils(pere,fils1,1,jaid);
			make_fils(pere,fils2,2,jaid);
			make_fils(pere,fils3,3,jaid);
			make_fils(pere,fils4,4,jaid);
			make_fils(pere,fils5,5,jaid);
			make_fils(pere,fils6,6,jaid);
			make_fils(pere,fils7,7,jaid);

			a=minimax(fils1,joueur,indma,1,p-1); b=minimax(fils2,joueur,indma,2,p-1);
			c=minimax(fils3,joueur,indma,3,p-1); d=minimax(fils4,joueur,indma,4,p-1);
			e=minimax(fils5,joueur,indma,5,p-1); f=minimax(fils6,joueur,indma,6,p-1); g=minimax(fils7,joueur,indma,7,p-1);
			return minimum(a,b,c,d,e,f,g);
		}
	}

}

int choix_colonne_minimax(Position Tab[6][7],int joueur){
	int c,Max=0,Minimax;
	int indma,indice;
	Position fils[6][7],fils2[6][7];;
	indma=joueur%2+1;
	nbre_noeuds=0;
	arret=0;
	int jaid=indma;
	for(c=1;c<8;c++){
		make_fils(Tab,fils,c,joueur);
		Minimax=minimax(fils,joueur,indma,c,2);
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












#endif
