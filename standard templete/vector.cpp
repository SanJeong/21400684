#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>

class Thing
{
public:
    Thing(std::string name)
    :m_name(name){ }
public:
    std::string& get_name(){ return m_name; }
    
    virtual std::string say_something(){ return m_name; }
    
protected:
    std::string m_name;
};

class Person: public Thing //inheritance
{
public:
    Person(std::string name)
    :Thing(name){}
    
    std::string say_something(){ 
        std::string contents;
        contents += "My name is ";
        contents += m_name;
        return contents; 
    }
};

class Animal: public Thing 
{
public:
    Animal(std::string name)
    :Thing(name)
    {
        
    }
    
    std::string say_something(){ 
        std::string contents;
        contents += "Wang Wang! ";
        contents += m_name;
        return contents; 
    }
};

class ICTer: public Thing 
{
public:
    ICTer(std::string name)
    :Thing(name)
    {
        
    }
    
    std::string say_something(){ 
        std::string contents;
        contents += "I love Programming 2 ";
        contents += m_name;
        return contents; 
    }
};


int main(int argc, char** argv)
{
    std::map<std::string, std::vector<Thing*>* > m_student_list;
    
    if(m_student_list.find("SIT22005") != m_student_list.end())
    {
        // do something
        m_student_list["SIT22005"]->push_back(new Person("Hello1"));
        m_student_list["SIT22005"]->push_back(new Person("Hello2"));
        m_student_list["SIT22005"]->push_back(new Person("Hello3"));
        m_student_list["SIT22005"]->push_back(new Person("Hello4"));
    }
    else
    {
        m_student_list.insert(std::pair<std::string, std::vector<Thing*>*>("SIT22005", new std::vector<Thing*>));
    }
    
    
    
    //Person* p_list;
    std::list<Thing*> vecList;
    
    //// Game World
    vecList.push_back(new Person("Hello1"));
    vecList.push_back(new Person("Hello2"));
    vecList.push_back(new Animal("Hello3"));
    vecList.push_back(new ICTer("Hello3"));
    vecList.push_back(new Animal("Hello4"));
    ////
    
    /****************************************/
    //for(int i = 0; i < vecList.size(); i++)
    //{
    // //   std::cout << vecList[i].get_name().c_str() << std::endl;
    // std::cout << vecList[i]->say_something().c_str() << std::endl;
    //}
    
    for(std::list<Thing*>::iterator iter = vecList.begin();
        iter != vecList.end(); ++iter)
    {
        std::cout << (*iter)->say_something().c_str() << std::endl;
    }
    /****************************************/
    
    return 0;
}
