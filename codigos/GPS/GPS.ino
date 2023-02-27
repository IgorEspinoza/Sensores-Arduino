#include<SoftwareSerial.h>

SoftwareSerial NEO6M(2, 3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  NEO6M.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(NEO6M.available() > 0){
    Serial.write(NEO6M.read());
  }

}

