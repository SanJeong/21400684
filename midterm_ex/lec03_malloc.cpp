#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

int main(){
    int **coordinate;
    int xsize, ysize,i,j;
    xsize = 3;
    ysize = 6;
    
    
    coordinate=(int**)malloc(sizeof(int*)*xsize);
    for(i=0;i<xsize;i++){
        coordinate[i]=(int*)malloc(sizeof(int)*ysize);
    }
    for(i=0;i<xsize;i++){
        for(j=0;j<ysize;j++){
            std::cin>>coordinate[i][j];
        }
    }
    for(i=0;i<xsize;i++){
        for(j=0;j<ysize;j++){
            printf("[%1d][%1d] : %2d\n",i,j,coordinate[i][j]);
        }
    }
    free(coordinate);
    return 0;
    
}