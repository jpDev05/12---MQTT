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
const int PINO_LAMPADA = 8;

const char TOPICO_COMANDO[] = "senai134/esp32/comando";

Adafruit_NeoPixel ledRGB(
    QUANTIDADE_LEDS,
    PINO_LED_RGB,
    NEO_GRB + NEO_KHZ800);

void tratarJsonLedRGB(const String &mensagem);
void alternarCorLedRGB(int vermelho, int verde, int azul);
void configurarLedRGB();
void tratarMensagemRecebida(const char *topico, const String &mensagem);
void tratarJsonLEDRGB(const String& mensagem);

void setup()
{
   configurarDebug();

   // alternarCorLedRGB(0, 255, 0); // VERDE
   // alternarCorLedRGB(255, 255, 255); // BRANCO
   // alternarCorLedRGB(0, 0, 255); // AZUL
   // delay(500);
   // alternarCorLedRGB(255, 0, 255); // ROXO
   // alternarCorLedRGB(255, 0, 0); // VERMELHO
   // delay(500);

   conectarWiFi();
   configurarMQTT();
   registrarCallbackMensagem(tratarMensagemRecebida);
   conectarMQTT();

   configurarLedRGB();
}

void loop()
{

   garantirWiFiConectado();
   garantirMQTTConectado();
   loopMQTT();
}

void tratarMensagemRecebida(const char* topico, const String& mensagem)
{
  debugInfo("==============================");
  debugInfo("Mensagem recebida na aplicacao");
  debugInfo("==============================");
  if(topico == nullptr)
  {
    debugErro("Topico MQTT invalido");
    return;
  }
  debugInfo("Topico: " + String(topico));
  debugInfo("Mensagem: " + mensagem);
  if(strcmp(topico, TOPICO_COMANDO) == 0)
  {
    tratarJsonLEDRGB(mensagem);
    return;
  }
  debugErro("Topico nao tratado: " + String(topico));
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
   verde = constrain(verde, 0, 255);
   azul = constrain(azul, 0, 255);

   ledRGB.setPixelColor(0, ledRGB.Color(vermelho, verde, azul));
   ledRGB.show();
}

void tratarJsonLEDRGB(const String &mensagem)
{
    JsonDocument doc;
  DeserializationError erro = deserializeJson(doc, mensagem);
  if (erro)
  {
    debugErro("Erro ao desserializar JSON: " + String(erro.c_str()));
    return;
  }
  if (doc["led"].is<JsonObject>())
  {
    if (!doc["led"]["r"].is<int>() || !doc["led"]["g"].is<int>() || !doc["led"]["b"].is<int>())
    {
      debugErro("JSON INVALIDADO. Use led.r, led.g e led.b");
      return;
    }
    else
    {
      int vermelho = doc["led"]["r"].as<int>();
      int verde = doc["led"]["g"].as<int>();
      int azul = doc["led"]["b"].as<int>();
     alternarCorLedRGB(vermelho, verde, azul);
    }
  }
  if(doc["lampada"].is<JsonObject>())
  {
    if(!doc["lampada"].is<bool>())
    {
      debugInfo("JSON INVALIDADO. Use lampada: true ou lampada: false");
      return;
    }
    else
    {
      bool estadoLampada = doc["lampada"].as<bool>();
      if(estadoLampada)
      {
        pinMode(PINO_LAMPADA, OUTPUT);
        digitalWrite(PINO_LAMPADA, HIGH); // Liga a lâmpada (ou
      }
      else
      {
        pinMode(PINO_LAMPADA, OUTPUT);
        digitalWrite(PINO_LAMPADA, LOW); // Desliga a lâmpada (ou LED)
      }
    }
  }
}