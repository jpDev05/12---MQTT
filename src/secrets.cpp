#include "secrets.h"
#include <Arduino.h>

const char *WIFI_SSID = "SALA 09";
const char *WIFI_SENHA = "info@134";



//=============================
// MQTT
//=============================


const bool MQTT_TLS = true;
const char *MQTT_BROKER = "7446153920f943aaafdb9d624f064dbb.s1.eu.hivemq.cloud";
const int MQTT_PORTA = 8883;

const char *MQTT_CLIENT_ID = "esp_joao_oliveira";

const char *MQTT_USUARIO = "CA0S6";
const char *MQTT_SENHA = "Senai@134";

const bool MQTT_USAR_TLS = true; // modo de cnexao sem segurança


const char MQTT_CERTIFICADO_CA[]  PROGMEM = "";


//=============================
// AWS
//=============================

const bool USAR_AWS_IOT = false;

const char* AWS_CERT_CA PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";


const char* AWS_CERT_CRT PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDWTCCAkGgAwIBAgIUeKJz8jYjowwSqBAqwKZQ9HaToq4wDQYJKoZIhvcNAQEL
BQAwTTFLMEkGA1UECwxCQW1hem9uIFdlYiBTZXJ2aWNlcyBPPUFtYXpvbi5jb20g
SW5jLiBMPVNlYXR0bGUgU1Q9V2FzaGluZ3RvbiBDPVVTMB4XDTI2MDUxODE3MzE1
MFoXDTQ5MTIzMTIzNTk1OVowHjEcMBoGA1UEAwwTQVdTIElvVCBDZXJ0aWZpY2F0
ZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBANDvcks9vnOA6XqRrBpp
GrkArcsP/8b4Dg8cZNzZVDdjNMdF2KFI/p1xZ5WR60LTZN0cUhbfaBJmUBYmNcnm
ab6X834VSIOhVOYeMXowvymlPJ9be+m5nHGEN3Eg2MBaplXTGhXy2ookUcDpV/TG
i75+92efXB6KPtoNq4cUtFw7HEHKBJi2UKosWaCcDM7t8ObMDymAJdrWsSYJzwr3
VbZPTxN6AQlsGlf4jeLp99pZL66aBN4llj0bnz/olmR/wV//LFtRAlOLBq60oRre
1UeJmPEsS8h9GhJMkLEhFbhiu9Zpbax+bFpiyWwVNmbaxyEfXL1rte+VkU3m9Ih9
jS8CAwEAAaNgMF4wHwYDVR0jBBgwFoAU6PillGGxMy/S56Kj46TCzCdb29EwHQYD
VR0OBBYEFGA8NJbCtfMeIl+Al7z0ttHjC2H0MAwGA1UdEwEB/wQCMAAwDgYDVR0P
AQH/BAQDAgeAMA0GCSqGSIb3DQEBCwUAA4IBAQB/CAtmeJbmjUhptvVhRHhLL5jF
QWa1znZxCGppsYvRzp+v6qftbBqz+1HuIIK+rU+LpOsRfyaHGMGmlVt+YKB26s3o
HOZUSVHk9dHouy95dLnk1pa9Wg+IaPxzJe6DIKFK7YG2tF3ibNW0A96qCzJpwgt5
pBH78mfkIjOxeAQ7A0l/89heqHqTFCPLG0YBAvQDBkqF4l2W2VFmKfuV/u8fl3TX
PG1cuoBzZvePoi0kMiCNGCFRxZ4qbtJ+i75Z7/k0XxH6WTBIr9or1CyPtDODHYxo
2SRHKee/FcMKs30oCXB/R9RVPP2+IMVpVkcsS3mfJAYvnxdSC/qvM/JR0PW8
-----END CERTIFICATE-----
)EOF";

