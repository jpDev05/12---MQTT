//!MqttManager.cpp
#include "MqqtManager.h"
#include <Arduino.h>
#include <WiFiClient.h>
#include <PubSubClient.h>
#include <WiFiClientSecure.h>
#include "WiFiManager.h"
#include "secrets.h"

#include "DebugManager.h"

//==============INSTANCIAS===============
WiFiClient wifiClient;
WiFiClientSecure wifiClientSecure;
PubSubClient mqqtClient;

CallBackMensagemMQTT callbackDaAplicacao = nullptr;

void registrarCallbackMensagem(CallbackMensagemMQTT callback)
{
    callbackDaAplicacao = callback;

if(callbackDaAplicacao != nullptr)
{
    debugInfo("Callback da aplicação registrada com sucesso.");

}
else
{
    debugErro("Callback da aplicação não foi registrada.");
}
}

const char* obterTopicoPublicacao(int indiceTopico)
{

}