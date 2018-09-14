#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include "global.h"

#include "Page_Root.h"
#include "Page_Script.js.h"
 
const char* ssid = "own";
const char* password = "pown";
 
int ledPin = 13; // GPIO13
int greenPin = 15; // GPIO13
 
void setup() {
  Serial.begin(115200);
  delay(10);
 
  pinMode(ledPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  digitalWrite(greenPin, LOW);
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.hostname("nodewebjuht"); 
  WiFi.begin(ssid, password);
  digitalWrite(ledPin, HIGH);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    digitalWrite(ledPin, LOW);
    delay(250);
    digitalWrite(ledPin, HIGH);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  digitalWrite(ledPin, LOW);
  digitalWrite(greenPin, HIGH);
  delay(250);
  digitalWrite(greenPin, LOW);
  
  // Start the server

  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

  server.on("/",handleWeb);
  //server.on("/ajax",handleAjax);

  server.on ( "/microajax.js", []() {
    Serial.println("microajax.js");
    server.send ( 200, "text/plain", PAGE_microajax_js );
  } );

  server.on ( "/favicon.ico",   []() {
        Serial.println("favicon.ico");
        server.send ( 200, "text/html", "" );
      }  );
 
}

void handleWeb() {
  Serial.println("returning root");
  server.send ( 200, "text/html", PAGE_Root );
}

void handleAjax() {
  Serial.println("returning ajax");
  server.send(200,"text/xml", PAGE_microajax_js);
}
 
void loop() {

}
 
