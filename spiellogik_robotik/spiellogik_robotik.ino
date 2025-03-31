#include <Arduino.h>

#define ROWS = 6
#define COLUMNS = 7
#define EMPTY = 0
#define Spieler = 1
#define SpielLogik = 2
#define MAX_DEPTH 4

int board[ROWS][COLUMNS];

void setup() {
  Serial.begin(9600);
  Spielfeld();
  MonitorSpielfeld();
  start();

  for (int rounds = 1, rounds > 20, rounds ++) {
    knoepfe() {
    int SpielerZug = col();
    if (richtigerZug(SpielerZug)) {
      Zug(SpielerZug, PLAYER);
      MonitorSpielfeld();

      
}













