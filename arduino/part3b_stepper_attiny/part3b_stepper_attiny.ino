/*
Adafruit Arduino - Lesson 16. Stepper
Modified to take input from ESP8266 instead of user
*/
 
#include <Stepper.h>
 
// NYL: changed pin number to match that in ATtiny
int in1Pin = 0; //12;
int in2Pin = 1; //11;
int in3Pin = 2; //10;
int in4Pin = 3; //9;
int readPin = 4; //8; 
 
Stepper motor(512, in1Pin, in2Pin, in3Pin, in4Pin);  

void setup()
{
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);

  pinMode(readPin, INPUT);
  
  motor.setSpeed(20);
}
 
void loop() 
{
  if (digitalRead(readPin)==1) {
    motor.step(32);
  }
  delay(1000);
}


