#include <EtherCard.h>  // libreria de internet
#include <ArduinoJson.hpp>
#include <ArduinoJson.h>

//varibles de sensores

const byte sensor0 = 0;
const byte sensor2 = 2;
const byte sensor3 = 3;
const byte sensor4 = 4;




// array que almacena los asientos disponibles
const int N = 8;
int asientos[] = { 3, 4, 7, 8 };

// inicialzando los pines en alto
int asiento3 = HIGH;   //Asiento disponible
int asiento4 = HIGH;   //Asiento disponible
int asiento7 = HIGH;   //Asiento disponible
int asiento8 = HIGH;   //Asiento disponible

//numero de identificacion del bus
int numeroBus_4 = 500;
int dt = 1000;

//----------------------------------------------------------------------
// CONEXION

// Si colocamos 1 deshabilitamos el DHCP
// Si colocamos 0 colocamos una IP estática
#define ESTATICA 1

#if ESTATICA
// Colocamos la dirección IP al dispositivo
static byte myip[] = { 43, 68, 12, 26 };
// Colocamos la dirección IP de la puerta de enlace de nuestro router
static byte gwip[] = { 43, 68, 12, 1 };

#endif

// Colocamos la dirección MAC, que sera único en nuestra red
static byte mymac[] = { 0x90, 0xA2, 0xDA, 0x0A, 0xA0, 0x88 };

// Enviar y recibir buffer (TCP/IP)
byte Ethernet::buffer[500];

//---------------------------------------------------------------------
// Pagina Web

const char page[] PROGMEM =
  "HTTP/1.0 503 Ethernet Hanrun HR911105A - \r\n"
  "Content-Type: text/html\r\n"
  "Retry-After: 600\r\n"
  "\r\n"
  "<html>"
  "<head><title>"
  "Asientos Libres"
  "</title></head>"
  "<body>"
  "<h3>Andimar</h3>"
  "<p><em>"
  "Asientos libres en bus 500: 'variable json'<br />"
  "</em></p>"
  "</body>"
  "</html>",
                  json;


//-----------------------------------------------------------------------

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  conexion();
}

void loop() {

  asiento3 = digitalRead(sensor0);
  asiento4 = digitalRead(sensor2);
  asiento7 = digitalRead(sensor3);
  asiento8 = digitalRead(sensor4);



  if (asiento3 == HIGH) {  //valida que el sensor no detecte nada y guarda el numero del asiento
    asientos[0] = 3;
  } else {  // caso contrario almacena un 0
    asientos[0] = 0;
  }

  if (asiento4 == HIGH) {
    asientos[1] = 4;
  } else {
    asientos[1] = 0;
  }

  if (asiento7 == HIGH) {
    asientos[2] = 7;
  } else {
    asientos[2] = 0;
  }

  if (asiento8 == HIGH) {
    asientos[3] = 8;
  } else {
    asientos[3] = 0;
  }

  web();
}

void web() {
  if (ether.packetLoop(ether.packetReceive())) {
    memcpy_P(ether.tcpOffset(), page, sizeof page);
    imprimir();
    ether.httpServerReply(sizeof page - 1);
  }
}

void conexion() {
  Serial.println("\n[Conexion]");

  if (ether.begin(sizeof Ethernet::buffer, mymac) == 0)  // valida la conexion a internet
    Serial.println("Error al acceder al controlador Ethernet");
#if ESTATICA
  ether.staticSetup(myip, gwip);
#else
  if (!ether.dhcpSetup())
    Serial.println("DHCP falló");
#endif
  // si se conecta muestra la informacion siguiente
  ether.printIp("IP:  ", ether.myip);
  ether.printIp("GW:  ", ether.gwip);
  ether.printIp("DNS: ", ether.dnsip);
  Serial.println();
}



void imprimir() {
  Serial.print("Asientos disponibles en bus ");
  Serial.print(numeroBus_4);
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
