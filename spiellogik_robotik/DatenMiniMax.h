
#ifndef DatenMiniMax_h
#define DatenMiniMax_h
#include "Arduino.h"

class DatenMiniMax {

  public:
    int BesterSpielzug();
    int minimax(int depth, bool maximizing);
  private:
};
#endif