#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// 1 - creer une fonction qui prend la variable solution, et la variable tableauJoueur (par exemple) : un tableau rempli de 0, cette fonction doit copier certaines valeurs (grace au rand() % N)
// de solution dans tableauJoueur afin d'initialiser une grille jouable ( car solution est bel est bien la solution, donc pas jouable par définition. ).
// un parametre doit permettre de verifier la condition de victoire en un seul coup (proposer votre façon de faire :) )

void copyArray(int solution[8][8], int tableauJoueur[8][8] ){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            tableauJoueur[i][j] = solution[i][j];
        }
    }
}

void afficher(int tab[8][8]) {
    // printf("|X,Y");
    printf("| Y\\X  ");

    for (int i = 0; i < 8; i++) {
        printf("| %d ", i);
    }
    printf("|\n");

    for (int i = 0; i < 9; i++) {
        printf("----");
    }
}







// 2- une fonction saisir qui demande au joueur de saisir 3 informations: i, j , et v qui permettront de placer la valeur v aux coordonnées (i,j)
// cette fonction doit verifier que les coordonnées sont valides (i et j entre 0 et 8) et que la valeur v est valide (entre 0 et 1)
int saisir(int tab[8][8]){
    int result = 0;
    while (result == 0){
        int tableaugenerer[8][8] = {
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0}
        };
        copyArray(tableaugenerer, tab);
        int saisie = 0;

        printf("saisir i : \n");
        scanf("%d", &saisie);
        int saisieI = saisie;

        printf("saisir j : \n");
        scanf("%d", &saisie);
        int saisieJ = saisie;

        if(tab[saisieI][saisieJ]){
            printf("case deja rempli...");
        } else {
            printf("quelle valeur voulez vous mettre ? \n");
            scanf("%d", &saisie);
            int saisieValeur = saisie;
            tableaugenerer[saisieI][saisieJ] = saisieValeur;

            result = (tableaugenerer, saisieI, 0);
            if(result == 1){
                tab[saisieI][saisieJ] = saisieValeur;
            }
        }
    }
    return result;

}



// 3- apres chaque coordonnées il faut verifier les regles du sudoku sur le tableauJoueur donc :

// - la fonction verifierLigneColonne ( qui verifie les lignes et les colonnes  sur lesquelles sont la nouvelle valeur)

int verifierLigneColonne(int tab[8][8], int ligne, int ligneOrCol ){
    int i, j, k;
    int copy[8][8];
    copyArray(tab, copy);
    int verif = 1;
    if(ligneOrCol == 0){
        for(i=0; i<8; ++i){
            if(copy[ligne][i] == 1){
                verif = 0;
            }
        }
    }
    else{
        for(i=0; i<8; ++i){
            if(copy[i][ligne] == 1){
                verif = 0;
            }
        }
    }
    return verif;
}
// - la fonction verifierGrille (qui fait ceci pour toute la grille et permet de definir la condition de victoire)
int verifierGrille(int tab[8][8]){
    int i, j, k;
    int copy[8][8];
    copyArray(tab, copy);
    int verif = 1;
    for(i=0; i<8; ++i){
        for(j=0; j<8; ++j){
            if(copy[i][j] == 1){
                verif = 0;
            }
        }
    }
    return verif;
}
// 4 - Ecrire le code principal qui permet de jouer au joueur :  le programme prend fin quand on gagne

int main(){
    // Ne pas toucher le code entre les commentaires

    srand( time( NULL ) );


    int i, j, k;
    printf("SOLUTION");
    printf("\n");
    printf("---------------------------------");
    printf("\n");

    int solution[8][8] = {
            {1,1,0,1, 0,1,0,0},
            {0,0,1,0, 1,0,1,1},
            {0,1,0,0, 1,1,0,1},
            {1,0,1,1, 0,0,1,0},

            {1,0,1,0, 0,1,1,0},
            {0,1,0,1, 1,0,0,1},
            {1,1,0,0, 1,0,1,0},
            {0,0,1,1, 0,1,0,1}
    };


    for(i=0;i<8; ++i)
    {
        for(j=0; j<8; ++j)
            printf("%d ", solution[i][j]);
        printf("\n");
    }
    printf("---------------------------------");
    printf("\n");
    //toucher le code entre les commentaires
    int tableauJoueur[8][8] = {
            {0,0,0,0, 0,0,0,0},
            {0,0,0,0, 0,0,0,0},
            {0,0,0,0, 0,0,0,0},
            {0,0,0,0, 0,0,0,0},

            {0,0,0,0, 0,0,0,0},
            {0,0,0,0, 0,0,0,0},
            {0,0,0,0, 0,0,0,0},
            {0,0,0,0, 0,0,0,0}
    };
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            printf("%d ", tableauJoueur[i][j]);
        }
        printf("\n");
    }
    int isTurning = 0;
    do{
        afficher(tableauJoueur);
        saisir(tableauJoueur);
        isTurning = verifierGrille(tableauJoueur);
    } while(isTurning);
    printf("Bravo, vous avez reussi");



    saisir(solution);
    verifierLigneColonne(solution, 0, 0);
    verifierGrille(solution);
    copyArray(solution, tableauJoueur);
    afficher(solution);

    //Ne pas toucher au code ci dessous
    system("pause");
    return 0;
}
