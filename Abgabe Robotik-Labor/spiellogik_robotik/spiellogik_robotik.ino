
#include <Arduino.h>
#include "SpielMechaniken.h" 
#include "knoepfe.h"
#include "DatenMiniMax.h"
#include "stepper001.h"
#include "LedKlasse.h"
#include "startEnde.h"
#include "Servo.h";

// fix Werte
#define ROWS 6
#define COLUMNS 7
#define EMPTY 0
#define Spieler 1
#define SpielLogik 2
#define MAX_DEPTH 4
#define SERVO 7

// Einbeziehung von Objekten für den zugriff auf die Header-Dateien
extern SpielMechaniken spielmechaniken; 
extern knoepfe Knoepfe; 
extern DatenMiniMax datenminimax; 
extern stepper Stepper001;
extern LedKlasse ledklasse;
extern Servo servo;
extern startEnde startende;

// Initialisierung 
LedKlasse roteLed(9);
LedKlasse blaueLed(8);
int board[ROWS][COLUMNS];
int beginner;

void setup() {
  Serial.begin(9600);
  Knoepfe.knoepfe1(0);  
  spielmechaniken.DigitalSpielfeld();  
  spielmechaniken.MonitorSpielfeld(); 
  randomSeed(analogRead(A3));  // oder A1, egal – wichtig ist nur, dass ein unbestimmter Wert reinkommt
  servo.attach(SERVO);
  startende.start();
}  

void loop() {
  // weil 20 Steine pro Farbe und dann ein Unentschieden erreicht ist 
  for (int rounds = 1; rounds <= 20; rounds++) {

    // schaut ob Spieler anfängt, wenn nicht ist durch den if-Befehl der Teil vom Code dauerhaft ausgeschalten 
    if (beginner == 4){ 
      Serial.print("Runde: ");
      Serial.println(rounds);

      int SpielerZug = -1;

      while (SpielerZug == -1) {
        SpielerZug = Knoepfe.knoepfe2();  // wartet auf Knopfeingabe
        if (!spielmechaniken.richtigerZug(SpielerZug)) {
          Serial.println("Ungültiger Zug. Bitte erneut versuchen.");
          SpielerZug = -1; 
        }
      // der Code um rein digital Spielen zu können, per Seriellen-Monitor-Eingabe
      //while (SpielerZug == -1) {
          //if (Serial.available() > 0) {
              //SpielerZug = Serial.parseInt();  // Liest die eingegebene Zahl des Spielers
              //delay(200);
              // Überprüft, ob der Zug gültig ist
              //if (!spielmechaniken.richtigerZug(SpielerZug)) {
                  //Serial.println("Ungültiger Zug. Bitte erneut versuchen.");
                  //SpielerZug = -1; 
                   
                  //}
          //}
      }

      spielmechaniken.Zug(SpielerZug, Spieler);
      Serial.print("Du spielst: ");
      Serial.println(SpielerZug);
      Serial.println();
      spielmechaniken.MonitorSpielfeld();

      if (spielmechaniken.letzterSpielzug(Spieler)) {
        Serial.println("Du hast gewonnen!");
        startende.ende(1);
        while (true);
      }
      roteLed.toggle();
      blaueLed.toggle();
    }

    // KI-Zug

    Serial.print("Runde: ");
    Serial.println(rounds);

    int KIzug = datenminimax.besterSpielzug();  // KI-Zug wird direkt hier gesetzt
    Serial.print("Besten Zug für KI: ");
    Serial.println(KIzug);

    if (KIzug != -1 && spielmechaniken.richtigerZug(KIzug)) {
      spielmechaniken.Zug(KIzug, SpielLogik);  // KI führt den Zug digital aus
      Stepper001.moveTo(KIzug);
      Stepper001.push();
      Stepper001.moveTo(-1);
      Serial.print("KI spielt: ");
      Serial.println(KIzug);
      Serial.println();
      spielmechaniken.MonitorSpielfeld();  // Zeigt das Spielfeld an

      if (spielmechaniken.letzterSpielzug(SpielLogik)) {
        Serial.println("Die KI hat gewonnen!");
        startende.ende(0);
        while (true);  // Spiel beenden oder wiederholen
      }
      roteLed.toggle();
      blaueLed.toggle();
    } else {
      // Dies wird nur ausgeführt, wenn die KI keinen gültigen Zug findet
      Serial.println("Die KI hat keinen gültigen Zug gefunden.");
      }

    // schaut ob die KI anfängt, wenn nicht ist durch den if-Befehl der Teil vom Code dauerhaft ausgeschalten
    if (beginner == 3){ 

      Serial.print("Runde: ");
      Serial.println(rounds);

      int SpielerZug = -1;

      while (SpielerZug == -1) {
        SpielerZug = Knoepfe.knoepfe2();  // wartet auf Knopfeingabe
        if (!spielmechaniken.richtigerZug(SpielerZug)) {
          Serial.println("Ungültiger Zug. Bitte erneut versuchen.");
          SpielerZug = -1; 
        }
      // der Code um rein digital Spielen zu können, per Seriellen-Monitor-Eingabe
      //while (SpielerZug == -1) {
          //if (Serial.available() > 0) {
              //SpielerZug = Serial.parseInt();  // Liest die eingegebene Zahl des Spielers
              //delay(200);
              // Überprüft, ob der Zug gültig ist
              //if (!spielmechaniken.richtigerZug(SpielerZug)) {
                  //Serial.println("Ungültiger Zug. Bitte erneut versuchen.");
                  //SpielerZug = -1; 
                   
                  //}
          //}
      }

      spielmechaniken.Zug(SpielerZug, Spieler);
      Serial.print("Du spielst: ");
      Serial.println(SpielerZug);
      Serial.println();
      spielmechaniken.MonitorSpielfeld();

      if (spielmechaniken.letzterSpielzug(Spieler)) {
        Serial.println("Du hast gewonnen!");
        startende.ende(1);
        while (true);
      }
      roteLed.toggle();
      blaueLed.toggle();
    }
  }
  startende.ende(2);
}  




      










