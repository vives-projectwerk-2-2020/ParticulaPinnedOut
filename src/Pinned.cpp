#include "mbed.h"
#include "Pinned.h"

namespace Particula{
    Pinned::Pinned(PinName out_pin, PinName in_pin){
        output = DigitalOut(out_pin);
        input = DigitalIn(in_pin);
    }

    void Pinned::enable(void){
        forced = true;
        output.write(0);
        status_output = true;
        this->evaluate();
    }

    void Pinned::disable(void){
        forced = true;
        output.write(1);
        status_output = false;
        this->evaluate();
    }

    void Pinned::force_software(void){
        forced = false;
    }

    bool Pinned::status_forced(void){
        return forced;
    }

    bool Pinned::status(void){
        return status_output;
    }

    void Pinned::evaluate(void){
        if(forced){
            return;
        }else{
            status_output = (bool) input;
            if(input){
                output.write(1); 
            }else{
                output.write(0);
            }
        } 
    }

}