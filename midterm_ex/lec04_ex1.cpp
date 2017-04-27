#include <iostream>
#include <cstring>
#include <stdio.h>

int main(){
    int i;
    int &rr = i;
    i = 0;
    

    std::cout<<rr<<std::endl;
    return 0;
}