//
//  main.c
//  exercice 5
//
//  Created by MENG on 15/9/16.
//  Copyright (c) 2015年 MENG. All rights reserved.
//



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
int IsPalindrome(char s[])
{
    int i,length;
    length = strlen(s);
    for (i=0; i<length/2; i++) {
        if (s[i] != s[length-1-i])
            return FALSE;
    }
    return TRUE;
}

int main() {
    char chaine[64];
    printf("entrez une chaine\n");
    scanf("%s",chaine);
    if (IsPalindrome(chaine)) {
        printf("%s est un palindrome\n", chaine);
    } else {
        printf("%s n_est pas un palindrome\n", chaine);
    } 
   
    return 0; 
}