/*
 * fonctions.h
 *
 *  Created on: 31 mars 2020
 *      Author: razing
 */

#ifndef FONCTIONS_H_
#define FONCTIONS_H_

typedef struct position{
	char color;
	int etat;
}Position;

int min(int a,int b){
	if(a<=b)return a;
	else return b;

}
int max(int a,int b){
	if(a>=b)return a;
	else return b;
}
int init_game(Position Tab[6][7]){
	int i,j;
	for(i=0;i<6;i++){
		for(j=0;j<7;j++){
			Tab[i][j].etat=0;
			Tab[i][j].color='N';
		}
	}
	return 0;
}

int placer_pion(Position Tab[6][7],int joueur,int colonne){
	int c,j=0;
	char couleur[2];
	couleur[0]='R';
	couleur[1]='B';
	int Etat[2]={1,2};


		c=colonne-1;
		j=0;
		while(j<6){
			if(Tab[j][c].color=='N'){
			Tab[j][c].color = couleur[joueur-1];
			Tab[j][c].etat= Etat[joueur-1];
				return 1;
			}
			else{j++;}

		}

    return 0;
}

int puissance(Position Tab[6][7],int joueur){
	int i,j,retour=0;
	char couleur[2]={'R','B'};

	//1
	for(i=0;i<6;i++){
		for(j=0;j<4;j++){
			if(Tab[i][j].color==couleur[joueur-1] && Tab[i][j+1].color==couleur[joueur-1]
			&& Tab[i][j+2].color==couleur[joueur-1] && Tab[i][j+3].color==couleur[joueur-1]){

				retour=1;
				goto end;
			}
		}
	}
	//2
	for(i=0;i<6;i++){
		for(j=3;j<7;j++){
			if(Tab[i][j].color==couleur[joueur-1] && Tab[i][j-1].color==couleur[joueur-1]
			&& Tab[i][j-2].color==couleur[joueur-1] && Tab[i][j-3].color==couleur[joueur-1]){

				retour=1;
				goto end;
			}
		}
	}
	//3
	for(i=3;i<6;i++){
		for(j=0;j<7;j++){
			if(Tab[i][j].color==couleur[joueur-1] && Tab[i-1][j].color==couleur[joueur-1]
			&& Tab[i-2][j].color==couleur[joueur-1] && Tab[i-3][j].color==couleur[joueur-1]){

				retour=1;
				goto end;
			}
		}
	}
	//4
	for(i=0;i<3;i++){
		for(j=0;j<7;j++){
			if(Tab[i][j].color==couleur[joueur-1] && Tab[i+1][j].color==couleur[joueur-1]
			&& Tab[i+2][j].color==couleur[joueur-1] && Tab[i+3][j].color==couleur[joueur-1]){

				retour=1;
				goto end;
			}
		}
	}
	//5
	for(i=3;i<6;i++){
		for(j=0;j<4;j++){
			if(Tab[i][j].color==couleur[joueur-1] && Tab[i-1][j+1].color==couleur[joueur-1]
			&& Tab[i-2][j+2].color==couleur[joueur-1] && Tab[i-3][j+3].color==couleur[joueur-1]){

				retour=1;
				goto end;
			}
		}
	}
	//6
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			if(Tab[i][j].color==couleur[joueur-1] && Tab[i+1][j+1].color==couleur[joueur-1]
			&& Tab[i+2][j+2].color==couleur[joueur-1] && Tab[i+3][j+3].color==couleur[joueur-1]){

				retour=1;
				goto end;
			}
		}
	}
	//7
	for(i=0;i<3;i++){
		for(j=3;j<7;j++){
			if(Tab[i][j].color==couleur[joueur-1] && Tab[i+1][j-1].color==couleur[joueur-1]
			&& Tab[i+2][j-2].color==couleur[joueur-1] && Tab[i+3][j-3].color==couleur[joueur-1]){

				retour=1;
				goto end;
			}
		}
	}
	//8
	for(i=3;i<6;i++){
		for(j=3;j<7;j++){
			if(Tab[i][j].color==couleur[joueur-1] && Tab[i-1][j-1].color==couleur[joueur-1]
			&& Tab[i-2][j-2].color==couleur[joueur-1] && Tab[i-3][j-3].color==couleur[joueur-1]){

				retour=1;
				goto end;
			}
		}
	}
	end:

	return retour;
}

