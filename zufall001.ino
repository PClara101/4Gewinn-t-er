/*
  ZUFALL/START

  - zufällige Bestimmung des Beginners random()
  - dazu visueller Effekt 
    - schneller werdenes, abwechselndes Blinken der zwei LED --> accelerando()
    - dann leuchtet nur noch die LED des Beginnenden --> toggel


*/
#define PIEZO 6
#define ROTE_LED 9
#define BLAUE_LED 8

#include "pitches.h"
#include "LedKlasse.h"
LedKlasse redLED(ROTE_LED); // LED der Spielerin
LedKlasse blueLED(BLAUE_LED); // LED des Roboters



int beginner = 0;

void setup() {
  //Serial.begin(9600);    //muss nur drin sein, wenn die ausgeloste Zahl auf dem SerialMonitor angezeigt werden soll + Z41
  randomSeed(analogRead(0));  // damit die auswahl wirklich zufällig ist
  
  soundStart();
  losen();
  accelerando();
  ritardando();
  
  // anzeigen des Beginners
  if (beginner == 3) {
    blueLED.toggle();
  }
  else {
    redLED.toggle();
  }
}

void loop() {

}

// losen bestimmt "zufällig" eine Zahl zwischen 3 und 5 (also entweder 3 oder 4)
// zufällig zwischen den Anschlusspins der LEDs wählen

int losen() {
  beginner = random(3,5);
  //Serial.println(beginner); 
}


void accelerando() {
  for (int i = 275; i >= 100; i -= 25){
    redLED.blinken(i);
    blueLED.blinken(i);
  }
  for (int i = 100; i >= 30; i -= 10) {
    redLED.blinken(i);
    blueLED.blinken(i);
  }
}

void ritardando() {
  for (int i = 30; i <= 100; i += 10) {
    redLED.blinken(i);
    blueLED.blinken(i);    
  }
}

void soundStart() {
  // Töne der Melodie
  int melody[] = {
    NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_DS5
  };
  // Notenwert
  int noteDurations [] = {
    16, 16, 16, 4
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