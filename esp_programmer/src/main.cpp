#include <Arduino.h>
#include <WiFi.h>
#include <HardwareSerial.h>

const char* WIFI_SSID     = "YOUR_SSID";
const char* WIFI_PASSWORD = "YOUR_PASSWORD";
const uint16_t TCP_PORT   = 328;
const int RX_PIN          = 16;
const int TX_PIN          = 17;

WiFiServer server(TCP_PORT);
HardwareSerial ArduinoSerial(2);

void setup() {
  Serial.begin(115200);
  ArduinoSerial.begin(115200, SERIAL_8N1, RX_PIN, TX_PIN);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); Serial.print(".");
  }
  Serial.println("\nConnected! IP: " + WiFi.localIP().toString());
  server.begin();
  Serial.println("TCP server started on port 328");
}

void loop() {
  WiFiClient client = server.available();
  if (!client) return;

  Serial.println("avrdude connected - press RST on Arduino now!");
  
  ArduinoSerial.setTimeout(100);

  while (client.connected()) {
    while (client.available()) {
      ArduinoSerial.write((uint8_t)client.read());
    }
    while (ArduinoSerial.available()) {
      client.write((uint8_t)ArduinoSerial.read());
    }
  }
  client.stop();
  Serial.println("avrdude disconnected.");
}


