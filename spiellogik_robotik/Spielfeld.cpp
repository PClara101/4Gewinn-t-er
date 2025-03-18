#include "SpielMechaniken.h"
#include <Arduino.h>

    // Funktion zum erstellen des Spielfeldes
    void SpielMechaniken::DigitalSpielfeld() {
      for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLUMNS; col++) {
          board[row][col] = EMPTY;
        }
      }
    }

    // Funktion, Spielfeld auf dem Monitor
    void SpielMechaniken::MonitorSpielfeld() {
      for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLUMNS; col++) {
          Serial.print(board[row][col]);
        }
        Serial.println(" ");
      }
      Serial.println("---------------------------------------------------------");#
    }
}