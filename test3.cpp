#include <stdio.h>
#include <iostream>
#include <cstring>
#include <iomanip>

struct student{ 
    char name[20]; 
    int age;
};

int main(){
    struct student *p1 = new struct student[sizeof(struct student)];
    void *ptr;
    
    strcpy(p1 -> name,  "정산");
    p1 -> age = 30;
    
    ptr = p1;

    std::cout<<"이름:"<<static_cast<struct student*>(ptr)->name <<std::endl;
    std::cout<<"나이:"<<static_cast<struct student*>(ptr)->age <<std::endl;
    //gittest이
    delete []p1;
    return 0;
}