/*
  STEPPER
  > Steuererung des Steppermotors 
  > verwendet stepper Klasse
    - stepper.cpp und stepper.h einbinden
*/


#include "stepper.h"

#define ENABLE_PIN 4  // wenn HIGH, Motor aus
#define STEP_PIN 2    //
#define DIR_PIN 3     //Richtung (high=richtung trichter, low=richtung parkplatz)

int col;

stepper stepper(ENABLE_PIN, STEP_PIN, DIR_PIN);

void setup() {
  randomSeed(analogRead(2));
  col = random(1,8);
  stepper.moveTo(col);
  delay(2000);
  stepper.moveTo(0);  // fährt zurück zum Parkplatz
}

void loop() {
  // put your main code here, to run repeatedly:

}
