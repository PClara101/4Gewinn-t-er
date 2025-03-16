/*
  Stepper 
  - ohne Klasse 
  - ohne Funktionen

  funktioniert!

  col   steps
  1     1345
  2     1200
  3     1050
  4     873
  5     745
  6     592
  7     435

*/


int stepCounter;
int steps = 1050;  

void setup() {
  Serial.begin(9600);
  pinMode(4, OUTPUT); // Enable
  pinMode(2, OUTPUT); // Step
  pinMode(3, OUTPUT); // Richtung

  digitalWrite(4, LOW);

  digitalWrite(3,HIGH); // richtung Trichter

  for(stepCounter = 0; stepCounter < steps; stepCounter++) {
    digitalWrite(2,HIGH);
    delayMicroseconds(500);
    digitalWrite(2,LOW);
    delayMicroseconds(500);
  }
  
  delay(2000);
  
  digitalWrite(3,LOW); // richtung Parkplatz
  for(stepCounter = 0; stepCounter < steps; stepCounter++) {
    digitalWrite(2,HIGH);
    delayMicroseconds(1000);
    digitalWrite(2,LOW);
    delayMicroseconds(1000);
    Serial.println(stepCounter);
  }
  
  delay(1000);
}

void loop() {

}