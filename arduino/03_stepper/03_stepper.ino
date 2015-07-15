/*
Adafruit Arduino - Lesson 16. Stepper
*/
 
#include <Stepper.h>
 
// Using these pins instead of pin number from Adafruit tutorial (which I commented out)
int in1Pin = 0; //2;
int in2Pin = 1; //3;
int in3Pin = 2; //4;
int in4Pin = 3; //5;
int readPin = 4; //12;
 
Stepper motor(512, in1Pin, in2Pin, in3Pin, in4Pin);  

void setup()
{
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);

  pinMode(readPin, INPUT);
  
//  Serial.begin(115200);
  motor.setSpeed(20);
}
 
void loop()
{
//  if (Serial.available()) {
//    Serial.println(digitalRead(readPin));
//  }
  if (digitalRead(readPin)==1) {
    motor.step(32);
  }
  delay(1000);
}
