#include <ESP8266WiFi.h>
#include <WiFiClient.h>

#include <ESPAsyncWebServer.h>

const char *ssid = "***** ***";
const char *password = "wiadomoktowiadomokogowiadomoco";

AsyncWebServer server(80);

void runAccessPoint() {
   Serial.println("\ninfo(ap): configuring access point...");
   WiFi.softAP(ssid, password);
   Serial.println("info(ap): Access point successfuly runned; AP IP address " + WiFi.softAPIP().toString());
}

void runWebServer() {
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request -> send_P(200, "text/plain", "Async server response");
  });
  
  server.begin();
  Serial.println("info(webserver): HTTP server started");
}

void setup() {
   Serial.begin(9600);
   
   runAccessPoint();
   runWebServer();
}

void loop() {
   
}