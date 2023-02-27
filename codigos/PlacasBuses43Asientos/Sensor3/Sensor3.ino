//varibles de sensores
const byte sensor1 = 1;
const byte sensor2 = 2;
const byte sensor3 = 3;
const byte sensor4 = 4;
const byte sensor5 = 5;
const byte sensor6 = 6;
const byte sensor7 = 7;
const byte sensor8 = 8;
const byte sensor9 = 9;


// array que almacena los asientos disponibles
const int N = 9;
int asientos[N] = { 3, 10, 13, 16, 19, 22, 25, 28, 30};

// inicialzando los pines en alto
int asiento3 = HIGH;  //Asiento disponible
int asiento10 = HIGH;  //Asiento disponible
int asiento13 = HIGH;  //Asiento disponible
int asiento16 = HIGH;  //Asiento disponible
int asiento19 = HIGH;  //Asiento disponible
int asiento22 = HIGH;  //Asiento disponible
int asiento25 = HIGH;  //Asiento disponible
int asiento28 = HIGH;  //Asiento disponible
int asiento31 = HIGH;  //Asiento disponible

//numero de identificacion del bus
int numeroBus_3 = 1000;

int dt = 1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  asiento3 = digitalRead(sensor1);
  asiento10 = digitalRead(sensor2);
  asiento13 = digitalRead(sensor3);
  asiento16 = digitalRead(sensor4);
  asiento19 = digitalRead(sensor5);
  asiento22 = digitalRead(sensor6);
  asiento25 = digitalRead(sensor7);
  asiento28 = digitalRead(sensor8);
  asiento31 = digitalRead(sensor9);
  
  if (asiento3 == HIGH) {    
    asientos[0] = 3;
  } else {
    asientos[0] = 0;
  }
  if (asiento10 == HIGH) {
    asientos[1] = 10;
  } else {
    asientos[1] = 0;
  }
  if (asiento13 == HIGH) {
    asientos[2] = 13;
  } else {
    asientos[2] = 0;
  }
  if (asiento16 == HIGH) {
    asientos[3] = 16;
  } else {
    asientos[3] = 0;
  }
  if (asiento19 == HIGH) {
    asientos[4] = 19;
  } else {
    asientos[4] = 0;
  }
  if (asiento22 == HIGH) {
    asientos[5] = 22;
  } else {
    asientos[5] = 0;
  }
  if (asiento25 == HIGH) {
    asientos[6] = 25;
  } else {
    asientos[6] = 0;
  }
  if (asiento28 == HIGH) {
    asientos[7] = 28;
  } else {
    asientos[7] = 0;
  }
  if (asiento31 == HIGH) {
    asientos[8] = 31;
  } else {
    asientos[8] = 0;
  }

  imprimir();
  delay(dt);
}

void imprimir() {

  Serial.print("Asientos disponibles en bus ");
  Serial.print(numeroBus_3);
  Serial.print(": ");
  disponibilidad();
  delay(dt);
}

void disponibilidad() {
  for (int i = 0; i < N; i++) {
    if (asientos[i] != 0) {
      Serial.print(asientos[i]);
      Serial.print(",");      
    }
  }
  Serial.println();
}
