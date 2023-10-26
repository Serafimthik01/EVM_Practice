void setup() {
  analogWriteFreq(25000);

}

void loop() {
  int pvm = map(analogRead(A0), 0, 4095, 0, 255);
  analogWrite(D0, pvm);
  analogWrite(D1, pvm);

}
