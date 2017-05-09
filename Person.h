#pragma once
#include <iostream>
#include <string>

class Person{

public:
    Person()
    {
        std::cout << "Default Constructor" << std::endl;
        m_age = -1;
        m_name = NULL;
    }
    
    Person(int age)
    :m_age(age), m_name(NULL)
    {
        //m_age = age;
        //m_name = NULL;
        
        std::cout << "Age Constructor" << std::endl;
    }
    
    Person(int age, char* name)
    {
        m_age = age; 
        // m_name = name; - X
        m_name = new char[strlen(name)+1];
        strcpy(m_name, name);
    }
    
    ~Person()
    {
        std::cout << "Destructor" << std::endl;
        if(m_name != NULL)
            delete [] m_name;
    }
    
private:
    int   m_age;
    char* m_name;
};





