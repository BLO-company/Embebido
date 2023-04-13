void Send_JSON() {
  // Create a JSON object
  StaticJsonDocument<200> doc;
  doc["temperature"] = 23.5;
  doc["humidity"] = 56.8;

  // Convert the JSON object to a string
  String json_str;
  serializeJson(doc, json_str);

  // Publish the JSON string to MQTT
  client.publish("sensor/temperature_humidity", json_str.c_str());
}
  