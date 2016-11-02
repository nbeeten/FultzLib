////////////////////////////////////////////////////////////////////////////////////////////
/*
 *This library was written by Nathan Beeten on October 28, 2016
 *It was last updated on October 31, 2016
 *This library was created for the Harry Fultz Institute's Robotics Club
 */
////////////////////////////////////////////////////////////////////////////////////////////
#include "DCMOTOR.h"

	DCMOTOR::DCMOTOR () {} //default Cunstructor to create the object

	void DCMOTOR::attach(uint8_t pwmPin, uint8_t dirPin1, uint8_t dirPin2, uint8_t enablePin){ //method to set up the object
		/////////////////////////set driver pins to the ones sepecified/////////////////////////
		this->pwmPin = pwmPin;
		this->dirPin1 = dirPin1;
		this->dirPin2 = dirPin2;
		this->enablePin = enablePin;
		///////////////////////////Initialize all the pins to outputs///////////////////////////
		enableState = false;
		pinMode(pwmPin, OUTPUT);
		pinMode(dirPin1, OUTPUT);
		pinMode(dirPin2, OUTPUT);
		pinMode(enablePin, OUTPUT);

		state = disabled;
	}

	void DCMOTOR::motorEnable(void) {//This method allows the motors to move
		enableState = true;
		digitalWrite(enablePin, enableState);
		return;
	}

	void DCMOTOR::motorDisable(void) {//This method forces the motors to stop
		enableState = false;
		digitalWrite(enablePin, enableState);
		return;
	}

	void DCMOTOR::motorBrake(void) {//Forces the motors to stop without disabling them
		dir1State = false;
		dir2State = false;
		digitalWrite(dirPin1, dir1State);
		digitalWrite(dirPin2, dir2State);
		return;
	}

	void DCMOTOR::motorRunCW(uint8_t pwmIn) {//Run the motor Clockwise (nominally backwards)
		dir1State = true;
		dir2State = false;
		digitalWrite(dirPin1, dir1State);
		digitalWrite(dirPin2, dir2State);
		analogWrite(pwmPin, pwmIn);
		return;
	}

	void DCMOTOR::motorRunCCW(uint8_t pwmIn) { //Run the motor Counter-Clockwise (nominally forwards)
		dir1State = false;
		dir2State = true;
		digitalWrite(dirPin1, dir1State);
		digitalWrite(dirPin2, dir2State);
		analogWrite(pwmPin, pwmIn);
		return;
	}

	DCMOTOR::MotorState DCMOTOR::getState(void){//this returns the current state of the motor
		return state;
	}


	; //This semicolon makes everything else work. Don't ask why
