void setup() {
  pinMode(D0, OUTPUT);
  pinMode(D1, INPUT);
}

void loop() {
  digitalWrite(D0, !digitalRead(D1));
}
