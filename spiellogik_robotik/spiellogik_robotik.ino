#include <Arduino.h>

#define ROWS = 6
#define COLUMNS = 7
#define EMPTY = 0
int board[ROWS][COLUMNS];

void setup() {
  Serial.begin(9600);
  Spielfeld();
  MonitorSpielfeld();
}

void 











