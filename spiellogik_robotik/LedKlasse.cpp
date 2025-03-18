#include "Arduino.h"
#include "LedKlasse.h"

LedKlasse::LedKlasse(int pin) {
  pinMode(pin, OUTPUT);
  _pin = pin;
  stateLed = false;
}

void LedKlasse::blinken(int blinkRate) {
  digitalWrite(_pin, HIGH);
  delay(blinkRate);
  digitalWrite(_pin, LOW);
  delay(blinkRate);
}

void LedKlasse::toggle() {
  stateLed = !stateLed;
  digitalWrite(_pin, stateLed);
}
