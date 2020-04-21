#pragma once
#include "mbed.h"

namespace PinnedOut{
    class Pinned{
        public:
            Pinned(PinName OutPin, PinName InPin);
            void enable(void);
            void disable(void);
            void forceSoftware(void);
            bool statusForced(void);
            bool status(void);
            void evaluate(void);
        private:
            DigitalOut Output = DigitalOut(D0);
            DigitalIn Input = DigitalIn(D1);
            bool forced = false;
            bool statusOutput = false;
    };
}