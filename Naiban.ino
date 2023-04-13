#include <WiFi.h>
#include <PubSubClient.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <ArduinoJson.h>

char* ssid = "Nombre_de_la_Red_WiFi";
char* password = "Contraseña_de_la_Red_WiFi";
char* mqtt_server = "IP_o_Dominio_del_Servidor_MQTT";
char* mqtt_user = "Usuario_del_Servidor_MQTT";
char* mqtt_password = "Contraseña_del_Servidor_MQTT";

double Latitud;
double Longitud;

WiFiClient espClient;
PubSubClient client(espClient);
SoftwareSerial ss(16, 17); // RX, TX
TinyGPSPlus gps;

void setup() {
  ss.begin(9600);
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();  
  
  Read_GPS();
  Send_JSON();
  delay(5000);

}

