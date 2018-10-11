#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
//#include <WebSocketsServer.h>

/*
#include <OneWire.h>
#include <DallasTemperature.h>
*/
#include "global.h"
#include "Page_Root.h"
#include "Page_Script.js.h"

//#define ONE_WIRE_BUS            D4

#define APWM D5
#define AIN1 D6
#define AIN2 D7

#define BPWM D8
#define BIN1 D4
#define BIN2 D3

const char* ssid = "own";
const char* password = "pown";

/*
int ledPin = 13; // GPIO13
int greenPin = 14; // GPIO14
int value = LOW;


OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature DS18B20(&oneWire);

float temp;
*/
void setup() {
  Serial.begin(115200);
  delay(10);
/*
  pinMode(ledPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  digitalWrite(greenPin, LOW);
*/

  pinMode(APWM, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BPWM, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.hostname("nodewebjuht");
  WiFi.begin(ssid, password);
  //digitalWrite(ledPin, HIGH);

  while (WiFi.status() != WL_CONNECTED) {
    //delay(250);
    //digitalWrite(ledPin, LOW);
    delay(250);
    //digitalWrite(ledPin, HIGH);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  //digitalWrite(ledPin, LOW);
  //digitalWrite(greenPin, HIGH);
  delay(250);
  //digitalWrite(greenPin, LOW);

  Serial.println("Networking connected");

  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

//  DS18B20.begin();

  server.on("/ajax/led", []() {
    /*if (value == 0) {
      Serial.println("LED on page");
      value = HIGH;
      server.send(200, "text/html", "GreenON");
  } else {
      Serial.println("LED off page");
      value = LOW;
      server.send(200, "text/html", "GreenOFF");
  }*/
  Serial.println("whatever 2");
  server.send(200, "text/html", "whatever 2");
  }
  );

  server.on("/ajax/temp", []() {
    Serial.println("temp page");
    /*
    DS18B20.requestTemperatures();
    temp = DS18B20.getTempCByIndex(0);
    server.send(200, "text/html", String(temp));*/
    server.send(200, "text/html", "temp");
  }
  );

  server.on("/ajax/ledOn", handleLEDon);
  server.on("/ajax/ledOff", handleLEDoff);

  server.on("/ajax/stop", handleStop);
  server.on("/ajax/start", handleRun);
  server.on("/ajax/slow", handleSlow);
  server.on("/ajax/medium", handleMedium);
  server.on("/ajax/quick", handleQuick);

  server.on("/ajax/left", handleLeft);
  server.on("/ajax/right", handleRight);

  server.on("/ajax/back", handleBack);

  server.on("/ajax/uleft", handleULeft);
  server.on("/ajax/uright", handleURight);

  server.on("/ajax/bleft", handleBLeft);
  server.on("/ajax/bright", handleBRight);

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
  /*digitalWrite(greenPin, HIGH);
  delay(50);
  digitalWrite(greenPin, LOW);
  delay(50);
  digitalWrite(greenPin, HIGH);
  delay(50);
  digitalWrite(greenPin, LOW);*/
}

void SetStop(char MOTOR) {
  if (MOTOR == 'a') {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
    analogWrite(APWM, LOW);
  } else if (MOTOR == 'b') {
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, LOW);
    analogWrite(BPWM, LOW);
  }
}

char * SetSpeed(char MOTOR, int SPEED) {
    int dir = LOW;
    if(SPEED < 0) {
        dir = HIGH;
        SPEED = SPEED * -1;
    }
    if(SPEED == 0) {
        SetStop(MOTOR);
        return "Motor stopped \n";
    } else {
      if(MOTOR == 'a') {
        digitalWrite(AIN2, dir);
        digitalWrite(AIN1, HIGH);
        analogWrite(APWM, SPEED);
        return "Left - Speed: Direction  \n";
      } else if(MOTOR == 'b') {
        digitalWrite(BIN2, dir);
        digitalWrite(BIN1, HIGH);
        analogWrite(BPWM, SPEED);
        return "Right - Speed: %u Direction %u \n";
      }
      return "Unknown motor";
    }
}

void handleWeb() {
  Serial.println("returning root");
  server.send ( 200, "text/html", htmlMessage );
}

void handleLed() {
  Serial.println("switch led");
  /*Serial.println(value);
  if (value == 0) {
    Serial.println("was low, will be high");
    value = HIGH;
    server.send ( 200, "text/html", "HIGH" );
  } else {
    Serial.println("was high, will be low");
    value = LOW;
    server.send ( 200, "text/html", "LOW" );
  }
  digitalWrite(greenPin, value);*/
  Serial.println("whatever");
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
 SetStop('a');
 SetStop('b');
}

void handleRun() {
 Serial.println("RUN");
 //digitalWrite(greenPin,LOW);
 server.send(200, "text/html", "RUN");
 SetSpeed('a', 1023);
 SetSpeed('b', 1023);
}

void handleSlow() {
 Serial.println("SLOW");
 //digitalWrite(greenPin,LOW);
 server.send(200, "text/html", "SLOW");
 SetSpeed('a', 500);
 SetSpeed('b', 500);
}

void handleMedium() {
 Serial.println("MEDIUM");
 //digitalWrite(greenPin,LOW);
 server.send(200, "text/html", "MEDIUM");
 SetSpeed('a', 850);
 SetSpeed('b', 850);
}

void handleQuick() {
 Serial.println("QUICK");
 //digitalWrite(greenPin,LOW);
 server.send(200, "text/html", "QUICK");
 SetSpeed('a', 1023);
 SetSpeed('b', 1023);
}

void handleBack() {
 Serial.println("BACK");
 //digitalWrite(greenPin,LOW);
 server.send(200, "text/html", "BACK");
 SetSpeed('a', -1023);
 SetSpeed('b', -1023);
}

void handleLeft() {
 Serial.println("LEFT");
 //digitalWrite(greenPin,LOW);
 server.send(200, "text/html", "LEFT");
 SetSpeed('a', 0);
 SetSpeed('b', 1023);
}

void handleRight() {
 Serial.println("RIGHT");
 //digitalWrite(greenPin,LOW);
 server.send(200, "text/html", "RIGHT");
 SetSpeed('a', 1023);
 SetSpeed('b', 0);
}


void handleULeft() {
 Serial.println("ULEFT");
 //digitalWrite(greenPin,LOW);
 server.send(200, "text/html", "ULEFT");
 SetSpeed('a', -1023);
 SetSpeed('b', 1023);
}

void handleURight() {
 Serial.println("URIGHT");
 //digitalWrite(greenPin,LOW);
 server.send(200, "text/html", "URIGHT");
 SetSpeed('a', 1023);
 SetSpeed('b', -1023);
}


void handleBLeft() {
 Serial.println("BLEFT");
 //digitalWrite(greenPin,LOW);
 server.send(200, "text/html", "BLEFT");
 SetSpeed('a', -1000);
 SetSpeed('b', -1023);
}

void handleBRight() {
 Serial.println("BRIGHT");
 //digitalWrite(greenPin,LOW);
 server.send(200, "text/html", "BRIGHT");
 SetSpeed('a', -1023);
 SetSpeed('b', -1000);
}

void handleLEDon() {
 Serial.println("LED on page");
 //digitalWrite(ledPin,HIGH);
 server.send(200, "text/html", "ON");
}

void handleLEDoff() {
 Serial.println("LED off page");
 //digitalWrite(ledPin,LOW);
 server.send(200, "text/html", "OFF");
}

void loop() {
  server.handleClient();
  //digitalWrite(greenPin,value);
}
