#include "mbed.h"
#include "Pinned.h"

namespace PinnedOut{
    Pinned::Pinned(PinName ioPins[],bool outputPins[], unsigned int sizePins){
        output = outputPins;
        size = sizePins;
        for(unsigned int i = 0; i< size; i++ ){
            io[i] = DigitalInOut(ioPins[i]);
            io[i].input();
            if(output[i])io[i].output();
        }
    }
    Pinned::Pinned(PinName ioPin, bool outputPin){
        io[0] = DigitalInOut(ioPin);
        output[0] = outputPin;
        size = 1;
        io[0].input();
        if(outputPin)io[0].output();
    }
    Pinned::Pinned(){}
    void Pinned::enable(void){
        if(forced)outEnable(false, true);
    }
    void Pinned::disable(void){
        if(forced)outEnable(false, false);
    }
    void Pinned::forceSoftware(void){
        forced = !forced;
    }
    bool Pinned::statusForced(void){
        return forced;
    }
    bool Pinned::status(void){
        return statusOutput;
    }

    void openDrain(bool openDrain[]){
        for(unsigned int i = 0; i<size; i++ ){
            this->io[i].mode(PullDefault);
            if(output[i]&&opendDrain[i])this->io[i].mode(OpenDrain);
        }
    }

    void Pinned::setOut(bool hardware, bool enabled){
        if(forced && !hardware || !forced && hardeware){
            for(unsigned int i = 0; i<size; i++ ){
                if(output[i])this->io[i] = enabled;
            }
            statusOutput = enabled;
        }
    }

}