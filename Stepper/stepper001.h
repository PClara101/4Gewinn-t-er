#ifndef stepper001_h
#define stepper001_h
#include "Arduino.h"

class stepper {

  public:
    stepper(bool enablePin,int stepPin,bool dirPin);
    void moveTo(int col);


  private:
    int currentPosition;
    int _steps;
    bool _enablePin;
    bool _stepPin;
    bool _dirPin;
    int calculateSteps(int col);
  
};
#endif
