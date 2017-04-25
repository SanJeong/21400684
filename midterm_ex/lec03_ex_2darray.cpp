#include <iostream>
#include <cstring>
#include <stdio.h>

int arr1[2][3] ={1,2,3,4,5,6};
int i,j;
int main(){
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            printf("[%1d][%1d] %1d",i,j,arr1[i][j]);
            std::cout<<std::endl;
            
        }
    }
}