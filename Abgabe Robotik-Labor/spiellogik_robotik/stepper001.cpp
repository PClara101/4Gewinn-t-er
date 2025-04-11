#include "Arduino.h"
#include "stepper001.h"
#include <Servo.h>;

#define ENABLE_PIN 4
#define STEP_PIN 2
#define DIR_PIN 3



stepper Stepper001(ENABLE_PIN, STEP_PIN, DIR_PIN);
Servo servo;

// Initialisierung des Steppers
stepper::stepper(int enablePin,int stepPin,int dirPin) {  // geändert
  // Zahl, Zahl, Zahl
  // true (jeder Wert ungleich 0)/ false, Zahl, true / false
  pinMode(enablePin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  
  _enablePin = enablePin;  // ein- und ausschalten des Motors
  _stepPin = stepPin;   // Schritte
  _dirPin = dirPin;   // Richtung
  
  // Startwerte setzen
  _steps = 0;   // _steps speichert die Anazhl der Schritte
  currentPosition = 0;  // Startpunkt Parkplatz

  digitalWrite(_enablePin, HIGH);  // Stepper ist aus    richtig, dass aus??
  digitalWrite(_dirPin, HIGH); // Fahrtrichtung nach links Richtung Trichter
}

void stepper::moveTo(int col) { 
  // moveTo(int col) sorgt dafür, dass Schrittmotor bestimmte Schrittanzahl fährt
  // je nachdem, welcher Wert für col übergeben
  _steps = calculateSteps(col);  // berechnet, wie viele Schritte für Zielposition col benötigt
  digitalWrite(_enablePin, LOW);  // Motor an 
  
  // Falls Stepper nicht auf Startposition -> zurückfahren: 
  if (currentPosition != 0) {
    digitalWrite(_dirPin, LOW); // Richtung Parkplatz
   // Stepper fährt _steps Schritte zurück:
    for (int stepCounter = 0; stepCounter < _steps; stepCounter++) {
      digitalWrite(_stepPin, HIGH);
      delayMicroseconds(700);
      digitalWrite(_stepPin, LOW);
      delayMicroseconds(700);
    }
    currentPosition = 0;  // wird auf 0 gesetzt
  }

  // falls Stepper auf Startposition -> vorwärts fahren (zu Trichterposition): 
  else {
    digitalWrite(_dirPin, HIGH);  // Richtung Trichter
   // Stepper fährt _steps Schritte vorwärts:
    for (int stepCounter = 0; stepCounter < _steps; stepCounter++) {
      digitalWrite(_stepPin, HIGH);
      delayMicroseconds(700);
      digitalWrite(_stepPin, LOW);
      delayMicroseconds(700);
    }
    currentPosition = _steps;  // wird auf _steps aktualisiert
  }

  digitalWrite(_enablePin, HIGH);  // Motor ausschalten
  return currentPosition;  // !!return beendet die Funktion sofort!!
}

// definiere die Funktion calculateSteps(int col)
//(berechnet, wie viele Schritte Motor ausführen soll, um bestimmte Position (col) zu erreichen)
int stepper::calculateSteps(int col) {
  if (col == -1) {
    _steps = currentPosition; // es passiert nichts
  }
  else if (col == 0) {
    _steps = 1345;
  }
  else if (col == 1) {
    _steps = 1200;
  }
  else if (col == 2) {
    _steps = 1050;
  }
  else if (col == 3) {
    _steps = 873;   
  }
  else if (col == 4) {
    _steps = 745;   
  }
  else if (col == 5) {
    _steps = 592;   
  }
  else if (col == 6) {
    _steps = 435;   
  }
  return _steps;
}
// Funktion bewegt Servo hin und zurück:
void stepper::push() {
  Serial.println("Servo dreht sich hin");  // Ausgabe zur Kontrolle
  // Servo dreht sich von 160° auf 25°:
  for (int i = 164; i>=25; i--) {
    servo.write(i);
    delay(30);
  }
  Serial.println("Servo dreht sich zurück");  // Ausgabe zur Kontrolle
  // Servo dreht sich zurück von 25° auf 160°:
  for (int i = 25; i <= 164; i++) {
    servo.write(i);
    delay(30);
  }
}
