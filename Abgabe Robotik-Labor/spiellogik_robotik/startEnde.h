#ifndef startEnde_h
#define startEnde_h
#include "Arduino.h"

class startEnde{
  
  public: 
    void start();
    void ende(int gewinnter);
    void soundStart();
    void losen();
    void accelerando();
    void ritardando();
    void soundGameover();
    void soundVictory();
    void soundTie();
  
};

#endif