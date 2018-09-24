#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WebSocketsServer.h>

#include <OneWire.h>
#include <DallasTemperature.h>

#include "global.h"
#include "Page_Root.h"
#include "Page_Script.js.h"

#define ONE_WIRE_BUS            D4 
 
const char* ssid = "own";
const char* password = "pown";
 
int ledPin = 13; // GPIO13
int greenPin = 14; // GPIO14
int value = LOW;

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature DS18B20(&oneWire);

float temp; 

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

  Serial.println("Networking connected");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

  DS18B20.begin();

  server.on("/ajax/led", []() {
    if (value == 0) {
      Serial.println("LED on page");
      value = HIGH;
      server.send(200, "text/html", "GreenON");
  } else {
      Serial.println("LED off page");
      value = LOW;
      server.send(200, "text/html", "GreenOFF");
  }}
  );

  server.on("/ajax/temp", []() {
    Serial.println("LED on page");
    DS18B20.requestTemperatures();
    temp = DS18B20.getTempCByIndex(0);
    server.send(200, "text/html", String(temp));
  }
  );

  server.on("/ajax/ledOn", handleLEDon);
  server.on("/ajax/ledOff", handleLEDoff);

  server.on("/ajax/stop", handleStop);
  server.on("/ajax/start", handleRun);

  server.on("/ajax/left", handleLeft);
  server.on("/ajax/right", handleRight);

  server.on ( "/microajax.js", handleAjax);

  server.on ( "/favicon.ico",   []() {
        Serial.println("favicon.ico");
        server.send ( 200, "text/html", "" );
      }  );
  server.on("/", handleWeb);

  server.onNotFound([]() {
    Serial.println("returning not found");
    server.send(200, "text/plain", "not found");
  });

  server.begin();
  Serial.println("HTTP server started");
  digitalWrite(greenPin, HIGH);
  delay(50);
  digitalWrite(greenPin, LOW);
  delay(50);
  digitalWrite(greenPin, HIGH);
  delay(50);
  digitalWrite(greenPin, LOW);
}


void loop() {
  server.handleClient();
  digitalWrite(greenPin,value);
}


void handleWeb() {
  Serial.println("returning root");
  server.send ( 200, "text/html", htmlMessage );
}

void handleLed() {
  Serial.println("switch led");
  Serial.println(value);
  if (value == 0) {
    Serial.println("was low, will be high");
    value = HIGH;
    server.send ( 200, "text/html", "HIGH" );
  } else {
    Serial.println("was high, will be low");
    value = LOW;
    server.send ( 200, "text/html", "LOW" );
  }
  digitalWrite(greenPin, value);
}

void handleAjax() {
  Serial.println("returning ajax");
  server.send(200,"text/xml", microajax_js);
}

void helloWeb() {
  Serial.println("returning hello");
  server.send(200,"text/xml", "hello");
}

void handleStop() {
 Serial.println("STOP!");
 //digitalWrite(greenPin,HIGH);
 server.send(200, "text/html", "STOP");
}

void handleRun() {
 Serial.println("RUN");
 //digitalWrite(greenPin,LOW);
 server.send(200, "text/html", "RUN");
}

void handleLeft() {
 Serial.println("LEFT");
 //digitalWrite(greenPin,LOW);
 server.send(200, "text/html", "LEFT");
}

void handleRight() {
 Serial.println("RIGHT");
 //digitalWrite(greenPin,LOW);
 server.send(200, "text/html", "RIGHT");
}

void handleLEDon() {
 Serial.println("LED on page");
 digitalWrite(ledPin,HIGH);
 server.send(200, "text/html", "ON");
}
 
void handleLEDoff() {
 Serial.println("LED off page");
 digitalWrite(ledPin,LOW);
 server.send(200, "text/html", "OFF");
}
