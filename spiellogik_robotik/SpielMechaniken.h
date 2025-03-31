
#ifndef SpielMechaniken_h
#define SpielMechaniken_h
#include "Arduino.h"

class SpielMechaniken {

  public:
    //Spielzug.cpp
    void Zug(int col, int x);
    bool richtigerZug(int col);
    void zurueckZug(int col);
    //Ueberprüfung.cpp
    bool LetzterSpielzug(int spieler);
    //Spielfeld.cpp
    void MonitorSpielfeld();
    void DigitalSpielfeld();

}

#endif
