//
//  main.c
//  find max in two-dimension array
//
//  Created by MENG on 15/8/28.
//  Copyright (c) 2015年 MENG. All rights reserved.
//

#include<stdio.h>
int main()
{
    int i, j, row = 0, colum = 0, max;
    int a[3][4] = {{1, 2, 3, 4}, {9, 8, 7, 6}, {11, 10, -5, 2}};
    max = a[0][0];
    for(i=0;i<=2;i++)
        for(j=0;j<=3;j++)
            if(a[i][j]>max)
            {
                max = a[i][j];
                row = i;
                colum = j;
            }
    printf("max=%d\nrow=%d\ncolum=%d\n", max, row, colum);
    return 0;
}