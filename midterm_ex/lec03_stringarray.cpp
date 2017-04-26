#include <iostream>
#include <cstring>
#include <stdio.h>
#include <cstdio>

int main(){
    int t, i;
    char text[100][10];
    for(t=0;t<100;t++){
        std::cout<<t<":";
        gets(text[t]);
        if(!text[t][0]) break;
        
    }
    for(i=0;i<100;i++){
        std::cout<<gets(text[t])<<std::endl;
    
    }
    return 0;
}