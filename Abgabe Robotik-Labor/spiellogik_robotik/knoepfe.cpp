#include <Arduino.h>
#include "knoepfe.h"

void knoepfe::knoepfe1(int pin) {
  pinMode(pin, INPUT);
}

int knoepfe::knoepfe2() {
  int col = -1;  // Position: Parkplatz
  
  // Knopfwerte werden nur übermittelt, wenn Schlitten auf Parkplatz ist
  while (col == -1) {
    int buttonvalue = analogRead(A0);
    
  // erkenne und übergebe Spalte 6
    if(buttonvalue <= 130 && buttonvalue > 120) {
      Serial.println(6);
      col = 6;
    }
    
  // erkenne und übergebe Spalte 5
    if(buttonvalue <= 180 && buttonvalue > 165) {
      Serial.println(5);
      col = 5;
    }
    
  // erkenne und übergebe Spalte 4
    if(buttonvalue <= 210 && buttonvalue > 200) {
      Serial.println(4);
      col = 4;
    }
    
  // erkenne und übergebe Spalte 3
    if(buttonvalue <= 265 && buttonvalue > 250) {
      Serial.println(3);
      col = 3;
    }
    
  // erkenne und übergebe Spalte 2
    if(buttonvalue <= 350 && buttonvalue > 340) {
      Serial.println(2);
      col = 2;
    }
    
  // erkenne und übergebe Spalte 1
    if(buttonvalue <= 520 && buttonvalue > 510) {
      Serial.println(1);
      col = 1;
    }
    
  // erkenne und übergebe Spalte 0
    if(buttonvalue <= 1020 && buttonvalue > 1010) {
      Serial.println(0);
      col = 0;
    }
    
    delay(300);
  }
  return col;  // übergebe Spalte
}
