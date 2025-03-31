#include <Arduino.h>

//#define MAX_DEPTH 4

int DatenMiniMax::minimax(int depth, bool maximizing) {
    if (checkWin(SpielLogik)) return 1000 - depth;
    if (checkWin(Spieler)) return -1000 + depth;
    if (depth == MAX_DEPTH) return 0;
    
    if (maximizing) {
        int bestScore = -10000;
        for (int c = 0; c < COLUMNS; c++) {
            if (richtigerZug(c)) {
                Zug(c, SpielLogik);
                bestScore = max(bestScore, minimax(depth + 1, false));
                zurueckZug(c);
            }
        }
        return bestScore;
    } else {
        int bestScore = 10000;
        for (int c = 0; c < COLUMNS; c++) {
            if (richtigerZug(c)) {
                Zug(c, Spieler);
                bestScore = min(bestScore, minimax(depth + 1, true));
                zurueckZug(c);
            }
        }
        return bestScore;
    }
}

int DatenMiniMax::BesterSpielzug() {
    int bestMove = -1;
    int bestScore = -10000;
    for (int c = 0; c < COLS; c++) {
        if (richtigerMove(c)) {
            Zug(c, SpielLogik);
            int score = minimax(0, false);
            zurueckZug(c);
            if (score > bestScore) {
                bestScore = score;
                bestMove = c;
            }
        }
    }
    return bestMove;
}
