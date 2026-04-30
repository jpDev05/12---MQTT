
#ifndef MQTT_MANAGER_H
#define MQTT_MANAGER_H
#include <Arduino.h>

void configurarMQTT();
void conectarMQTT();
void garantirMQTTConectado();
void loopMQTT();

void publicarMensagem(const char *topico, const char *mensagem);
void publicarMensagemNoTopico(int indiceTopico, const char *mensagem);

bool mqttEstaConectado();

//TODO criar as funções publicarMensagem e publicarMensagemNoTopico
//TODO criar parametro do tipo int chamado indiceTopico para as funções abaixo
const char *obterTopicoPublicacao(int indiceTopico);
const char *obterTopicoRecebimento(int indiceTopico);

typedef void (*CallbackMensagemMQTT)(const char *topico, const String &mensagem);

void registrarCallbackMensagem(CallbackMensagemMQTT callback);

int obterTotalTopicosRecebimento();

#endif