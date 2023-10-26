volatile int g = 0;

void setup() {
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  attachInterrupt(D3, myEventListener, CHANGE);
  digitalWrite(D0, HIGH);
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
}

void loop() {
  
  }

void myEventListener() {
  //if (!attachInterrupt(0, myEventListener, CHANGE)){
    switch(g){
      case 1:
      digitalWrite(D0, HIGH);
      digitalWrite(D1, LOW);
      digitalWrite(D2, LOW);
      g++;
      break;

      case 2:
      digitalWrite(D1, HIGH);
      digitalWrite(D0, LOW);
      digitalWrite(D2, LOW);
      g++;
      break;

      case 3:
      digitalWrite(D2, HIGH);
      digitalWrite(D0, LOW);
      digitalWrite(D1, LOW);
      g=0;
      break;

      /*default:
      if(g >= 3){
        g = 0;
      }*/
    }
  }
