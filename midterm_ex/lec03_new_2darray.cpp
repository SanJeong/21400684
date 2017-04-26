#include <iostream>
#include <cstring>
#include <stdio.h>

int main(){
    int size1,size2,i,j;
    int**array;
    
    std::cin>>size1;
    std::cin>>size2;
    array = new int*[size1];
    for(i=0;i<size1;i++){
        array[i] = new int[size2];
    }
    for(i=0;i<size1;i++){
        delete []array[i];
    }
    delete[]array;
    
    
}