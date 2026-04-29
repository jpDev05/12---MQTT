#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include "WiFiManager.h" 

// void conectarWiFi();

// void garantirWiFiConectado();

void setup() 
{
   Serial.begin(9600);
   conectarWiFi();
}

void loop() 
{
   garantirWiFiConectado();
}