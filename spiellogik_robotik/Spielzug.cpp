
#include "Arduino.h"
#include "SpielMechaniken.h"

    // Funktion, Spielzug
    // x ist das Symbol vom Spieler
    void SpielMechaniken::Zug(int col, int x) {
      for (int row = ROWS - 1; row >= 0; row--) {
        if (board[row][col] == EMPTY) {
          board[row][col] = x;
          break;
        }
      }    
    }
    bool SpielMechaniken::richtigerZug(int col) {
      return board[0][col] == EMPTY;
    }

    void SpielMechaniken::zurueckZug(int col) {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][col] != 0) {
            board[i][col] = 0;
            break;
        }
    }
}
