#include "STEPPER.h"

/** Default constructor
*/
STEPPER::STEPPER() {
}

/** Initialize the pins for the stepper motor
    @param dirPin Pin for controlling direction
    @param stepPin Pin for taking steps
*/
void STEPPER::attach(uint8_t dirPin, uint8_t stepPin) {
    this->dirPin = dirPin;
    this->stepPin = stepPin;
    pinMode(dirPin, OUTPUT);
    pinMode(stepPin, OUTPUT);
    dir = 0;
}

/** Takes a single step
*/
void STEPPER::step() {
    //Ensure the output is low
    digitalWrite(stepPin, LOW);
    //set direction to correct direction
    digitalWrite(dirPin, dir);
    //Toggle output
    digitalWrite(stepPin, HIGH);
    //
    digitalWrite(stepPin, LOW);
}

/** Takes a single step
    @param dir New direction value
*/
void STEPPER::step(bool dir) {
    digitalWrite(stepPin, LOW);

    changeDir(dir);

    digitalWrite(dirPin, dir);

    digitalWrite(stepPin, HIGH);

    digitalWrite(stepPin, LOW);
}

/** Drives the stepPin output at the desired frequency in a new direction
    @param freq Frequency from 31-65535Hz
    @param dir New direction value
*/
void STEPPER::stepSpd(uint16_t freq, bool dir) {

    changeDir(dir);

    digitalWrite(dirPin, dir);

    tone(stepPin,freq);
}


/** Drives the stepPin output at the desired frequency
    @param freq Frequency from 31-65535Hz
*/
void STEPPER::stepSpd(uint16_t freq) {
    //set direction
    digitalWrite(dirPin, dir);
    //output a square wave at the desired frequency
    tone(stepPin, freq);
}

/** Changes the direction variable
    @param dir New direction value
*/
void STEPPER::changeDir(bool dir) {
    this->dir = dir;
}
