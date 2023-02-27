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
const byte sensor10 = 10;
const byte sensor11 = 11;
const byte sensor12 = 12;

// array que almacena los asientos disponibles
const int N = 12;
int asientos[N] = { 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43};

// inicialzando los pines en alto
int asiento32 = HIGH;  //Asiento disponible
int asiento33 = HIGH;  //Asiento disponible
int asiento34 = HIGH;  //Asiento disponible
int asiento35 = HIGH;  //Asiento disponible
int asiento36 = HIGH;  //Asiento disponible
int asiento37 = HIGH;  //Asiento disponible
int asiento38 = HIGH;  //Asiento disponible
int asiento39 = HIGH;  //Asiento disponible
int asiento40 = HIGH;  //Asiento disponible
int asiento41 = HIGH;  //Asiento disponible
int asiento42 = HIGH;  //Asiento disponible
int asiento43 = HIGH;  //Asiento disponible

//numero de identificacion del bus
int numeroBus_4 = 1000;

int dt = 1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  asiento32 = digitalRead(sensor1);
  asiento33 = digitalRead(sensor2);
  asiento34 = digitalRead(sensor3);
  asiento35 = digitalRead(sensor4);
  asiento36 = digitalRead(sensor5);
  asiento37 = digitalRead(sensor6);
  asiento38 = digitalRead(sensor7);
  asiento39 = digitalRead(sensor8);
  asiento40 = digitalRead(sensor9);
  asiento41 = digitalRead(sensor10);
  asiento42 = digitalRead(sensor11);
  asiento43 = digitalRead(sensor12);

  if (asiento32 == HIGH) {    
    asientos[0] = 32;
  } else {
    asientos[0] = 0;
  }
  if (asiento33 == HIGH) {
    asientos[1] = 33;
  } else {
    asientos[1] = 0;
  }
  if (asiento34 == HIGH) {
    asientos[2] = 34;
  } else {
    asientos[2] = 0;
  }
  if (asiento35 == HIGH) {
    asientos[3] = 35;
  } else {
    asientos[3] = 0;
  }
  if (asiento36 == HIGH) {
    asientos[4] = 36;
  } else {
    asientos[4] = 0;
  }
  if (asiento37 == HIGH) {
    asientos[5] = 37;
  } else {
    asientos[5] = 0;
  }
  if (asiento38 == HIGH) {
    asientos[6] = 38;
  } else {
    asientos[6] = 0;
  }
  if (asiento39 == HIGH) {
    asientos[7] = 39;
  } else {
    asientos[7] = 0;
  }
  if (asiento40 == HIGH) {
    asientos[8] = 40;
  } else {
    asientos[8] = 0;
  }
  if (asiento41 == HIGH) {
    asientos[9] = 41;
  } else {
    asientos[9] = 0;
  }
  if (asiento42 == HIGH) {
    asientos[10] = 42;
  } else {
    asientos[10] = 0;
  }
  if (asiento43 == HIGH) {
    asientos[10] = 43;
  } else {
    asientos[10] = 0;
  }

  imprimir();
  delay(dt);
}

void imprimir() {

  Serial.print("Asientos disponibles en bus ");
  Serial.print(numeroBus_4);
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
