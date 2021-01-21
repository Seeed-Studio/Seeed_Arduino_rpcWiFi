

/*
 *  This sketch sends data via HTTP GET requests to examle.com service.
 */

#include <rpcWiFi.h>
#include <rpcPing.h>
const char *ssid = "ssid";
const char *password = "password";
const char *host = "www.baidu.com";
const char *url = "/index.html";

void setup()
{
    Serial.begin(115200);
    delay(10);

    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print("Connecting to ");
        Serial.println(ssid);
        WiFi.begin(ssid, password);
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

int value = 0;

void loop()
{
    delay(5000);
  Serial.print("Pinging host ");
  Serial.println(host);
  bool ret = Ping.ping(host);
  //float avg_time_ms = Ping.averageTime();
  if(ret) {
    Serial.println("Success!!");
    Serial.println("TIME: ");
   // Serial.println(avg_time_ms);
  } else {
    Serial.println("Error :(");
  }
    
}
