#include <SPI.h>
#include <ArduinoJson.hpp>
#include <ArduinoJson.h>
#include <EtherCard.h>
#include <UIPEthernet.h>

byte mac[] = { 0x90, 0xA2, 0xDA, 0x0A, 0xA0, 0x88 };  //mac address 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED / 0x74, 0x69, 0x69, 0x2D, 0x45, 0x41 / 0x90, 0xA2, 0xDA, 0x0A, 0xA0, 0x88
IPAddress ip(43, 68, 12, 26);                         //ip de tu Arduino en la red
/* IPAddress dns(43, 68, 12, 1); */
IPAddress gateway(43, 68, 12, 1);    // ip de tu router
IPAddress subnet(255, 255, 255, 0);  // subnet

char server[] = "43, 68, 12, 26";
char c;
EthernetClient cliente;

/* EthernetServer server = EthernetServer(80); */  // puerto de conexión

String json, solicitud;

//varibles de sensores
const byte sensor1 = 1;
const byte sensor3 = 3;
const byte sensor4 = 4;
const byte sensor5 = 5;
const byte sensor6 = 6;
const byte sensor7 = 7;
const byte sensor8 = 8;
const byte sensor9 = 9;


// array que almacena los asientos disponibles
const int N = 13;
int asientos[N] = { 1, 5, 9, 11, 13, 17, 21, 25, 29 };


// inicialzando los pines en alto
int asiento1 = HIGH;   //Asiento disponible
int asiento9 = HIGH;   //Asiento disponible
int asiento11 = HIGH;  //Asiento disponible
int asiento13 = HIGH;  //Asiento disponible
int asiento17 = HIGH;  //Asiento disponible
int asiento21 = HIGH;  //Asiento disponible
int asiento25 = HIGH;  //Asiento disponible
int asiento29 = HIGH;  //Asiento disponible

//numero de identificacion del bus
int numeroBus_1 = 500;
int dt = 1000;


void setup() {
  Serial.begin(9600);

  Ethernet.linkStatus();
  Serial.println("\n[Conexion]");
  Serial.println();
  Ethernet.begin(mac, ip);  // si se conecta muestra la informacion siguiente
  if (Ethernet.linkStatus() != LinkOFF) {
    Serial.println("El cable Ethernet esta conectado");
    Serial.println();
  }

  Serial.print("IP Address : ");
  Serial.println(Ethernet.localIP());
  Serial.print("Subnet Mask : ");
  Serial.println(Ethernet.subnetMask());
  Serial.print("Default Gateway IP: ");
  Serial.println(Ethernet.gatewayIP());
  Serial.print("DNS Server IP : ");
  Serial.println(Ethernet.dnsServerIP());

  if (cliente.connect(server, 80)) {

    Serial.print("nuevo cliente conectado desde ");
    Serial.println(Ethernet.localIP());
  }
  c = cliente.read();
  Serial.write(c);


  /* server.begin(); */
}
void loop() {
  lectura();
  web();

  delay(dt);
}


void lectura() {
  // put your main code here, to run repeatedly:
  asiento1 = digitalRead(sensor1);
  asiento9 = digitalRead(sensor3);
  asiento11 = digitalRead(sensor4);
  asiento13 = digitalRead(sensor5);
  asiento17 = digitalRead(sensor6);
  asiento21 = digitalRead(sensor7);
  asiento25 = digitalRead(sensor8);
  asiento29 = digitalRead(sensor9);


  if (asiento1 == HIGH) {  //valida que el sensor no detecte nada y guarda el numero del asiento
    asientos[0] = 1;
  } else {  // caso contrario almacena un 0
    asientos[0] = 0;
  }
  if (asiento9 == HIGH) {
    asientos[2] = 9;
  } else {
    asientos[2] = 0;
  }
  if (asiento11 == HIGH) {
    asientos[3] = 11;
  } else {
    asientos[3] = 0;
  }
  if (asiento13 == HIGH) {
    asientos[4] = 13;
  } else {
    asientos[4] = 0;
  }
  if (asiento17 == HIGH) {
    asientos[5] = 17;
  } else {
    asientos[5] = 0;
  }
  if (asiento21 == HIGH) {
    asientos[6] = 21;
  } else {
    asientos[6] = 0;
  }
  if (asiento25 == HIGH) {
    asientos[7] = 25;
  } else {
    asientos[7] = 0;
  }
  if (asiento29 == HIGH) {
    asientos[8] = 29;
  } else {
    asientos[8] = 0;
  }
}


void web() {
  boolean currentLineIsBlank = true;

  /*   if (solicitud.length() < 100) { solicitud += c; }
  if (c == '\n' && currentLineIsBlank) { */
  cliente.println("HTTP/1.0 503 Ethernet Hanrun HR911105A - \r\n");  // enviamos cabeceras HTTP/1.1 200 OK
  /* cliente.println("Cache-Control: no-store, no-cache, must-revalidate, max-age=0"); */
  cliente.println("Content-Type: text/html\r\n");  //Content-Type: application/json;charset=utf-8
  cliente.println("Access-Control-Allow-Origin: *");
  cliente.println("Connection: close");
  cliente.println("Refresh: 5");
  cliente.println();

  // Enviar pagina web en HTML
  cliente.println("<!DOCTYPE HTML>");
  cliente.println("<html>");
  cliente.println("<head><title>");
  cliente.println("Asientos Libres");
  cliente.println("</title></head>");
  cliente.println("<body>");
  cliente.println("<h3>");
  cliente.println("Asientos libres bus 500:");
  cliente.println("</h3>");
  cliente.println(json);  //imprimimos datos
  cliente.println();
  cliente.println("</body>");
  cliente.println("</html>");
  /*   }
  if (c == '\n') {
    currentLineIsBlank = true;
  }
  if (c != '\r') {
    currentLineIsBlank = false;
  } */

  delay(100);      // esperamos un poco
  cliente.stop();  //cerramos la conexión
  if (!cliente.connected()) { cliente.stop(); }
}




void imprimir() {
  Serial.print("Asientos disponibles en bus ");
  Serial.print(numeroBus_1);
  Serial.print(": ");
  disponibilidad();
  delay(dt);
}

void disponibilidad() {
  String json;
  StaticJsonDocument<300> doc;
  JsonArray arr = doc.createNestedArray();
  for (int i = 0; i < N; i++) {  // recorre el array que almacena los numeros de los asientos
    if (asientos[i] != 0) {      // valida que los numeros del array eh imprime los que tengan un numero que sea distinto a 0

      arr.add(asientos[i]);
    }
  }
  serializeJson(doc, json);
  Serial.println(json);
  Serial.println();
}
