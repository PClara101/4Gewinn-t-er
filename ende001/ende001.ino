/*
  _____ENDE_______
    > reagiert auf Überprüfung der Spiellogik --> letzterSpielzug()
    > letzterSpielzug() hat als return true(Spielerin gewonnen)
   - was ist mit den Möglichkeiten rob gweninnt und unentschieden?
        > unentschieden 
          - getätigte Spielzüge zählen(von rob und Spielerin), wenn Anzahl der Spielsteine erreicht und kein Gewinner festgestellt --> unentschieden
*/

#define PIEZO 6
#define ROTE_LED 4
#define BLAUE_LED 3

#include "LedKlasse.h"
#include "pitches.h"

LedKlasse redLed(ROTE_LED);
LedKlasse blueLed(BLAUE_LED);

int gewinnter;

void setup() {
  // zum Ausprobieren wird Endstand ausgelost
  randomSeed(analogRead(0));
  losen();
  //int gewinnter = 2;
  
  if (gewinnter == 0) { 
    soundGameover();
    for (int i = 0; i < 10; i++) {
      blueLed.blinken(400);
    }
  }
  else if (gewinnter == 1) {
    soundVictory();
    for (int i = 0; i < 10; i++) {
      redLed.blinken(400);
    }
  }
  else {
    soundTie();
    for (int i = 0; i < 20; i++) {
    redLed.toggle();
    blueLed.toggle();
    delay(400);
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}

int losen() {
  gewinnter = random(2); // 0(Maschiene), 1(Mensch), 2(Unentschieden)
  return gewinnter;
}

void soundGameover() {
  // notes in the melody in the correct order:
  int melody[] = {  
    NOTE_A3, NOTE_GS3, NOTE_G3
  };

  // note durations: 4 = quarter note, 8 = eighth note, etc.:
  int noteDurations [] = {
    2, 2, 1
  }; 


  for (int thisNote = 0; thisNote < 3; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(PIEZO, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.3;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(PIEZO);  
  }
}

void soundVictory() {
  int melody[] = {  
    NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_G5, 0, NOTE_B5, NOTE_C6
  };

  // note durations: 4 = quarter note, 8 = eighth note, etc.:
  int noteDurations [] = {
    32, 32, 32, 32, 32, 32, 32, 8, 16, 16, 8, 8, 8, 8, 4
  }; 


  for (int thisNote = 0; thisNote < 15; thisNote++) {
    int noteDuration = 1300 / noteDurations[thisNote];
    tone(PIEZO, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.3;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(PIEZO);
  } 
}

void soundTie() {
  int melody[] = {
    NOTE_GS6, NOTE_DS6, NOTE_GS5, NOTE_AS5
  };
  // Notenwert
  int noteDurations [] = {
    4, 4, 4, 4
  };

  for (int thisNote = 0; thisNote < 4; thisNote ++) {
    int noteDuration = 800 / noteDurations[thisNote];
    tone(PIEZO, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration *1.3;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(PIEZO);
  }
}
