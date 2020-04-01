#pragma once
#include "mbed.h"

namespace PinnedOut{
    class Pinned{
        public:
            Pinned(PinName ioPins[],bool outputPins[], unsigned int sizePins);
            Pinned(PinName ioPin, bool outputPin);
            Pinned(void);
            void enable(void);
            void disable(void);
            void forceSoftware(void);
            void openDrain(bool OpenDrain[]);
            bool statusForced(void);
            bool status(void);
        private:
            void setOut(bool hardeware, bool enabled);
            bool output[];
            DigitalInOut io[];
            bool forced = false;
            bool statusOutput = false;
            unsigned int size = 0;
    };
}