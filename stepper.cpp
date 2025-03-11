#include "Arduino.h"
#include "stepper.h"
stepper::stepper(bool enablePin,int stepPin,bool dirPin) {
  pinMode(enablePin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  
  _enablePin = enablePin;
  _stepPin = stepPin;
  _dirPin = dirPin;
  
  _steps = 0;
  currentPosition = 0;  // Startpunkt Parkplatz
  digitalWrite(_enablePin, HIGH);  // Stepper ist aus    
  digitalWrite(_dirPin, HIGH); // fahrtrichtung nach links richtung Trichter
}

void stepper::moveTo(int col) {
  int calculateSteps(int col);
  digitalWrite(_enablePin, LOW);  // Motor an 
  if (currentPosition =! 0) {
    digitalWrite(_dirPin, LOW); // Richtung Parkplatz
    for (int stepCounter = 0; stepCounter < _steps; stepCounter++) {
      digitalWrite(_stepPin, HIGH);
      delayMicroseconds(700);
      digitalWrite(_stepPin, LOW);
      delayMicroseconds(700);
    }
    currentPosition = 0;
  }
  else {
    digitalWrite(_dirPin, HIGH);  // Richtung Trichter
    for (int stepCounter = 0; stepCounter < _steps; stepCounter++) {
      digitalWrite(_stepPin, HIGH);
      delayMicroseconds(700);
      digitalWrite(_stepPin, LOW);
      delayMicroseconds(700);
    }
    currentPosition = _steps;
  }
  return currentPosition;
  digitalWrite(_enablePin, HIGH);
}

int stepper::calculateSteps(int col) {
  if (col == 0) {
    _steps = currentPosition;
  }
  else if (col == 1) {
    _steps = 1345;
  }
  else if (col == 2) {
    _steps = 1200;
  }
  else if (col == 3) {
    _steps = 1050;
  }
  else if (col == 4) {
    _steps = 873;   
  }
  else if (col == 5) {
    _steps = 745;   
  }
  else if (col == 6) {
    _steps = 592;   
  }
  else if (col == 7) {
    _steps = 435;   
  }
  return _steps;
}
