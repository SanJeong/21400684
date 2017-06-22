#include <iostream>
#include <cstring>
#include <stdio.h> 
void swap(int &a,int &b);


int main(){
    int a =0, b=20;

    
    std::cout<<a<<",,"<<b<<std::endl;
    swap(a,b);
    std::cout<<a<<",,"<<b<<std::endl;
    
}
void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