int puissance3(Position Tab[6][7],int joueur){
	int i,j,retour=0;
	char couleur[2]={'R','B'};

	//1
	for(i=0;i<6;i++){
		for(j=0;j<4;j++){
			if(Tab[i][j].color==couleur[joueur-1] && Tab[i][j+1].color==couleur[joueur-1]
			&& Tab[i][j+2].color==couleur[joueur-1]){

				retour=1;
				goto end;
			}
		}
	}
	//2
	for(i=0;i<6;i++){
		for(j=3;j<7;j++){
			if(Tab[i][j].color==couleur[joueur-1] && Tab[i][j-1].color==couleur[joueur-1]
			&& Tab[i][j-2].color==couleur[joueur-1]){

				retour=1;
				goto end;
			}
		}
	}
	//3
	for(i=3;i<6;i++){
		for(j=0;j<7;j++){
			if(Tab[i][j].color==couleur[joueur-1] && Tab[i-1][j].color==couleur[joueur-1]
			&& Tab[i-2][j].color==couleur[joueur-1]){

				retour=1;
				goto end;
			}
		}
	}
	//4
	for(i=0;i<3;i++){
		for(j=0;j<7;j++){
			if(Tab[i][j].color==couleur[joueur-1] && Tab[i+1][j].color==couleur[joueur-1]
			&& Tab[i+2][j].color==couleur[joueur-1]){

				retour=1;
				goto end;
			}
		}
	}
	//5
	for(i=3;i<6;i++){
		for(j=0;j<4;j++){
			if(Tab[i][j].color==couleur[joueur-1] && Tab[i-1][j+1].color==couleur[joueur-1]
			&& Tab[i-2][j+2].color==couleur[joueur-1]){

				retour=1;
				goto end;
			}
		}
	}
	//6
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			if(Tab[i][j].color==couleur[joueur-1] && Tab[i+1][j+1].color==couleur[joueur-1]
			&& Tab[i+2][j+2].color==couleur[joueur-1]){

				retour=1;
				goto end;
			}
		}
	}
	//7
	for(i=0;i<3;i++){
		for(j=3;j<7;j++){
			if(Tab[i][j].color==couleur[joueur-1] && Tab[i+1][j-1].color==couleur[joueur-1]
			&& Tab[i+2][j-2].color==couleur[joueur-1]){

				retour=1;
				goto end;
			}
		}
	}
	//8
	for(i=3;i<6;i++){
		for(j=3;j<7;j++){
			if(Tab[i][j].color==couleur[joueur-1] && Tab[i-1][j-1].color==couleur[joueur-1]
			&& Tab[i-2][j-2].color==couleur[joueur-1]){

				retour=1;
				goto end;
			}
		}
	}
	end:

	return retour;
}
void affichage(Position Tab[6][7]){
	int i,j;
	char C[6][7];
	for(i=0;i<6;i++){
		for(j=0;j<7;j++){
			if(Tab[i][j].color=='N'){
				C[i][j]=' ';
			}
			else C[i][j] = Tab[i][j].color;
		}

	}


		 printf("\n\t\t 1    2   3   4   5   6   7");
		 printf("\n\t\t ___________________________\n");
	i=5; printf("\t\t| %c | %c | %c | %c | %c | %c | %c |\n",C[i][0],C[i][1],C[i][2],C[i][3],C[i][4],C[i][5],C[i][6]);
		 printf("\t\t|___|___|___|___|___|___|___|\n");
	i=4; printf("\t\t| %c | %c | %c | %c | %c | %c | %c |\n",C[i][0],C[i][1],C[i][2],C[i][3],C[i][4],C[i][5],C[i][6]);
		 printf("\t\t|___|___|___|___|___|___|___|\n");
	i=3; printf("\t\t| %c | %c | %c | %c | %c | %c | %c |\n",C[i][0],C[i][1],C[i][2],C[i][3],C[i][4],C[i][5],C[i][6]);
		 printf("\t\t|___|___|___|___|___|___|___|\n");
	i=2; printf("\t\t| %c | %c | %c | %c | %c | %c | %c |\n",C[i][0],C[i][1],C[i][2],C[i][3],C[i][4],C[i][5],C[i][6]);
	 	 printf("\t\t|___|___|___|___|___|___|___|\n");
	i=1; printf("\t\t| %c | %c | %c | %c | %c | %c | %c |\n",C[i][0],C[i][1],C[i][2],C[i][3],C[i][4],C[i][5],C[i][6]);
		 printf("\t\t|___|___|___|___|___|___|___|\n");
	i=0; printf("\t\t| %c | %c | %c | %c | %c | %c | %c |\n",C[i][0],C[i][1],C[i][2],C[i][3],C[i][4],C[i][5],C[i][6]);
		 printf("\t\t|___|___|___|___|___|___|___|\n");
		printf("\n\n");

}


#endif /* FONCTIONS_H_ */
