/*
  STEPPER
  > Steuererung des Steppermotors 
  > verwendet stepper Klasse
    - stepper.cpp und stepper.h einbinden


  - servo hinzugefügt
*/


#include "stepper.h"
#include <Servo.h>;

//Pins Stepper
#define ENABLE_PIN 4  // wenn HIGH, Motor aus
#define STEP_PIN 2    //
#define DIR_PIN 3     //Richtung (high=richtung trichter, low=richtung parkplatz)

//Pin Servo
#define SERVO 7

int col;

stepper stepper(ENABLE_PIN, STEP_PIN, DIR_PIN);
Servo servo;

void setup() {
  Serial.begin(9600);
  servo.attach(SERVO);

  randomSeed(analogRead(2));
  col = random(1,8);
  Serial.println(col);

  stepper.moveTo(col);
  delay(100);
  push();
  delay(100); 
  stepper.moveTo(0); // fährt zurück zum Parkplatz
}

void push() {
  for (int i = 0; i<180; i++) {
    servo1.write(i);
    delay(15);
  }
  for (int i = 180; i >= 0; i--) {
    servo1.write(i);
    delay(15);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}

void loop() {
  // put your main code here, to run repeatedly:

}
