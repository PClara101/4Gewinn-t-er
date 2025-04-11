#include "Arduino.h"
#include "LedKlasse.h"

// Constructer erstellt LED Objekte
 LedKlasse::LedKlasse(int pin) {
  pinMode(pin, OUTPUT);
  _pin = pin;
  stateLed = false;
}

// Blinken in einer bestimmten Geschwindigkeit
void LedKlasse::blinken(int blinkRate) {
  digitalWrite(_pin, HIGH);
  delay(blinkRate);
  digitalWrite(_pin, LOW);
  delay(blinkRate);
}

// ändern des Zustands der LED 
void LedKlasse::toggle() {
  stateLed = !stateLed;
  digitalWrite(_pin, stateLed);
}
