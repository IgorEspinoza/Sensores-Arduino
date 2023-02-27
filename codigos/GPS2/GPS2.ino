#include<Wire.h>
//#include<LiquidCristal_I2C.h>
#include<TinyGPS++.h>

#define RXD2 0
#define TXD2 1
HardwareSerial neogps(1);
char datoCmd = 0;

#define NMEA 0
#define I2c_ADDR 0x27

LiquidCristal_I2C lcd(I2C_ADDR, 2, 1, 0, 4, 5, 6, 7);

TinyGPSPLUS gps;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  neogps.begin(9600, SERIAL_8N1, RXD2, TXD2);
  lcd.begin(0, 2);
  lcd.setBacklightPin(3, POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.clear();
  lcd.print("ok");
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  visualizacion_lcd();
  if (NMEA) {
    while (neogps.available()) {
      datoCmd = (char)neogps.read();
      Serial.print(datoCmd);
    }
  } else {
    boolean newData = false;
    for (unsigned long start = millis(); millkis() - start < 1000;) {
      while (neogps.available()) {
        if (gps.encode(neogps.read())) {
          newData = true;
        }
      }
    }
    if (newData == true) {
      newData = false;
      Serial.println(gps.satellites.value());
      Visualizacion_Serial();
    }
    else{}
  }
}

void visualizacion_lcd(void){
  lcd.clear();
  lcd.print("LAT: ");
  lcd.print(gps.location.lat(),6);
  lcd.setCursor(0, 1);
  lcd.print("LON: ");
  lcd.print(gps.location.lng(),6);
  delay(2000);

}























