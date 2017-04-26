#include <iostream>
#include <cstring>
#include <stdio.h>

int main(int argc, char**argv){
    int i, div, score[5];
    char grade[5];
    std::cout << "Input 5 scores:" <<std::endl;
    for(i=0;i<5;i++){
        std::cin >> score[i];
        div = score[i]/10;
        switch(div){
            case 10:
            case 9: grade[i] = 'A';
                break;
            case 8: grade[i]='B';
                break;
            case 7: grade[i]='C';
                break;
            case 6: grade[i]='D';
                break;
            case 5: grade[i] ='E';
                break;
            default: grade[i] ='F';
            break;
            
    }
    }
    for(i=0;i<5;i++){
        printf("[%2d](%2d/100) : %c\n",i,score[i],grade[i]);
    
    }
        
    
}