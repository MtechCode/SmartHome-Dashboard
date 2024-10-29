#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>

#define DHTPIN 4     
#define DHTTYPE DHT11  

DHT dht(DHTPIN, DHTTYPE);
const char* ssid = "your-SSID";
const char* password = "your-PASSWORD";
String serverName = "http://your_server_ip:5000/data";

void setup() {
  Serial.begin(115200);
  dht.begin();
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverName.c_str());
    http.addHeader("Content-Type", "application/json");

    String jsonData = "{\"temperature\":" + String(t) + ", \"humidity\":" + String(h) + "}";
    int httpResponseCode = http.POST(jsonData);

    if (httpResponseCode > 0) {
      Serial.println("Data sent successfully");
    } else {
      Serial.println("Error sending data");
    }
    http.end();
  }
  delay(60000); // Wysyłanie danych co minutę
}
