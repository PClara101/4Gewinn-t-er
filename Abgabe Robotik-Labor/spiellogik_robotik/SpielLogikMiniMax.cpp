
#include <Arduino.h>
#include "DatenMiniMax.h"
#include "SpielMechaniken.h" 

#define ROWS 6
#define COLUMNS 7
#define EMPTY 0
#define Spieler 1
#define SpielLogik 2
#define MAX_DEPTH 4

SpielMechaniken spielmechaniken;


int DatenMiniMax::minimax(int depth, bool maximizing) {
    if (spielmechaniken.letzterSpielzug(SpielLogik)) return 1000 - depth;
    if (spielmechaniken.letzterSpielzug(Spieler)) return -1000 + depth;
    if (depth == MAX_DEPTH) return 0;
    
    if (maximizing) {
        int bestScore = -10000;
        for (int c = 0; c < COLUMNS; c++) {
            if (spielmechaniken.richtigerZug(c)) {
                spielmechaniken.Zug(c, SpielLogik);
                bestScore = max(bestScore, minimax(depth + 1, false));
                spielmechaniken.zurueckZug(c);
            }
        }
        return bestScore;
    } else {
        int bestScore = 10000;
        for (int c = 0; c < COLUMNS; c++) {
            if (spielmechaniken.richtigerZug(c)) {
                spielmechaniken.Zug(c, Spieler);
                bestScore = min(bestScore, minimax(depth + 1, true));
                spielmechaniken.zurueckZug(c);
            }
        }
        return bestScore;
    }
}

int DatenMiniMax::besterSpielzug() {
    int bestMove = -1;
    int bestScore = -10000;
    int besteZuege[COLUMNS];
    int AnzahlBesteZuege = 0;

    for (int c = 0; c < COLUMNS; c++) {
        if (spielmechaniken.richtigerZug(c)) {
            spielmechaniken.Zug(c, SpielLogik);
            int score = minimax(1, false);
            spielmechaniken.zurueckZug(c);
            
            Serial.print("Evaluating Column: ");
            Serial.println(c);
            Serial.print("Current Score: ");
            Serial.println(score);   

            if (score > bestScore) {
                bestScore = score;
                // alten besten Zug verwerfen, neuen speichern
                bestMove = c; 
                besteZuege[0] = c;
                AnzahlBesteZuege = 1;
            } else if (score == bestScore) {
                // gleicher Score -> zur Liste hinzufügen
                besteZuege[AnzahlBesteZuege] = c;
                AnzahlBesteZuege++;
            }
        }
    }

    int zufallsIndex = random(AnzahlBesteZuege);
    bestMove = besteZuege[zufallsIndex];

    Serial.print("Best Move for AI: ");
    Serial.println(bestMove);  
    return bestMove;
}
