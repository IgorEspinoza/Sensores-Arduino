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

// array que almacena los asientos disponibles
const int N = 11;
int asientos[N] = { 1, 4, 6, 8, 11, 14, 17, 20, 23, 26, 29};

// inicialzando los pines en alto
int asiento1 = HIGH;  //Asiento disponible
int asiento4 = HIGH;  //Asiento disponible
int asiento6 = HIGH;  //Asiento disponible
int asiento8 = HIGH;  //Asiento disponible
int asiento11 = HIGH;  //Asiento disponible
int asiento14 = HIGH;  //Asiento disponible
int asiento17 = HIGH;  //Asiento disponible
int asiento20 = HIGH;  //Asiento disponible
int asiento23 = HIGH;  //Asiento disponible
int asiento26 = HIGH;  //Asiento disponible
int asiento29 = HIGH;  //Asiento disponible

//numero de identificacion del bus
int numeroBus_1 = 1000;

int dt = 1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  asiento1 = digitalRead(sensor1);
  asiento4 = digitalRead(sensor2);
  asiento6 = digitalRead(sensor3);
  asiento8 = digitalRead(sensor4);
  asiento11 = digitalRead(sensor5);
  asiento14 = digitalRead(sensor6);
  asiento17 = digitalRead(sensor7);
  asiento20 = digitalRead(sensor8);
  asiento23 = digitalRead(sensor9);
  asiento26 = digitalRead(sensor10);
  asiento29 = digitalRead(sensor11);

  if (asiento1 == HIGH) {    
    asientos[0] = 1;
  } else {
    asientos[0] = 0;
  }
  if (asiento4 == HIGH) {
    asientos[1] = 4;
  } else {
    asientos[1] = 0;
  }
  if (asiento6 == HIGH) {
    asientos[2] = 6;
  } else {
    asientos[2] = 0;
  }
  if (asiento8 == HIGH) {
    asientos[3] = 8;
  } else {
    asientos[3] = 0;
  }
  if (asiento11 == HIGH) {
    asientos[4] = 11;
  } else {
    asientos[4] = 0;
  }
  if (asiento14 == HIGH) {
    asientos[5] = 14;
  } else {
    asientos[5] = 0;
  }
  if (asiento17 == HIGH) {
    asientos[6] = 17;
  } else {
    asientos[6] = 0;
  }
  if (asiento20 == HIGH) {
    asientos[7] = 20;
  } else {
    asientos[7] = 0;
  }
  if (asiento23 == HIGH) {
    asientos[8] = 23;
  } else {
    asientos[8] = 0;
  }
  if (asiento26 == HIGH) {
    asientos[9] = 26;
  } else {
    asientos[9] = 0;
  }
  if (asiento29 == HIGH) {
    asientos[10] = 29;
  } else {
    asientos[10] = 0;
  }

  imprimir();
  delay(dt);
}

void imprimir() {

  Serial.print("Asientos disponibles en bus ");
  Serial.print(numeroBus_1);
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
