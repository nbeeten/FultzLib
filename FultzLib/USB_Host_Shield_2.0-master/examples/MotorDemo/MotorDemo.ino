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
DCMOTOR Motor(pwmPin, dirPin1, dirPin2, enablePin);
int16_t hatYInput;

uint8_t xboxPort = 0;//The port on the receiver that the controller is connected to

void setup() {//The setup code initializes the rest of your program
  Serial.begin(115200);
  if (Usb.Init() == -1) {//check whether the USB connects
    Serial.print(F("\r\nOSC did not start"));
    while (1); //Stop the program if we didn't connect
  }
  Motor.motorEnable();
  Serial.print(F("\r\nXbox Wireless Receiver Library Started"));
}

void loop() {// The loop runs repeatedly from top to bottom after the setup
  Usb.Task();
  if(Xbox.XboxReceiverConnected)  {
    if(Xbox.Xbox360Connected(xboxPort)){
      hatYInput = Xbox.getAnalogHat(LefthatY, xboxPort);
    }
  }
}