#include <stdio.h>
#include <iostream>
#include "stdafx.h"

struct student{ 
    char name[20]; 
    int age;
};

int main(){
    struct student *p1 == new struct student[sizeof(struct student)];
    void *ptr;
    
    strcpy(p1 -> name[20] =  "정산");
    p1 -> age = 30;
    
    ptr = p1;
    
    std::cout<<'이름:'<<<<std::endl;
    
    delete []p1;
    return 0;
}
