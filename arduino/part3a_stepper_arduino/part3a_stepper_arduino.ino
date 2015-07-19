/*
Adafruit Arduino - Lesson 16. Stepper
Modified to take input from ESP8266 instead of user
*/
 
#include <Stepper.h>
 
int in1Pin = 12;
int in2Pin = 11;
int in3Pin = 10;
int in4Pin = 9;
int readPin = 8; // NYL: new line, not in original Adafruit Tutorial
 
Stepper motor(512, in1Pin, in2Pin, in3Pin, in4Pin);  

void setup()
{
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);

  pinMode(readPin, INPUT); // NYL: new line, beginning listening for input on readPin
  
  motor.setSpeed(20);
}
 
void loop()  // NYL: changed this to read input from ESP, then proceed at 32 steps every second
{
  if (digitalRead(readPin)==1) {
    motor.step(32);
  }
  delay(1000);
}


