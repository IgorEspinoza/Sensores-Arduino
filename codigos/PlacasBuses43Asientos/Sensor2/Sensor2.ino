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
int asientos[N] = { 2, 5, 7, 9, 12, 15, 18, 21, 24, 27, 30};

// inicialzando los pines en alto
int asiento2 = HIGH;  //Asiento disponible
int asiento5 = HIGH;  //Asiento disponible
int asiento7 = HIGH;  //Asiento disponible
int asiento9 = HIGH;  //Asiento disponible
int asiento12 = HIGH;  //Asiento disponible
int asiento15 = HIGH;  //Asiento disponible
int asiento18 = HIGH;  //Asiento disponible
int asiento21 = HIGH;  //Asiento disponible
int asiento24 = HIGH;  //Asiento disponible
int asiento27 = HIGH;  //Asiento disponible
int asiento30 = HIGH;  //Asiento disponible

//numero de identificacion del bus
int numeroBus_2 = 1000;

int dt = 1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  asiento2 = digitalRead(sensor1);
  asiento5 = digitalRead(sensor2);
  asiento7 = digitalRead(sensor3);
  asiento9 = digitalRead(sensor4);
  asiento12 = digitalRead(sensor5);
  asiento15 = digitalRead(sensor6);
  asiento18 = digitalRead(sensor7);
  asiento21 = digitalRead(sensor8);
  asiento24 = digitalRead(sensor9);
  asiento27 = digitalRead(sensor10);
  asiento30 = digitalRead(sensor11);

  if (asiento2 == HIGH) {    
    asientos[0] = 2;
  } else {
    asientos[0] = 0;
  }
  if (asiento5 == HIGH) {
    asientos[1] = 5;
  } else {
    asientos[1] = 0;
  }
  if (asiento7 == HIGH) {
    asientos[2] = 7;
  } else {
    asientos[2] = 0;
  }
  if (asiento9 == HIGH) {
    asientos[3] = 9;
  } else {
    asientos[3] = 0;
  }
  if (asiento12 == HIGH) {
    asientos[4] = 12;
  } else {
    asientos[4] = 0;
  }
  if (asiento15 == HIGH) {
    asientos[5] = 15;
  } else {
    asientos[5] = 0;
  }
  if (asiento18 == HIGH) {
    asientos[6] = 18;
  } else {
    asientos[6] = 0;
  }
  if (asiento21 == HIGH) {
    asientos[7] = 21;
  } else {
    asientos[7] = 0;
  }
  if (asiento24 == HIGH) {
    asientos[8] = 24;
  } else {
    asientos[8] = 0;
  }
  if (asiento27 == HIGH) {
    asientos[9] = 27;
  } else {
    asientos[9] = 0;
  }
  if (asiento30 == HIGH) {
    asientos[10] = 30;
  } else {
    asientos[10] = 0;
  }

  imprimir();
  delay(dt);
}

void imprimir() {

  Serial.print("Asientos disponibles en bus ");
  Serial.print(numeroBus_2);
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
