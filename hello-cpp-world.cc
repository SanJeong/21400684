int main(int argc, char** argv) // 포인터로 vector 리스트에 집어넣어서 각자 다른 수행을 가능하게 한다
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
    std::vector<Thing*> vecList;
    
    //// Game World
    vecList.push_back(new Person("Hello1"));
    vecList.push_back(new Person("Hello2"));
    vecList.push_back(new Animal("Hello3"));
    vecList.push_back(new ICTer("Hello3"));
    vecList.push_back(new Animal("Hello4"));
    ////
    
    /****************************************/
    for(int i = 0; i < vecList.size(); i++)
    {
     //   std::cout << vecList[i].get_name().c_str() << std::endl;
     std::cout << vecList[i]->say_something().c_str() << std::endl;
    }
    
    ///////////////////////////////////////////이럴떈 vector 보다 list가 빠르다 REALLOCATION 이 없기 때문에
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
}
    /****************************************/