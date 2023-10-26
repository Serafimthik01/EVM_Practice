int g = 0;

void setup() {
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, INPUT);
  digitalWrite(D0, HIGH);
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
}

void loop() {
  if (!digitalRead(D3)){
    g++;
    switch(g){
      case 1:
      digitalWrite(D0, HIGH);
      digitalWrite(D1, LOW);
      digitalWrite(D2, LOW);
      delay(250);
      break;

      case 2:
      digitalWrite(D1, HIGH);
      digitalWrite(D0, LOW);
      digitalWrite(D2, LOW);
      delay(250);
      break;

      case 3:
      digitalWrite(D2, HIGH);
      digitalWrite(D0, LOW);
      digitalWrite(D1, LOW);
      delay(250);
      break;

      default:
      if(g >= 3){
        g = 0;
      }
    }
  }
}
