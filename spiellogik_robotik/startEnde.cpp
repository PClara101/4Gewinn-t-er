#include "Arduino.h"
#include "startEnde.h"
#include "pitches.h"

startEnde::start() {
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

startEnde::ende() {
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

startEnde::soundStart() {
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

startEnde::losen() {
  beginner = random(3,5);
}

startEnde::soundGameover() {
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

startEnde::soundVictory() {
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

startEnde::soundTie() {
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

startEnde::accelerando() {
  for (int i = 275; i >= 100; i -= 25){
    redLED.blinken(i);
    blueLED.blinken(i);
  }
  for (int i = 100; i >= 30; i -= 10) {
    redLED.blinken(i);
    blueLED.blinken(i);
  }
}

startEnde::ritardando() {
  for (int i = 30; i <= 100; i += 10) {
    redLED.blinken(i);
    blueLED.blinken(i);    
  }
}
