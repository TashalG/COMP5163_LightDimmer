#include <Arduino.h>

int iLedOn = 0;         
int iLastButton = HIGH;

void setup() {
  pinMode(D5, INPUT_PULLUP);

  pinMode(D4, OUTPUT);

  analogWriteRange(1023);

  digitalWrite(D4, HIGH);
}

void loop() {
  int iButton;
  int iPot;

  iButton = digitalRead(D5);

  if (iButton == LOW && iLastButton == HIGH) {
    iLedOn = !iLedOn;
  }
  iLastButton = iButton;

  if (iLedOn) {
    iPot = analogRead(A0);
    analogWrite(D4, 1023 - iPot);
  } else {
    digitalWrite(D4, HIGH);
  }

  delay(1);
}