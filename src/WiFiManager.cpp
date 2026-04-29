//! WiFiManager.cpp
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <WiFiClient.h>
#include "WiFiManager.h"
#include "secrets.h"
#include "DebugManager.h"

bool wifiEstaConectado()
{
    return WiFi.status() == WL_CONNECTED;
}

void conectarWiFi()
{
    debugInfo("===============================");
    debugInfo("Iniciando conexão Wi-Fi...");
    debugInfo("===============================");
    /**Configura o ESP32 como station, ou seja,
     * ele se conecta a um roteador Wi-Fi existente
     */
    WiFi.mode(WIFI_STA);

    /**Inicia a conexão com SSID e senha */
    WiFi.begin(WIFI_SSID, WIFI_SENHA);
    Serial.println("Conectando");

    int tentativasWiFi = 0;
    const int maxTentativasWiFi = 30;
    /**Aguarda a conexão por até 30 tentativas */
    while (WiFi.status() != WL_CONNECTED && tentativasWiFi < maxTentativasWiFi)
    {
        delay(500);
        debugInfoSemLinha(".");
        tentativasWiFi++;
    }
    {
        delay(500);
        debugInfoSemLinha(".");
    }

    debugInfo("");

    if (WiFi.status() == WL_CONNECTED)
    {
        debugInfo("Conectado à rede Wi-Fi!");
        debugInfo("Endereço IP: ");
        debugInfo(String(WiFi.localIP()));
    }
    else
    {
        debugErro("Falha ao conectar à rede Wi-Fi!");
        debugErro("Verifique as credenciais e tente novamente.");
    }
}

void garantirWiFiConectado()
{
    if (WiFi.status() != WL_CONNECTED)
    {
        debugErro("Wi-Fi desconectado. Tentando reconectar...");
        conectarWiFi();
    }
    if (WiFi.status() != WL_CONNECTED)
    {
        debugErro("Não foi possível reconectar ao Wi-Fi.");
    }
}