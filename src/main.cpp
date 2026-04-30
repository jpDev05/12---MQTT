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

   conectarWiFi();
   configurarMQTT();
   registrarCallbackMensagem(tratarMensagemRecebida);
   conectarMQTT();
}

void loop()
{
   garantirWiFiConectado();
   garantirMQTTConectado();
   loopMQTT();
}

void tratarMensagemRecebida(const char *topico, const String &mensagem)
{
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
}

void tratarJsonLedRGB(const String &mensagem)
{
}