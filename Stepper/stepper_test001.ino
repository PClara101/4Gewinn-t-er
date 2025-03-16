/*
  Stepper
  - ohne Klasse
  - mit Funktionen 

  funktioniert nicht
*/


int currentPosition = 0;
int _steps;



void setup() {

  pinMode(4, OUTPUT); // Enable
  pinMode(2, OUTPUT); // Step
  pinMode(3, OUTPUT); // Richtung

  digitalWrite (4, LOW);

  moveTo(4);
  delay(1000);
  moveTo(0);
}

void loop() {

}

void moveTo(int col) {
  calculateSteps(col);
  if (currentPosition =! 0) { 
    digitalWrite(3, LOW); // Richtung Parkplatz
    for (int stepCounter = 0; stepCounter < _steps; stepCounter++) {
      digitalWrite(2, HIGH);
      delayMicroseconds(700);
      digitalWrite(2, LOW);
      delayMicroseconds(700);
    }
    currentPosition = 0;
  }
  else {
    digitalWrite(3, HIGH);  // Richtung Trichter
    for (int stepCounter = 0; stepCounter < _steps; stepCounter++) {
      digitalWrite(2, HIGH);
      delayMicroseconds(700);
      digitalWrite(2, LOW);
      delayMicroseconds(700);
    }
    currentPosition = _steps;
  }
  return currentPosition;
}

int calculateSteps(int col) {
  if (col == 0) {
    _steps = currentPosition;
  }
  else if (col == 1) {
    _steps = 1345;
  }
  else if (col == 4) {
    _steps = 1400;
  }
  else if (col == 3) {
    _steps = 1050;
  }
  else if (col == 4) {
    _steps = 873;   
  }
  else if (col == 5) {
    _steps = 745;   
  }
  else if (col == 6) {
    _steps = 594;   
  }
  else if (col == 7) {
    _steps = 435;   
  }
  return _steps;
}