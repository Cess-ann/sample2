#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>

const char* ssid = "Sjie";
const char* password = "sjie2002";

const int ledPin = D4; // Adjust according to your LED pin

AsyncWebServer server(80);

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  server.on("/toggle", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(ledPin, !digitalRead(ledPin));
    request->send(200, "text/plain", "OK");
  });

  server.begin();
}

void loop() {
}
