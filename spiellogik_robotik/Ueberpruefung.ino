
class checking {

  public:
  // Überprüfung, x (Spieler) gewonnen?
   bool LetzterSpielzug(int spieler) {
  // Horizontal prüfen
    for (int row = 0; row < ROWS; row++) {
      for (int col = 0; col < COLUMNS - 3; col++) {
          if (board[row][col] == spieler && board[row][col + 1] == spieler &&
              board[row][col + 2] == spieler && board[row][col + 3] == spieler) {
              return true;
      }
    }
  }
    // Vertikal prüfen
    for (int col = 0; col < COLUMNS; col++) {
        for (int row = 0; row < ROWS - 3; row++) {
            if (board[row][col] == spieler && board[row + 1][col] == spieler &&
                board[row + 2][col] == spieler && board[row + 3][col] == spieler) {
                return true;
      }
    }
  }


    // Diagonal von links unten nach rechts oben prüfen
    for (int row = 0; row <= ROWS - 3; row++) {
        for (int col = 0; col <= COLUMNS - 3; col++) {
            if (board[row][col] == spieler &&
                board[row + 1][col + 1] == player &&
                board[row + 2][col + 2] == player &&
                board[row + 3][col + 3] == player) {
                return true;
            }
        }
    }
    
    // Diagonal von recht oben nach links unten prüfen
    for (int row = 0; row <= ROWS - 3; row++) {
        for (int col = 3; col < COLUMNS; col++) {
            if (board[row][col] == spieler &&
                board[row + 1][col - 1] == spieler &&
                board[row + 2][col - 2] == spieler &&
                board[row + 3][col - 3] == spieler) {
                return true;
            }
        }
    }
    
  return false;
}

}