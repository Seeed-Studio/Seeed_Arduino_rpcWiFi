/*
 *  This sketch sends data via HTTP GET requests to data.sparkfun.com service.
 *
 *  You need to get streamId and privateKey at data.sparkfun.com and paste them
 *  below. Or just customize this script to talk to other HTTP servers.
 *
 */

#include <WiFi.h>

const char* ssid     = "wio terminal";
const char* password = "123456789";

const char* host = "192.168.137.1";

void setup()
{
    Serial.begin(115200);
    while (!Serial){};
    
    delay(1000);

    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);
    //WiFi.begin();
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
}

int value = 0;

void loop()
{
    delay(5000);
    
    // Serial.println("");
    // Serial.println("WiFi connected");
    // Serial.println("IP address: ");
    // Serial.println(WiFi.localIP());
    // Serial.println("AP BSSID: ");
    // Serial.println(WiFi.BSSIDstr());
    // Serial.println("AP RSSI: ");
    // Serial.println(WiFi.RSSI());
    // delay(5000);
    ++value;

    Serial.print("connecting to ");
    Serial.println(host);

    // Use WiFiClient class to create TCP connections
    WiFiClient client;
    const int httpPort = 80;
    if (!client.connect(host, httpPort)) {
        Serial.println("Connection failed!");
    } else {

        Serial.println("Connected to server!");
        // Make a HTTP request:
        client.println("GET / HTTP/1.0");
        client.println();
        while (client.connected()) {
            String line = client.readStringUntil('\n');
            if (line == "\r") {
                Serial.println("headers received");
                break;
            }
        }
        // if there are incoming bytes available
        // from the server, read them and print them:
        while (client.available()) {
            char c = client.read();
            if (c == '\n') {
                Serial.write('\r');
            }
            Serial.write(c);
        }
        client.stop();
    }
  
}

