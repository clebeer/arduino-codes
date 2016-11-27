#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* ssid = "h2hc";
const char* password = "hck1337";

String site = "";

ESP8266WebServer server(80);

//int gpio0_pin = 0;
//int gpio2_pin = 2;

void handleRoot() {
  site =  "<html>\n";
  site += "<head><title>H2HC Badge by CleBeeR</title></head>\n";
  site += "<body stile\"color: blue\">\n";
  site += "<center><h1>Hello World from H2HC 2016 Badge</h1></center>\n";
  site += "</body>\n";
  site += "</html>";

  server.send(200, "text/html", site);

  site = "";
}

void setup() {
  WiFi.mode(WIFI_AP); //aceita WIFI_AP / WIFI_AP_STA / WIFI_STA
  WiFi.begin(ssid, password);
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  server.on("/", handleRoot);
  server.begin();
}

void loop(){
  server.handleClient();
}

