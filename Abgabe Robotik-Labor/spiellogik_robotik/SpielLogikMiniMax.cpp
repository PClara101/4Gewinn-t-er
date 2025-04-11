
#include <Arduino.h>
#include "DatenMiniMax.h"
#include "SpielMechaniken.h" 

// fix Werte
#define ROWS 6
#define COLUMNS 7
#define EMPTY 0
#define Spieler 1
#define SpielLogik 2
#define MAX_DEPTH 4

// Objekt erstellen für Header-Datei
SpielMechaniken spielmechaniken;


int DatenMiniMax::minimax(int depth, bool maximizing) {
    // Kontrolle ob jemand gewinnen kann um zu gewinnen oder zu präventieren
    if (spielmechaniken.letzterSpielzug(SpielLogik)) return 1000 - depth;
    if (spielmechaniken.letzterSpielzug(Spieler)) return -1000 + depth;
    if (depth == MAX_DEPTH) return 0;

    // wird erstmals übersprungen, weil bool maximizing = false ist
    // wird rekursiv aufgerufen in else
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
                // aufruf für die Rekursion
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
    int besteZuege[COLUMNS]; //erstellen des Arrays wo die besten Züge gesammalt werden um zwischen ihenn auszulosen 
    int AnzahlBesteZuege = 0; 

    for (int c = 0; c < COLUMNS; c++) {
        if (spielmechaniken.richtigerZug(c)) {
            spielmechaniken.Zug(c, SpielLogik);
            // Aufruf MiniMax-Algorithmus 
            int score = minimax(1, false);
            // löscht die Züge die vom Minimax Algorithmus gesetzt werden 
            // für die Kalkulation, um das Spielfeld nicht zu zerstören
            spielmechaniken.zurueckZug(c);

            // Kontrollpunkt zur Überprüfung der korrekten Wiedergabe der  Werte 
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
    
    // dieser Zufallsgenerator ist dafür zuständig zwischen den Zeilen mit den
    // besten Werten zufällig zu wählen, weil ansonsten der Algorithmus sonst hauptsächlich 
    // in die erste setzen würde
    int zufallsIndex = random(AnzahlBesteZuege);
    bestMove = besteZuege[zufallsIndex];

    // Kontrollpunkt zur Überprüfung der korrekten Wiedergabe der  Werte 
    Serial.print("Best Move for AI: ");
    Serial.println(bestMove);  

    //Rückgabe der besten Zeile
    return bestMove;
}
