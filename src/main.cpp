#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include "GestorDatos.h"
#include "FichaMedica.h"
#include "Paciente.h"

// 🔹 Pines para comunicación con Arduino
#define RXD2 16
#define TXD2 17
// 🔹 Datos Wi-fi  y Telegram
const char* ssid = "CASA WIFI";
const char* password = "95126239.com";
#define BOTtoken "8471480578:AAHIdrL2tU2llz_uO55NRJwQfn877mYrppc" //bot_token
#define CHAT_ID "7050184014"                                      // tu chat ID
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);
//Creancion del pasiente ,fichamedica, gestorDatos

FichaMedica ficha;
Paciente paciente;
GestorDatos gestorData(ficha);


void setup() {

  Serial.begin(115200);                       // Monitor serial
  Serial2.begin(9600, SERIAL_8N1, RXD2, -1);  // Comunicación con Arduino

  
  // Conexión Wi-Fi
  pinMode(2, OUTPUT);digitalWrite(2, LOW);    //Led Azul Interno
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {}
  digitalWrite(2, HIGH);                      // LED indica conexión
  client.setInsecure();    
  // Configura conexión segura
}


void loop() {
  if(gestorData.recibirDesdeSerial(paciente)){
  
    bot.sendMessage(CHAT_ID,gestorData.enviarATelegram(paciente));
    gestorData.guardarEnSD(paciente);
  }
}

