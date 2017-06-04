#include <iostream>

#include "Person.h"

Person superman;

int main(int argc, char** argv)
{
    std::cout << "Main Start!" << std::endl;
    {
        int a;
        Person student;
        
        int b = int();
        Person stduent2 = Person();
        
    }
    
    {
        int a = 10;
        Person student(10);
        
        int b = int(10);
        Person student2 = Person(10);
    }
    
    Person* pStudent;
    {
        // 1. const char _temp[] = "cbcho";
        
        // 2. pStudent = new Person(10, _temp);
        
        pStudent = new Person(10, "cbchoi");
    }
    
    delete pStudent;
    return 0;
}#include <iostream>

#include "Person.h"

Person superman;

int main(int argc, char** argv)
{
    std::cout << "Main Start!" << std::endl;
    {
        int a;
        Person student;
        
        int b = int();
        Person stduent2 = Person();
        
    }
    
    {
        int a = 10;
        Person student(10);
        
        int b = int(10);
        Person student2 = Person(10);
    }
    
    Person* pStudent;
    {
        // 1. const char _temp[] = "cbcho";
        
        // 2. pStudent = new Person(10, _temp);
        
        pStudent = new Person(10, "cbchoi");
    }
    
    delete pStudent;
    return 0;
}