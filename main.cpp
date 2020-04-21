#include "mbed.h"
#include "Pinned.h"

int main(void){
    DigitalOut Pin(D7);
    Pin.write(1);
    PinnedOut::Pinned Device(D8);
    while(1){
        Device.enable();
        Device.evaluate();
        Pin.write(1);
    }
}