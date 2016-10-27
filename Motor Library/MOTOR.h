#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class MOTOR{
	public:
	MOTOR(uint8_t pwmPin, uint8_t dirPin1, uint8_t dirPin2, uint8_t enablePin);
	MOTOR();
	void motorEnable(void);
	void motorDisable(void);
	void motorBrake(void);
	void motorRunCW(uint8_t pwmIn);
	void motorRunCCW(uint8_t pwmIn);
}