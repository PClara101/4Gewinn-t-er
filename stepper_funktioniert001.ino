int stepCounter;
int steps = 1000;

void setup() {
  pinMode(4, OUTPUT); // Enable
  pinMode(2, OUTPUT); // Step
  pinMode(3, OUTPUT); // Richtung

  digitalWrite(4, LOW);

  // digitalWrite(3,LOW); // im Uhrzeigersinn (rechts)

  // for(stepCounter = 0; stepCounter < steps; stepCounter++) {
  //   digitalWrite(2,HIGH);
  //   delayMicroseconds(1000);
  //   digitalWrite(2,LOW);
  //   delayMicroseconds(1000);
  // }
  
  // delay(1000);
}

void loop() {
  digitalWrite(3,HIGH); // im Uhrzeigersinn

  for(stepCounter = 0; stepCounter < steps; stepCounter++) {
    digitalWrite(2,HIGH);
    delayMicroseconds(500);
    digitalWrite(2,LOW);
    delayMicroseconds(500);
  }
  
  delay(1000);

  digitalWrite(3,LOW); // gegen den Uhrzeigersinn

  for(stepCounter = 0; stepCounter < steps; stepCounter++) {
    digitalWrite(2,HIGH);
    delayMicroseconds(500);
    digitalWrite(2,LOW);
    delayMicroseconds(500);
  }

  delay(1000);
}