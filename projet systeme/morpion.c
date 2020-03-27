#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>


//rien de compliqué dans la génération de la grille.
//on definit juste que toutes les cases sont vides.
//0 est vide, 1 est un X, 2 est un O
void generationGrille(int grille[3][3]){
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        grille[i][j]=0;
      }
    }
}


//C'est énervant de travailler avec des char*
char* symboleCase(int grille[3][3],int i,int j){
  if (grille[i][j]==0){
    return " ";
  }
  else if(grille[i][j]==1){
    return "X";
  }
  else if(grille[i][j]==2){
    return "O";
  }
  return "erreur";
}

//sachant qu'en général, i définie une colonne, et j définie la ligne,
//la fonction d'affichage parcourt une ligne, et check les colonnes 0, 1 et 2 avant d'afficher.
//d'ou les deux if qui sont en j puis en i, dans un soucis de lisibilité.

void afficherGrille(int grille[3][3]){
  char ligneAffiche[256];
  for (int j = 0; j < 3; j++) {
	  switch(j)
	  {
		  case 0:
		  strcat(ligneAffiche,"1");
		  break;
		  case 1:
		  strcat(ligneAffiche,"2");
		  break;
		  case 2:
		  strcat(ligneAffiche,"3");
		  break;
	  }
	  
    for (int i = 0; i < 3; i++) {
      strcat(ligneAffiche,"|");
      strcat(ligneAffiche,symboleCase(grille,i,j));
      strcat(ligneAffiche,"|");
    }
    strcat(ligneAffiche,"\n");
  }
  strcat(ligneAffiche,"  A  B  C \n");
  printf("%s",ligneAffiche);
}

void demandeCoordo(int grille[3][3], int joueur){
	printf("Entrez les coordonnées où vous voulez jouer : \n");
	char coord[20];
   scanf("%s", coord);
	if(strcmp(coord,"A1")==0){
		grille[0][0]=joueur;
	}
	else if(strcmp(coord,"A2")==0){
		grille[0][1]=joueur;
	}
	else if(strcmp(coord,"A3")==0){
		grille[0][2]=joueur;
	}
	else if(strcmp(coord,"B1")==0){
		grille[1][0]=joueur;
	}
	else if(strcmp(coord,"B2")==0){
		grille[1][1]=joueur;
	}
	else if(strcmp(coord,"B3")==0){
		grille[1][2]=joueur;
	}
	else if(strcmp(coord,"C1")==0){
		grille[2][0]=joueur;
	}
	else if(strcmp(coord,"C2")==0){
		grille[2][1]=joueur;
	}
	else if(strcmp(coord,"C3")==0){
		grille[2][2]=joueur;
	}
}

int main(int argc, char const *argv[]) {

  int grilleMorpion[3][3];
  generationGrille(grilleMorpion);
  afficherGrille(grilleMorpion);
  demandeCoordo(grilleMorpion, 1);
  afficherGrille(grilleMorpion);

  return 0;
}
