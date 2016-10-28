#include "STEPPER.h"

STEPPER::STEPPER() {
}

void STEPPER::attach(uint8_t dirPin, uint8_t stepPin) {
    this->dirPin = dirPin;
    this->stepPin = stepPin;
    pinMode(dirPin, OUTPUT);
    pinMode(stepPin, OUTPUT);
    dir = 0;
}

/** Takes a certain number of steps steps at a fixed frequency
    @param steps Number of steps to take
    @param dir Direction to rotate
*/
void STEPPER::step() {
    digitalWrite(stepPin, LOW);
    digitalWrite(dirPin, dir);
    digitalWrite(stepPin, HIGH);
    delay(1);
    digitalWrite(stepPin, LOW);
}

/** Takes a certain number of steps steps at a fixed frequency
    @param steps Number of steps to take
*/
void STEPPER::step(bool dir) {
    digitalWrite(stepPin, LOW);
    changeDir(dir);
    digitalWrite(dirPin, dir);
    digitalWrite(stepPin, HIGH);
    delay(1);
    digitalWrite(stepPin, LOW);
}

void STEPPER::stepSpd(uint16_t freq, bool dir) {
    changeDir(dir);
    digitalWrite(dirPin, dir);
    tone(stepPin,freq);
}

void STEPPER::stepSpd(uint16_t freq) {
    digitalWrite(dirPin, dir);
    tone(stepPin, freq);
}

void STEPPER::changeDir(bool dir) {
    this->dir = dir;
}
