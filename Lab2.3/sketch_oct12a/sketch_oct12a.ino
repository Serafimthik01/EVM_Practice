#include <SPI.h>
#include <AmperkaFET.h>

#define PIN_CS A0

FET mosfet(PIN_CS, 2);
int module;
int key;
bool a;

void setup() {
  SPI.setCS(D1);
  SPI.setTX(D3);
  SPI.setSCK(D2);
  mosfet.begin();
  Serial.begin(4800);
}

void loop() {
  if (Serial.available()>0){
    module = Serial.read();
    delay(250);
  }
  if (Serial.available()>0){
    key = Serial.read();
    delay(250);
  }
  if (Serial.available()>0) {
    a = Serial.read();
    delay(250);
  }
  mosfet.digitalWrite(module, key, a);
}
