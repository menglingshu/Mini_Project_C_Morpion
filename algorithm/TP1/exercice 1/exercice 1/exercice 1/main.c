//
//  main.c
//  exercice 1
//
//  Created by MENG on 15/9/16.
//  Copyright (c) 2015年 MENG. All rights reserved.
//


#include<stdio.h>

#include<math.h>





void diviseur(number){
    
    printf("Tous les diviseur de %d sont :",number);
    
    for (int i = 1 ; i <= sqrt(number) ; i++) {
        
        
        
        if( number%i==0){
            
            printf("\t%d\t%d",i, number/i);
            
        }
        
        
        
    }
    
    printf("\n");
    
}







int main()

{
    
    
    
    
    
    
    
    diviseur(48);
    
    diviseur(1516);
    
    diviseur(2342);
    
    
    
    return 0;
    
}
