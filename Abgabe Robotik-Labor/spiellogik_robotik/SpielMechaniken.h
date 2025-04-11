
#ifndef SpielMechaniken_h
#define SpielMechaniken_h
#include "Arduino.h"

#define ROWS 6
#define COLUMNS 7
#define EMPTY 0

class SpielMechaniken {

  public:
    //Spielzug.cpp
    void Zug(int col, int spieler);
    bool richtigerZug(int col);
    void zurueckZug(int col);
    //Ueberprüfung.cpp
    bool letzterSpielzug(int spieler);
    //Spielfeld.cpp
    void MonitorSpielfeld();
    void DigitalSpielfeld();

  private:
    int board[ROWS][COLUMNS];  

};

extern SpielMechaniken spielmechaniken;

#endif
