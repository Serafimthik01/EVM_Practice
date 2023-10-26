#include <WiFi.h>
#include <string>
 
String ssid = "ASOIU";
String password = "kaf.asoiu.48";
 
void setup() {
  Serial.begin();
  while (!Serial) continue;

  WiFi.begin(ssid.c_str(), password.c_str());
  Serial.print("Подключен к Wi-Fi. IP = ");
  Serial.println(WiFi.localIP());
}
 
void loop() {
  if (!Serial.available()) return;

  if (WiFi.status() != WL_CONNECTED) WiFi.begin(ssid.c_str(), password.c_str());

  String host = String(Serial.readString().c_str());
  host.trim();

  if (!host.length()) return;
  
  int pingResult = WiFi.ping(host.c_str());

  Serial.print("Пинг: ");
  Serial.println(host.c_str());
  Serial.println(pingResult);
}