void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mensaje recibido en el tema: ");
  Serial.println(topic);
  Serial.print("Contenido: ");
  Serial.println((char*)payload);
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Intentando conexión MQTT...");
    if (client.connect("ESP32_Client", mqtt_user, mqtt_password )) {
      Serial.println("Conexión establecida");
      client.subscribe("Tema_Subscripcion");
    } else {
      Serial.print("Error al conectar, código de error: ");
      Serial.println(client.state());
      delay(2000);
    }
  }
}