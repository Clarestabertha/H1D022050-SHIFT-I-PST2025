#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid = "4G-MIFI-F9A";
const char* password = "1234567890";
int LED1 = D2;
int LED2 = D3;
int LED3 = D4;

ESP8266WebServer server(80);
String webpage;

void setup(){
  Serial.begin(9600);
  delay(10);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
//Connect to wifi
  Serial.println();
  Serial.print("Configuring access point...");

//Mengatur wifi
  WiFi.mode(WIFI_AP); //mode station
  WiFi.begin(ssid, password); //mencocokan ssid dan password
  Serial.print("Access Point SSID : ");
  Serial.println(WiFi.softAPSSID());

//Print status connect
  Serial.println("IP address : ");
  Serial.println(WiFi.softAPIP());

//Isi website
  webpage+= "<h1>WEB CONTROL ESP8266</h1>";
  webpage+= "<h2>Claresta Berthalita Jatmika</h2>";
  webpage+= "<p>LED 1 :";
  webpage+= "<a href=\"LED10N\"\"><button>ON</button></a><a href=\"LED10FF\"\"><button>OFF</button></a></p><br>";
  webpage+= "<p>LED 2 :";
  webpage+= "<a href=\"LED20N\"\"><button>ON</button></a><a href=\"LED20FF\"\"><button>OFF</button></a></p><br>";
  webpage+= "<p>LED 3 :";
  webpage+= "<a href=\"LED30N\"\"><button>ON</button></a><a href=\"LED30FF\"\"><button>OFF</button></a></p>";

//membuat tampilan web
  server.on("/", [](){
    server.send(200, "text/html", webpage);
  });

//untuk merespon perintah  yang masuk
  server.on("/LED10N", [](){
    server.send(200, "text/html", webpage);
    digitalWrite(LED1, HIGH);
    delay(1000);
  });
  server.on("/LED20N", [](){
    server.send(200, "text/html", webpage);
    digitalWrite(LED2, HIGH);
    delay(1000);
  });
  server.on("/LED30N", [](){
    server.send(200, "text/html", webpage);
    digitalWrite(LED3, HIGH);
    delay(1000);
  });
  server.on("/LED10FF", [](){
    server.send(200, "text/html", webpage);
    digitalWrite(LED1, LOW);
    delay(1000);
  });
  server.on("/LED20FF", [](){
    server.send(200, "text/html", webpage);
    digitalWrite(LED2, LOW);
    delay(1000);
  });
  server.on("/LED30FF", [](){
    server.send(200, "text/html", webpage);
    digitalWrite(LED3, LOW);
    delay(1000);
  });
  
  server.begin();
  Serial.println("Webserver dijalankan...");
}

void loop (){
  server.handleClient();
}