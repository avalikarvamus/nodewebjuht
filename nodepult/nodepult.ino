#include <ESP8266WiFi.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS            D4

const char* ssid = "kala";
const char* password = "sala";

const char* host = "xxx.xxx.xxx.xxx";
const int   port = 80;
const int   watchTime = 5000;
unsigned long previousMillis = millis(); 


int ledPin = 4; // GPIO13
int greenPin = 5; // GPIO14

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature DS18B20(&oneWire);

float temp;

void setup() {
  WiFi.hostname("nodepult");
  Serial.begin(115200);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  unsigned long currentMillis = millis();

  if ( currentMillis - previousMillis > watchTime ) {
    previousMillis = currentMillis;
    WiFiClient client;
  
    if (!client.connect(host, port)) {
      Serial.println("connection failed");
      return;
    }

    String url = "/adddata?sdata=logentry&ddata=0.0&idata=";
    url += String(millis());
    url += "&kdata=nodepult";
    url += WiFi.localIP().toString();
    
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
    unsigned long timeout = millis();
    while (client.available() == 0) {
      if (millis() - timeout > 5000) {
        Serial.println(">>> Client Timeout !");
        client.stop();
        return;
      }
    }
  
    // Read all the lines of the reply from server and print them to Serial
    while(client.available()){
      String line = client.readStringUntil('\r');
      Serial.print(line);
    }
  }
}
