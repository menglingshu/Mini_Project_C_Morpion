//
//  main.c
//  morpion mini projet
//
//  Created by MENG on 15/9/5.


#include <stdio.h>
#define nblignes 11
#define nbcolonnes 11

char grille[nblignes][nbcolonnes];
int i, j;

void initialisergrille()
{
    for (i=0; i<nblignes; i++)
        for (j=0; j<nbcolonnes; j++)
            grille[i][j] = ' ';
}

//Affichage de la grille du morpion :
void affichergrille()
{
    for (i=0; i<nblignes; i++)
    {
        for (j=0; j<nbcolonnes; j++)
            printf("%c|", grille[i][j]);
        printf("\n- - - - - - - - - - -\n");
    }
    return;
}

/*Saisie des coordonnees du symbole a mettre sur la grille. Si les coordonnees
 sont en dehors de la grille ou si la case a deja ete remplie, la saisie est
 refusee, un message d'erreur s'affiche et le joueur doit rejouer. */
void mettresymbole(char symbole)
{
    printf("Veuillez donner les numeros de la ligne et de la colonne :");
    do
    {
        scanf("%i %i", &i, &j);
        if ((i>0) && (i<=nblignes) && (j>0) && (j<=nbcolonnes))
        {
            i--; //pour etre compatible avec les indices du tableau
            j--;
            if (grille[i][j]!=' ')
                printf("La case a deja ete remplie. Veuillez en choisir une autre :");
            else
            {
                grille[i][j]=symbole;
                if (symbole=='X')
                    symbole='O';
                else
                    symbole='X';
            }
        }
        else
            printf("Indice de ligne ou colonne incorrect. Veuillez ressaisir :");
    }
    while(grille[i][j]==' ');
}

//Test pour voir si l'un des joueurs a gagne :
int testgagnant(char symbole)
{
    int somme=0, gagne=0;
    for (i=0; i<nblignes; i++, somme=0)
    {
        for (j=0; j<nbcolonnes; j++)
            somme+=grille[i][j];
        if((somme==395) || (somme==440))
            gagne = 1;
    }
    for(j=0 ; j<nbcolonnes ; j++, somme=0)
    {
        for(i=0 ; i<nblignes ; i++)
            somme+=grille[i][j] ;
        if((somme==395) || (somme==440))
            gagne = 1;
    }
   
    if
    (   (grille[i][j] + grille[i+1][j] + grille[i-1][j] + grille[i-2][j] + grille[i+2][j] == 395)||
        (grille[i][j] + grille[i][j-1] + grille[i][j-2] + grille[i][j+1] + grille[i][j+2] == 395) ||
        (grille[i][j] + grille[i+1][j-1] + grille[i+2][j-2] + grille[i-1][j+1] + grille[i-2][j+2] == 395) ||
        (grille[i][j] + grille[i-1][j-1] + grille[i-2][j-2] + grille[i+1][j+1] + grille[i+2][j+2] == 395) ||
        (grille[i][j] + grille[i+1][j] + grille[i-1][j] + grille[i-2][j] + grille[i+2][j] == 440)||
        (grille[i][j] + grille[i][j-1] + grille[i][j-2] + grille[i][j+1] + grille[i][j+2] == 440) ||
        (grille[i][j] + grille[i+1][j-1] + grille[i+2][j-2] + grille[i-1][j+1] + grille[i-2][j+2] == 440) ||
        (grille[i][j] + grille[i-1][j-1] + grille[i-2][j-2] + grille[i+1][j+1] + grille[i+2][j+2] == 440)
    )
        {gagne = 1;}
    
    if (gagne)
    {
        printf("FELICITATIONS au joueur ayant les %c qui a gagne\n", symbole);
        return 1;
    }
    // Test si la grille est pleine :
    for(i=0; i<nblignes; i++)
        for(j=0; j<nbcolonnes; j++)
            if(grille[i][j] == ' ')
                return 0;
    printf(" EGALITE /n ");
    return 2;
}
//gagne 1次 得一分
//设定人机对战部分

int main()
{
    char symbole;
    initialisergrille();
    affichergrille();
    printf("Veuillez choisir votre symbole, O ou X :");
    scanf("%c", &symbole);
    do
    {
        mettresymbole(symbole);
        affichergrille();
    }
    while(!testgagnant(symbole));
    return 0;
}