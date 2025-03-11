#include <Arduino.h>

#define ROWS = 6
#define COLUMNS = 7
#define EMPTY = 0

int board[ROWS][COLUMNS];

// Funktion zum erstellen des Spielfeldes
void Spielfeld() {
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLUMNS; col++) {
      board[row][col] = EMPTY;
    }
  }
}

// Funktion, Spielfeld auf dem Monitor
void MonitorSpielfeld() {
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLUMNS; col++) {
      Serial.print(board[row][col]);
    }
    Serial.println(" ");
  }
  Serial.println("---------------------------------------------------------");#
}


// Funktion, Spielzug
// x ist das Symbol vom Spieler
void Spielzug(int col, int x) {
  for (int row = ROWS - 1; row >= 0; row--) {
    if (board[row][col] == EMPTY) {
      board[row][col] = x;
      break;
    }
  }
}

void setup() {
  Serial.begin(9600);
  Spielfeld();
  MonitorSpielfeld();
}

void 











