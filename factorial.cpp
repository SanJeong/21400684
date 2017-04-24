#include <iostream>

int factorial(int a);
int a;
int main(){
    int result;
    std::cin >> a;
    
    if(a>=0){
        result = factorial(a);
        std::cout<<a<<"!= "<< result <<std::endl;
        
    }else{
        std::cout<<"Wrong input!"<<std::endl;
    }
}

int factorial(int a){
    int i;
    int result = 1;
    for(i=1;i<=a;i++)
        result = result * i;
    return result;
    }
