#include <Arduino.h>
#include <Servo.h>

Servo servo;

// void setup() {
//   servo.attach(D1);
// }

// void loop() {
//   for(int posisi = 0; posisi<=180; posisi++){
//     servo.write(posisi);
//     delay(10);
//   }
//   for(int posisi=180; posisi>=0; posisi --){
//     servo.write(posisi);
//     delay(10);
//   }
// }

void setup(){
  servo.attach(D1);
}

void loop(){
  servo.write(180);
  delay(2000);
  servo.write(0);
  delay(2000);
  servo.write(180);
  delay(2000);
}