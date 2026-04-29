#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>


void conectarWIfi();

void garantirWiFiConectado();

void setup() 
{
   Serial.begin(9600);
   conectarWIfi();
}

void loop() 
{
   garantirWiFiConectado();
}