#include "mbed.h"
#include "Pinned.h"

using namespace Particula;

int main(void){
    DigitalOut Pin(D6);
    Pinned Device(D7, D8);
    //Device2(D10, D11);
    mbed::Serial pc(USBTX, USBRX);
    //Device.enable();
    //Pin.write(1);

    //Device.enable();
    
    pc.printf("Start\r\n");
        
    while(true){
        //Device2.evaluate();
        Device.enable();
        pc.printf("Enabled\r\n");
        Pin.write(1);
        wait_us(10000);
        Device.disable();
        pc.printf("Disabled\r\n");
        Pin.write(0);
    }
}