#ifndef STEPPER_H
#define STEPPER_H

#include <Arduino.h>

class STEPPER {
    public:
        STEPPER(); //default constructor
        void attach(uint8_t dirPin, uint8_t stepPin); //explicit constructor
        void step(); //take one step
        void step(bool dir); //take one step
        void stepSpd(uint16_t freq, bool dir); //takes steps at a certain speed
        void stepSpd(uint16_t freq); //takes steps at a certain speed
        void changeDir(bool dir); //changes rotation direction

    private:
        bool dir; //rotation direction
        uint8_t dirPin; //controls rotation direction
        uint8_t stepPin; //tells motor to take a step
};

#endif
