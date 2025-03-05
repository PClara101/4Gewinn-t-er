#ifndef LedKlasse_h
#define LedKlasse_h
#include "Arduino.h"

class LedKlasse {

  public:
    LedKlasse(int pin);
    void blinken(int blinkRate);
    void toggle();
  private:
    int _pin;
    bool stateLed;
};
#endif