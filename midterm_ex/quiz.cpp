#include <iostream>
#include <stdlib.h>
#include <cstring>

int main(int argc, char** argv)
{
    char buff[1000];
    
    std::cout << "Enter the expression. " << std::endl;
    
    std::cin.getline(buff, 1000);
    
    std::cout << (int)buff[0] << std::endl; 
    // 111+444
    //int oprnd_1 = (buff[0]-'0')*100 + (buff[1]-'0')*10 + (buff[2]-'0');
    //int oprnd_2 = (buff[4]-'0')*100 + (buff[5]-'0')*10 + (buff[6]-'0'); 
    
    char buff_1[100];
    char buff_2[100];
    
    strncpy(buff_1, buff, 3);
    strncpy(buff_2, buff+4, 3);
    
    int oprnd_1 = atoi(buff_1);
    int oprnd_2 = atoi(buff_2);
    
    switch(buff[3])
    {
        case '+':
        std::cout << oprnd_1 + oprnd_2 << std::endl;
        break;
        case '-':
        std::cout << oprnd_1 - oprnd_2 << std::endl;
        break;
        case '*':
        std::cout << oprnd_1 * oprnd_2 << std::endl;
        break;
        case '/':
        std::cout << oprnd_1 / oprnd_2 << std::endl;
        break;
        default:
        break;
    }
    return 0;
}