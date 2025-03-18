
#ifndef SpielMechaniken_h
#define SpielMechaniken_h
#include "Arduino.h"

class SpielMechaniken {

  public:
    void Zug(int col, int x);
    bool LetzterSpielzug(int spieler);
    void MonitorSpielfeld();
    void DigitalSpielfeld();


}

#endif