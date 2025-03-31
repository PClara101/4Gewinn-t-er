#define KNOEPFE A0
void setup() {
  pinMode(KNOEPFE,INPUT);
  Serial.begin(9600);
}

void loop() {
  int buttonvalue = analogRead(A0);
// Spalte 0
  if(buttonvalue <= 155 && buttonvalue > 100) {
    Serial.println(0);
  }
// Spalte 1
  if(buttonvalue <= 185 && buttonvalue > 160) {
  Serial.println(1);
  }
// Spalte 2
  if(buttonvalue <= 230 && buttonvalue > 190) {
  Serial.println(2);
  }
// Spalte 3
  if(buttonvalue <= 320 && buttonvalue > 240) {
  Serial.println(3);
  }
// Spalte 4
  if(buttonvalue <= 400 && buttonvalue > 340) {
  Serial.println(4);
  }
// Spalte 5
  if(buttonvalue <= 600 && buttonvalue > 490) {
  Serial.println(5);
  }
// Spalte 6
  if(buttonvalue <= 1024 && buttonvalue > 900) {
  Serial.println(6);
  }
  delay(300);
}
