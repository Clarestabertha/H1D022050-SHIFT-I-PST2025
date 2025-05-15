#include <Arduino.h>
#include <Servo.h>

int trigPin = D0;
int echoPin = D1;
int LED1 = D2; //LED HIJAU
int LED2 = D3; //LED MERAH
Servo servo;

long duration;
long distance;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo.attach(D4);
  Serial.begin(9600);
}

void loop(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = 0.034*duration/2;
  
   if (distance <= 1500) { //Jika jarak benda 1,5 meter maka...
    digitalWrite(LED1, HIGH);
    servo.write(180); // Servo buka
  } else {
    digitalWrite(LED2, HIGH);
    servo.write(0); // Servo tutup
  }

}