#include <ESP8266WiFi.h>
#include <ArduinoJson.h>

const char* ssid     = "";  
const char* password = "";

const char* host     = ""; // Your domain  
String path          = "/path/to/light.json";  
const int pin        = 2;

void setup() {  
  pinMode(pin, OUTPUT); 
  pinMode(pin, HIGH);
  Serial.begin(115200);

  delay(10);
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  int wifi_ctr = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected");  
  Serial.println("IP address: " + WiFi.localIP());
}

void loop() {  
  Serial.print("connecting to ");
  Serial.println(host);
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }

  client.print(String("GET ") + path + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: keep-alive\r\n\r\n");

  delay(500); // wait for server to respond

  // read response
  int dir = 0; 
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
    // we’ll parse the HTML body here
  }
  Serial.print("closing connection. ");
}
