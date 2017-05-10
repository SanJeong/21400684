#include "ev3dev.h"

using namespace ev3dev;
int main(){
    
    
    
    motor::motor(address_type address)
    {
        connect({{ "outA", { OUTPUT_A[] } }});
    }
}