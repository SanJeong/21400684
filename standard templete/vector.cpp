#include <iostream>
#include <vector>
#include <string>

class Thing
{
public:
    Thing(std::string name)
    :m_name(name)
    {
        
    }
    
public:
    std::string& get_name()
    {
        return m_name;
    }
private:
    std::string m_name;
};

class Person: public Thing //inheritance
{
public:
    Person(std::string name)
    :Thing(name)
    {
        
    }
};

class Animal: public Thing 
{
public:
    Animal(std::string name)
    :Thing(name)
    {
        
    }
};

int main(int argc, char** argv)
{
    //Person* p_list;
    std::vector<Thing> vecList;
    
    vecList.push_back(Person("Hello1"));
    vecList.push_back(Person("Hello2"));
    vecList.push_back(Animal("Hello3"));
    vecList.push_back(Animal("Hello4"));
    
    for(int i = 0; i < vecList.size(); i++)
        std::cout << vecList[i].get_name().c_str() << std::endl;
    
    return 0;
}