#include <WiFi.h>
#include <string>
#include <Wire.h>
#include <TroykaMeteoSensor.h>
#include <TroykaIMU.h>
 
String ssid = "ASOIU";
String password = "kaf.asoiu.48";

WiFiServer server(80);
TroykaMeteoSensor meteoSensor;
Barometer barometer;

void setup() {
  Serial.begin();
  Wire.begin();
  meteoSensor.begin();
  barometer.begin();

  WiFi.mode(WIFI_STA);
  WiFi.setHostname("PicoW2");
  WiFi.begin(ssid.c_str(), password.c_str());
  
  Serial.printf("Подключение к '%s' с '%s'\n", ssid.c_str(), password.c_str());
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.printf("\nПодключение к Wi-Fi...\n\nПодключение к серверу по адресу: %s\n", WiFi.localIP().toString().c_str());

  server.begin();
}

void sendHtmlTemplate(WiFiClient client) {
  delay(50);
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println();
  client.println("<html>");
  client.println("<head><title>Данные о погоде и барометре:</title></head>");
  client.println("<body>");
  client.println("<h1>Данные барометра:</h1>");
  client.println("<p>Давление: " + String(barometer.readPressureMillimetersHg()) + " mmHg</p>");
  client.println("<p>Высота: " + String(barometer.readAltitude()) + " meters</p>");
  client.println("<p>Температура: " + String(barometer.readTemperatureC()) + "&deg;C</p>");

  client.println("</body>");
  client.println("</html>");

  client.flush();
}

void loop() {
  WiFiClient client = server.available();
  if (!client) return;
  
  while (!client.available()) ;

  String req = client.readStringUntil('\n');
  Serial.println(req);
  sendHtmlTemplate(client);
}