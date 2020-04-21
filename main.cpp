#include "mbed.h"
#include "Pinned.h"

int main(void){
    DigitalOut Pin(D6);
    PinnedOut::Pinned Device(D7, D8);
    mbed::Serial pc(USBTX, USBRX);
    Device.enable();
    Pin.write(1);

    Device.enable();

    while(true){
        Device.enable();
        pc.printf("Enabled\r\n");
        Pin.write(1);
        wait(1);
        Device.disable();
        pc.printf("Disabled\r\n");
        Pin.write(0);
    }
}