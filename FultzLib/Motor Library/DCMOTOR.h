#ifndef DCMOTOR_H
#define DCMOTOR_H

#include <Arduino.h>

class DCMOTOR{
	public:
	DCMOTOR(uint8_t pwmPin, uint8_t dirPin1, uint8_t dirPin2, uint8_t enablePin);
	DCMOTOR();
	void motorEnable(void);
	void motorDisable(void);
	void motorBrake(void);
	void motorRunCW(uint8_t pwmIn);
	void motorRunCCW(uint8_t pwmIn);
	private:
	uint8_t pwmPin;
	uint8_t dirPin1;
	uint8_t dirPin2;
	uint8_t enablePin;

	uint8_t pwmVal;

	bool dir1State;
	bool dir2State;
	bool enableState_n;
};
#endif
