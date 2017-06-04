#include <iostream>
#include "top_menu.h"

// single line comment
/*
  multi-line comments
*/

struct Member{
int  id;
char name[30];
int  member_type;
};

struct Member person;

person.member_type = 10;


int member_management_menu()
{
    int select;
    std::cout << "1. member add" << std::endl;
    std::cout << "2. member delete" << std::endl;
    std::cout << "3. member modify" << std::endl;
    std::cout << "99. Exit" << std::endl;
    std::cout << ">>";
    std::cin >> select;
    return select;
}

int main(int argc, char** argv)
{
    int select;ㄷ
    select = top_menu();

/*    
    bool result;
    if(select == 1)
        result = true;
    else if(select == 2)
        result = true;
    else if(select == 3)
        result = true;
    else
        result = false;
  */
  
    while(select != 99) //select != 99
    {
        std::cout << "Do something" << std::endl;
        select = top_menu();
    }
    
    std::cout << "Good bye!" << std::endl;
    
    return 0;
}
