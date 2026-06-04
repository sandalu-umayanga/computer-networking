// code for ESP32 traffic generator to test the DoS firewall

// #include <WiFi.h>
// #include <WiFiUdp.h>

// const char* ssid = "WIFI_SSID";
// const char* password = "PASSWORD";

// // Ubuntu PC IP
// const char* serverIP = "IP of the device running the firewall script";
// const int serverPort = 5000;

// WiFiUDP udp;

// unsigned long packetCount = 0;

// void connectWiFi() {
//   WiFi.mode(WIFI_STA);
//   WiFi.begin(ssid, password);

//   Serial.print("Connecting");

//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }

//   Serial.println();
//   Serial.println("WiFi Connected");
//   Serial.print("ESP32 IP: ");
//   Serial.println(WiFi.localIP());
// }

// void setup() {
//   Serial.begin(115200);
//   delay(1000);

//   connectWiFi();
// }

// void loop() {

//   // Reconnect if WiFi drops
//   if (WiFi.status() != WL_CONNECTED) {
//     Serial.println("WiFi Lost. Reconnecting...");
//     connectWiFi();
//   }

//   String payload =
//       "FIREWALL_TEST Packet #" +
//       String(packetCount++) +
//       " Time=" +
//       String(millis());

//   udp.beginPacket(serverIP, serverPort);
//   udp.print(payload);
//   udp.endPacket();

//   Serial.println(payload);

//   // Change this value to increase packet rate
//   delay(10);   // ~100 packets/sec
// }