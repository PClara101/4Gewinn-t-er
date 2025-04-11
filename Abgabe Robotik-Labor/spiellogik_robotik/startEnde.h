/*
  Headerdatei für die Kommuikation am Anfang und am Ende des Spiels
*/

#ifndef startEnde_h
#define startEnde_h
#include "Arduino.h"

class startEnde{
  
  public: 
    void start();
    void ende(int gewinnter);
  // die folgenden Funktionen werden von start() und ende() verwendet:
    void soundStart();
    void losen();
    void accelerando();
    void ritardando();
    void soundGameover();
    void soundVictory();
    void soundTie();
  
};

#endif
