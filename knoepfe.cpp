#include <Arduino.h>
#include "knoepfe.h"

knoepfe::knoepfe(int pin) {
  pinMode(pin, INPUT);
}

int knoepfe::knoepfe() {
  col = -1
  while (col == -1) {
    int buttonvalue = analogRead(A0);
  // Spalte 6
    if(buttonvalue <= 130 && buttonvalue > 120) {
    Serial.println(6);
    col = 6;
    }
  // Spalte 5
    if(buttonvalue <= 180 && buttonvalue > 165) {
    Serial.println(5);
    col = 5;
    }
  // Spalte 4
    if(buttonvalue <= 210 && buttonvalue > 200) {
    Serial.println(4);
    col = 4;
    }
  // Spalte 3
    if(buttonvalue <= 265 && buttonvalue > 250) {
    Serial.println(3);
    col = 3;
    }
  // Spalte 2
    if(buttonvalue <= 350 && buttonvalue > 340) {
    Serial.println(2);
    col = 2;
    }
  // Spalte 1
    if(buttonvalue <= 520 && buttonvalue > 510) {
    Serial.println(1);
    col = 1;
    }
  // Spalte 0
    if(buttonvalue <= 1020 && buttonvalue > 1010) {
    Serial.println(0);
    col = 0;
    }
    delay(300);
  }
  return col
}
