#pragma once
#include "mbed.h"

namespace Particula{
    class Pinned{
        public:
            Pinned(PinName OutPin, PinName InPin);
            void enable(void);
            void disable(void);
            void force_software(void);
            bool status_forced(void);
            bool status(void);
            void evaluate(void);
        private:
            DigitalOut output = DigitalOut(D0);
            DigitalIn input = DigitalIn(D1);
            bool forced = false;
            bool status_output = false;
    };
}