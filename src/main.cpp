#include <Arduino.h>

#include "WiFiManager.h"
#include "MqttManager.h"
#include "DebugManager.h"

#include <ArduinoJson.h>
#include <Adafruit_NeoPixel.h>

/*
Autor:João Pedro M.
Data:29/04/2026
Versão:1.0
Descrição: Criação MQTT
*/

const int PINO_LED_RGB = 48;
const int QUANTIDADE_LEDS = 1;

Adafruit_NeoPixel ledRGB(
    QUANTIDADE_LEDS,
    PINO_LED_RGB,
    NEO_GRB + NEO_KHZ800);

void tratarJsonLedRGB(const String &mensagem);
void alternarCorLedRGB(int vermelho, int verde, int azul);
void configurarLedRGB();
void tratarMensagemRecebida(const char *topico, const String &mensagem);

void setup()
{
   configurarDebug();

   configurarLedRGB();

  //alternarCorLedRGB(0, 255, 0); // VERDE
 //alternarCorLedRGB(255, 255, 255); // BRANCO
// alternarCorLedRGB(0, 0, 255); // AZUL
 //delay(500);
 //alternarCorLedRGB(255, 0, 255); // ROXO
 //alternarCorLedRGB(255, 0, 0); // VERMELHO
 //delay(500);

   conectarWiFi();
   configurarMQTT();
   registrarCallbackMensagem(tratarMensagemRecebida);
   conectarMQTT();

}

void loop()
{
 // Vermelho → Verde
for (int i = 0; i <= 255; i++) {
  alternarCorLedRGB(255 - i, i, 0);
  delay(10);
}

// Verde → Azul
for (int i = 0; i <= 255; i++) {
  alternarCorLedRGB(0, 255 - i, i);
  delay(10);
}

// Azul → Vermelho
for (int i = 0; i <= 255; i++) {
  alternarCorLedRGB(i, 0, 255 - i);
  delay(10);
}

   garantirWiFiConectado();
   garantirMQTTConectado();
   loopMQTT();
}

void tratarMensagemRecebida(const char *topico, const String &mensagem)
{
   Serial.print("Mensagem recebida: ");
   Serial.println(mensagem);

   tratarJsonLedRGB(mensagem);
}

void configurarLedRGB()
{
   ledRGB.begin();
   ledRGB.setBrightness(80);
   ledRGB.clear();
   ledRGB.show();
}

void alternarCorLedRGB(int vermelho, int verde, int azul)
{
   // Garante valores válidos (0–255)
   vermelho = constrain(vermelho, 0, 255);
   verde    = constrain(verde, 0, 255);
   azul     = constrain(azul, 0, 255);

   ledRGB.setPixelColor(0, ledRGB.Color(vermelho, verde, azul));
   ledRGB.show();
}

void tratarJsonLedRGB(const String &mensagem)
{
  JsonDocument doc;

   DeserializationError erro = deserializeJson(doc, mensagem);

   if (erro)
{
   Serial.println("Erro ao ler JSON. Mensagem inválida:");
   Serial.println(mensagem);
   return;

   

   int r = doc["r"] | 0;
   int g = doc["g"] | 0;
   int b = doc["b"] | 0;

   alternarCorLedRGB(r, g, b);
}
}