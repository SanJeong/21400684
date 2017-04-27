#include <iostream>
#include <cstring>
#include <stdio.h> 
void swap(int * a,int *b);


int main(){
    int v1 =0, v2=20;
    int *ptr1 = NULL;
    int* ptr2 = NULL;
    ptr1 = &v1;
    ptr2 =&v2;
    
    std::cout<<*ptr1<<",,"<<*ptr2<<std::endl;
    swap(ptr1,ptr2);
    std::cout<<*ptr1<<",,"<<*ptr2<<std::endl;
    
}
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
