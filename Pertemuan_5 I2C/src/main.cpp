#include <Arduino.h>
#include <Wire.h>

int SDA_pin = D4;
int SCL_pin = D2;


void setup() {
  Wire.begin(SDA_pin, SCL_pin);
  Serial.begin(9600);
}

void loop() {
  byte error, address;
  int nDevices;

  Serial.print("TUNG TUNG TUNG SAHUR");
  nDevices = 0;

  for(address = 1;address<127;address++){ 
    //127 karena di lab yg diinstal td cuma ada alamat sekitar 127
    Wire.beginTransmission(address);
    error=Wire.endTransmission();

    if(error==0){
      Serial.print("12C terbaca pada alamat 0x");
      if(address<16){
        Serial.print("0");
      }
      Serial.print(address, HEX);
      Serial.println("...!");

      nDevices++;
    }else if(error==4){
      Serial.print("ada eror yang tidak diketahui di alamant 0x");
      if(address<16){
        Serial.print("0");
      }
      Serial.print(address, HEX);
    }
  }
  if(nDevices==0){
    Serial.print("Tidak ada alamat 1C2 satupun yang terdeteksi");
  }else{
    Serial.print("Selesei");
  }
  delay(5000);
}

