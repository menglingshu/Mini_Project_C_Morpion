//
//  main.c
//  exercice 4
//
//  Created by MENG on 15/9/16.
//  Copyright (c) 2015年 MENG. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>


void init(int tableau[], int taille)
{
    int i;
    for(i=0;i<taille;i++)
    {
        tableau[i]=rand()%100;
    }
}

void print(int tableau[], int taille)
{
    int i;
    printf("les entiers aleatoires sont:\n");
    for(i=0;i<taille;i++)
    {
       printf("%d\t",tableau[i]);
    }
}

int somme(int tableau[], int taille)
{
    int i, sum=0;
    for(i=0;i<taille;i++)
    {
        sum = sum + tableau[i];
    }
    printf("\nla somme des elements du tableau est %d\n", sum);
    return 0;
}

int min(int tableau[], int taille)
{
    int min, i;
    min = tableau[0];
    for(i=1; i<taille; i++)
    {
        if(tableau[i]<min)
        {min = tableau[i];}
    }
    printf("\nle min nombre est:%d", min);
    return min;
}

int max(int tableau[], int taille )
{
    int max,i;
    max= tableau[0];
    for(i=1; i<taille; i++)
    {
        if(tableau[i]>max)
        {max = tableau[i];}
    }
    printf("\nle max nombre est:%d", max);
    return max;
}

void tri(int tableau[], int taille)
{
    int i,j;
    int temp =0;
    printf("\nles nombre tri sont:\n");
    for(i=1; i<taille; i++)
    {
        temp = tableau[i];
        for(j=i;j>0&&tableau[j-1]>temp; j--)
        {
            if(temp<tableau[j-1])
            {
                tableau[j] = tableau[j-1];
            }
        }
        tableau[j] = temp;
    }
    int m;
    for(m=0; m<taille; m++)
    {
        printf("%d\t", tableau[m]);
    }
}

int main()
{
    int taille= 10;
    int tableau[taille];
    init(tableau,taille);
    print(tableau,taille);
    min(tableau, taille);
    max(tableau, taille);
    tri(tableau, taille);
    return 0;
}

