
#include "Arduino.h"
#include "SpielMechaniken.h"

    // Funktion, Spielzug
    // x ist das Symbol vom Spieler
    void SpielMechaniken::Zug(int col, int spieler) {
      for (int row = ROWS - 1; row >= 0; row--) {
        if (board[row][col] == EMPTY) {
          board[row][col] = spieler;
          break;
        }
      }    
    }
    bool SpielMechaniken::richtigerZug(int col) {
      if (col < 0 || col >= COLUMNS) return false;
      for (int row = ROWS - 1; row >= 0; row--) {
        if (board[row][col] == EMPTY) {
            return true;  // Platz in der Spalte
        }
    }
    return false;  // Spalte ist voll
    }

    void SpielMechaniken::zurueckZug(int col) {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][col] != 0) {
            board[i][col] = 0;
            break;
        }
    }
}
