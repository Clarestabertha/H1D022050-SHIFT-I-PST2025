#include <Arduino.h>

int trigPin = D0;
int echoPin = D1;
int LED = D2;

long duration;
long distance;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = 0.034*duration/2;

  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");
  if (distance<=30){
    digitalWrite(LED, HIGH);
  }
  else{
    digitalWrite(LED, LOW);
  }
  delay(1000);
}
