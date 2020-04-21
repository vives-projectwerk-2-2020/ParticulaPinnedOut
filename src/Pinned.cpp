#include "mbed.h"
#include "Pinned.h"

namespace PinnedOut{
    Pinned::Pinned(PinName ioPin){
        DigitalOut newOut(ioPin);
        Output = &newOut;
    }

    void Pinned::enable(void){
        forced = true;
        statusOutput = true;
        evaluate();
    }

    void Pinned::disable(void){
        forced = true;
        statusOutput = false;
        evaluate();
    }

    void Pinned::forceSoftware(void){
        forced = false;
    }

    void Pinned::setInput(PinName ioPin){
        setIn = true;
        DigitalIn newIn(ioPin);
        Input = &newIn;
    }

    bool Pinned::statusForced(void){
        return forced;
    }

    bool Pinned::status(void){
        return statusOutput;
    }

    void Pinned::evaluate(void){
        if(forced){
            if(statusOutput) Output->write(1);
            else Output->write(0);
        }else{
            if((Input->read()==1) && (setIn = true)) Output->write(1);
            else Output->write(0);
        }
    }

}