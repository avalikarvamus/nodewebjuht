#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include "global.h"

#include "Page_Root.h"
#include "Page_Script.js.h"
 
const char* ssid = "own";
const char* password = "pown";
 
int ledPin = 13; // GPIO13
 
void setup() {
  Serial.begin(115200);
  delay(10);
 
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
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
  
  // Start the server

  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

  server.on("/",handleWeb);
  server.on("/ajax",handleAjax); 
 
}

void handleWeb() {
    // Return the response
  //client.println("HTTP/1.1 200 OK");
  //client.println("Content-Type: text/html");
  //client.println(""); //  do not forget this one
  //server.send(200,"text/xml",web);
}

void handleAjax() {
    // Return the response
  //client.println("HTTP/1.1 200 OK");
  //client.println("Content-Type: text/html");
  //client.println(""); //  do not forget this one
  //server.send(200,"text/xml",ajax);
}
 
void loop() {

}
 
