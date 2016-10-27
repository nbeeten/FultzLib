#include "MOTOR.h"

class MOTOR {
	public:
		MOTOR::MOTOR(uint8_t pwmPin, uint8_t dirPin1, uint8_t dirPin2, uint8_t enablePin){
			this.pwmPin = pwmPin;
			this.dirPin1 = dirPin1;
			this.dirPin2 = dirPin2;
			this.enablePin = enablePin;
			pinMode(pwmPin, OUTPUT);
			pinMode(dirPin1, OUTPUT);
			pinMode(dirPin2, OUTPUT);
			pinMode(enablePin, OUTPUT);
		}
		MOTOR::MOTOR () { //default configuration
			this.pwmPin = 4;
			this.dirPin1 = 6;
			this.dirPin2 = 5;
			this.enablePin = 3;
			pinMode(pwmPin, OUTPUT);
			pinMode(dirPin1, OUTPUT);
			pinMode(dirPin2, OUTPUT);
			pinMode(enablePin, OUTPUT);
		}
		uint8_t pwmPin;
		uint8_t dirPin1;
		uint8_t dirPin2;
		uint8_t enablePin;
		
		uint8_t pwmVal;
		
		bool dir1State;
		bool dir2State;
		bool enableState_n;
		
		void motorEnable(void) {
			return enableState_n = false;
			digitalWrite(enablePin, enableState_n);
		}
		
		void motorDisable(void) {
			return enableState_n = true;
			digitalWrite(enablePin, enableState_n);
		}
		
		void motorBrake(void){
			dir1State = true;
			dir2State = true;
			digitalWrite(dir1Pin, dir1State);
			digitalWrite(dir2Pin, dir2State);
			return;
		}
		
		void motorRunCW(uint8_t pwmIn){
			dir1State = true;
			dir2State = false;
			digitalWrite(dir1Pin, dir1State);
			digitalWrite(dir2Pin, dir2State);
			analogWrite(pwmPin, pwmIn);
			return;
		}
		
		void motorRunCCW(uint8_t pwmIn){
			dir1State = false;
			dir2State = true;
			digitalWrite(dir1Pin, dir1State);
			digitalWrite(dir2Pin, dir2State);
			analogWrite(pwmPin, pwmIn);
			return;
		}
}