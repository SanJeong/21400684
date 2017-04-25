#include <iostream>

int i;
int num1[5] = {1,2,3,4,5};
int num2[5];


main(){
    for (i=0;i<5;i++){
        num2[i]=num1[i];
    }
    for (i=0;i<5;i++)
{
    std::cout<<num2[i]<<std::endl;
}
    
}
