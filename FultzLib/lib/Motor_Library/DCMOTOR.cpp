#include "DCMOTOR.h"


	DCMOTOR::DCMOTOR () {}
	void DCMOTOR::attach(uint8_t pwmPin, uint8_t dirPin1, uint8_t dirPin2, uint8_t enablePin){
		this->pwmPin = pwmPin;
		this->dirPin1 = dirPin1;
		this->dirPin2 = dirPin2;
		this->enablePin = enablePin;
		pinMode(pwmPin, OUTPUT);
		pinMode(dirPin1, OUTPUT);
		pinMode(dirPin2, OUTPUT);
		pinMode(enablePin, OUTPUT);
	}

	void DCMOTOR::motorEnable(void) {
		enableState = true;
		digitalWrite(enablePin, enableState);
		return;
	}

	void DCMOTOR::motorDisable(void) {
		enableState = false;
		digitalWrite(enablePin, enableState);
		return;
	}

	void DCMOTOR::motorBrake(void){
		dir1State = false;
		dir2State = false;
		digitalWrite(dirPin1, dir1State);
		digitalWrite(dirPin2, dir2State);
		return;
	}

	void DCMOTOR::motorRunCW(uint8_t pwmIn){
		dir1State = true;
		dir2State = false;
		digitalWrite(dirPin1, dir1State);
		digitalWrite(dirPin2, dir2State);
		analogWrite(pwmPin, pwmIn);
		return;
	}

	void DCMOTOR::motorRunCCW(uint8_t pwmIn){
		dir1State = false;
		dir2State = true;
		digitalWrite(dirPin1, dir1State);
		digitalWrite(dirPin2, dir2State);
		analogWrite(pwmPin, pwmIn);
		return;
	}
	;
