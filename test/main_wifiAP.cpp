#include <WiFi.h>
#include <WebServer.h>

const char* ssid     = "ESPdePAU";
const char* password = "12345678";

void ConnectWiFi_AP()
{ 
   Serial.println("");
   WiFi.mode(WIFI_AP);
   while(!WiFi.softAP(ssid, password))
   {
     Serial.println(".");
     delay(100);
   }
 
   Serial.println("");
   Serial.print("Iniciado AP:\t");
   Serial.println(ssid);
   Serial.print("IP address:\t");
   Serial.println(WiFi.softAPIP());
}
 
void setup() 
{
  Serial.begin(9600);
  
  ConnectWiFi_AP();
}
 
void loop() 
{ 
}