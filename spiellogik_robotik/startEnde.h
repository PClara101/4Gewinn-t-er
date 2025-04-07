#ifndef startEnde
#define startEnde
#include "Arduino.h"

class startEnde{
  
  public: 
    void start();
    void ende();
  private:
    void soundStart();
    void losen();
    void accelerando();
    void ritardando();
    void soundGameover();
    void soundVictory();
    void soundTie();
  
};

#endif