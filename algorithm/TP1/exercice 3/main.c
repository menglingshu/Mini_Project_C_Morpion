//
//  main.c
//  TP1
//
//  Created by MENG on 15/9/15.

#include<stdio.h>

int main()
{
    int n;
    char a[100];
    printf("veillez donner le fois n et une chaine de caracteres:\n");
    scanf("%d %s", &n, a);
    for(int i=0; i<n ; i++)
    {
        printf("%s \n", a);
    }
   
}