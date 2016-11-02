#include <Arduino.h>
#include "STEPPER.h"
#include <Servo.h>

Servo motor1;

#define DIRPIN1 2
#define STEPPIN1 3

STEPPER stepper1;

void setup() {
    stepper1.attach(DIRPIN1, STEPPIN1);

    for (int i = 0; i < 5400; i++) {
        stepper1.step();
        delay(1);
    }
}

void loop() {

}
