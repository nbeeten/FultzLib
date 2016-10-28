#include <Arduino.h>

/*This program will show you an exaple of how to control external motors with your
 * XBOX 360 controller. You can use this as a template for your final robot
 *
 * Created by Nathan Beeten 27/10/15
 */

#include <XBOXRECV.h> //import the wireless coms library
#include <DCMOTOR.h> //import the motor control library

USB Usb; //Create Objects for program to use
XBOXRECV Xbox(&Usb);
uint8_t pwmPin = 9;
uint8_t dirPin1 = 8;
uint8_t dirPin2 = 7;
uint8_t enablePin = 6;
DCMOTOR Motor;
int16_t hatYInput;
int16_t intensity;
bool motorDir;

uint8_t pwmMap(uint16_t input);

uint8_t xboxPort = 0;//The port on the receiver that the controller is connected to

void setup() {//The setup code initializes the rest of your program
  Serial.begin(115200);
  if (Usb.Init() == -1) {//check whether the USB connects
    Serial.print(F("\r\nOSC did not start"));
    while (1); //Stop the program if we didn't connect
  }
  Motor.attach(pwmPin, dirPin1, dirPin2, enablePin);
  Motor.motorEnable();
  Serial.print(F("\r\nXbox Wireless Receiver Library Started"));
}

void loop() {// The loop runs repeatedly from top to bottom after the setup
  Usb.Task();
  if(Xbox.XboxReceiverConnected)  {
    if(Xbox.Xbox360Connected[xboxPort]){
      hatYInput = Xbox.getAnalogHat(LeftHatY, xboxPort);
      intensity = abs(hatYInput);
      if (Xbox.getAnalogHat(LeftHatY, xboxPort) > 7500 || Xbox.getAnalogHat(LeftHatY, xboxPort) < -7500) {
        Serial.print(F("LeftHatY: "));
        Serial.print(Xbox.getAnalogHat(LeftHatY, xboxPort));
        Serial.print("\n");
      }
      if(hatYInput > 0){
        Motor.motorRunCCW(pwmMap(intensity));
      } else if (hatYInput < 0 ){
        Motor.motorRunCW(pwmMap(intensity));
      } else {
        Motor.motorBrake();
      }
    }
  }
}

uint8_t pwmMap(uint16_t input){
  return input/128;
}
