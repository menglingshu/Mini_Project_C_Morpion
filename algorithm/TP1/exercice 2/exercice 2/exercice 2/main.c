//
//  main.c
//  exercice 2
//
//  Created by MENG on 15/9/16.
//  Copyright (c) 2015年 MENG. All rights reserved.
//

#include<stdio.h>

#include<math.h>


int SOMME_DIV(number)
{
    int somme = 0;
    for(int i=1; i<=sqrt(number); i++)
    {
        if(number%i==0)
        {
            somme = somme + i + number/i;
        }
    }
    somme-=number;
    return somme;
}
int PARFAIT(input)
{
    if(input== SOMME_DIV(input))
        return 1;
    else
        return 0;
}
int main()
{
    PRINTF("les nombre parfait sont:\n");
    for(int j=2; j<9999; j++)
    {
        if(PARFAIT(j))
        {
            pritnf("%d\t", j);
        }
    }
    return 0;
}