const char* AWS_CERT_PRIVATE PROGMEM = R"EOF(
-----BEGIN RSA PRIVATE KEY-----
MIIEpAIBAAKCAQEA0O9ySz2+c4DpepGsGmkauQCtyw//xvgODxxk3NlUN2M0x0XY
oUj+nXFnlZHrQtNk3RxSFt9oEmZQFiY1yeZpvpfzfhVIg6FU5h4xejC/KaU8n1t7
6bmccYQ3cSDYwFqmVdMaFfLaiiRRwOlX9MaLvn73Z59cHoo+2g2rhxS0XDscQcoE
mLZQqixZoJwMzu3w5swPKYAl2taxJgnPCvdVtk9PE3oBCWwaV/iN4un32lkvrpoE
3iWWPRufP+iWZH/BX/8sW1ECU4sGrrShGt7VR4mY8SxLyH0aEkyQsSEVuGK71mlt
rH5sWmLJbBU2ZtrHIR9cvWu175WRTeb0iH2NLwIDAQABAoIBAQCLFcrk8Y5Vv4wt
bsm9rxf97cjDs7vWTQy23HT8W6RnVqAsw39JJplwX6zP8ZpGGwk68/5lgYT7Mqa/
h+IorDzahratySdDkOM+aP0Q1WB8LaYkgzcCyO+u1ZA+u9nueqnd2jC0Sb1XVoQh
wnQt2vnt7wFtNrWREwByEcWMn6jM98uiErz0tIWPhiCVAxyxjtXf16iaLNsZz7PX
dSinEbqcfg+0w1K1Ykw38YLoInBw3vGp9qG3GEdevhjJYvsjJEpFSVeixSLyVZsp
MAV0SglYeEoh63Xgh0WY6/n0dlVWbUsl9GRXrMlxffqszZoMeDYgKpRvxTjGEoZc
tlJMUVWRAoGBAPo2amEU5CyhQe/xD4rfwUmN5oyNNqu6WSv1+75JzFWgldK/B+qV
Qc2tF+C4FRlW902d4isGEEK/SGATscy899nDNl2R+tzKbyunoLVRjM/EoBTYYXsU
+mNaV4nV0IFFCg0P/M9BhFXCQ/S+bUo3a1ShVWmMtk/NElxCdQcvA4OJAoGBANXE
na+eK8EQ7V6hNx6FlXhM1DV9RDfAOmerzbqWrpQmIJh/N3/j7/yCnQ+rG7QTFens
SdFHTFLPigeQvqOMIYrOzIvMLYxQvn/1ag70+ZIQFbovp/SAYerLl/3VypZD4gem
NMolMFwpp3zoPVynyPP/B9vhfNu58D+SBBpdT4T3AoGAEdZPPxx+J7BXQwOsV/ob
jWLQTLTEcPmX4cpnZ+la57/K7nsv1UlOp5rvWNXGq0fH2YCn3ulPv3JjdnXw9ueB
w8Rm28TMXXEQ+8u3aTWnFCiwQMwsJtoX/30xQGI9uvlw/f1lyGCjTnnK3me04tWQ
kTfvHtcpKAc2h900+o4fcgECgYBxNqlguj9oB+P/Kxi7FHp99QqqrYY0lJ0aDNZv
TKB3G95FhZLKK9kM/cva4X9Rlo4Tjq3lpYIZlYr/yLv+eBfHoRCZtXAmERljQYGD
HGEU52nqapTkHB4/sMX1jIW3oYoTDQaGTL3ZAcKPl5vv93ipKNdrr3dmE4rW0ClW
ITcdLwKBgQCQLwio/LjXpryoyPu6gfuauf1oDZ4o7it7pHuKttYBCV79/lRUPa/j
xbf6J/gZ8Q8WMQNERzGl3xbErPOmwba6qAzaKUma7PdScLwXyAi1+eQROVfgSXrO
r15YHi+cgdNHWBEutcJasOj8RuKdp7lt7N+UP5wJ02fBipAbbqUByg==
-----END RSA PRIVATE KEY-----
)EOF";

const char* AWS_IOT_ENDPOINT = "a2n5uxoq3pd1ue-ats.iot.us-east-1.amazonaws.com";

const int AWS_IOT_PORT = 8883;










//=============================
// TOPICOS
//=============================

const char *TOPICOS_PUBLICAR[] = {

    "senai134/esp32/status",
    "senai134/esp32/log",
    "senai134/esp32/resposta"};

const int TOTAL_TOPICOS_PUBLICAR = 3;

const char *TOPICOS_RECEBER[] = {
    "senai134/esp32/comando",
    "senai134/esp32/config",
    "senai134/esp32/display"};

const int TOTAL_TOPICOS_RECEBER = 3;

//=============================
// DEBUG
//=============================

// 0 = sem mensagens
// 1 = apenas erros
// 2 = todas as mensagens
const int  DEBUG_NIVEL_INICIAL = 2;

// Pino usado para forçar todas as mensagens na inicialização
const int  PINO_HABILITA_DEBUG_COMPLETO = 4;

