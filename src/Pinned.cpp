#include "mbed.h"
#include "Pinned.h"

namespace PinnedOut{
    Pinned::Pinned(PinName OutPin, PinName InPin){
        Output = DigitalOut(OutPin);
        Input = DigitalIn(InPin);
    }

    void Pinned::enable(void){
        forced = true;
        statusOutput = true;
        this->evaluate();
    }

    void Pinned::disable(void){
        forced = true;
        statusOutput = false;
        this->evaluate();
    }

    void Pinned::forceSoftware(void){
        forced = false;
    }

    bool Pinned::statusForced(void){
        return forced;
    }

    bool Pinned::status(void){
        return statusOutput;
    }

    void Pinned::evaluate(void){
        Output = 1;
        /* if(forced){
            Output = statusOutput;
        }else{
            statusOutput=Input;
            Output = statusOutput;
        } */
    }

}