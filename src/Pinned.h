#pragma once
#include "mbed.h"

namespace PinnedOut{
    class Pinned{
        public:
            Pinned(PinName ioPin);
            void enable(void);
            void disable(void);
            void forceSoftware(void);
            void setInput(PinName ioPin);
            bool statusForced(void);
            bool status(void);
            void evaluate(void);
        private:
            DigitalOut * Output;
            DigitalIn * Input;
            bool forced = false;
            bool statusOutput = false;
            unsigned int sizeOut = 0;
            bool setIn = false;
    };
}