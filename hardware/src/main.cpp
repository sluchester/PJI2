#include <Arduino.h>
#include "Mqtt.h"
#include "Wifi.h"
#include "LDR.h"
#include "AC.h"
#include <string.h>
#include <ArduinoMqttClient.h>
#include <SPI.h>
// Declaracao do servidor e da sua porta
char brokerServer[] = BROKER_SERVER;
int brokerPort = BROKER_PORT;

// Declaracao do usuario e senha do broker
char brokerUser[] = BROKER_USER;
char brokerPass[] = BROKER_PASS;

// Declaracao do ID do dispositivo
char ID[] = DEVICE_ID;

// Declaração do nome e senha da rede WiFi que o dispositivo irá se conectar
char SSID[] = WIFI_SSID;
char PASS[] = WIFI_PASS;

// Declaração do nome do dispositivo
char name[] = DEVICE_NAME;

// Tópico
char topic[16] = "SmartBox/";

// Mensagem de registro
char registerJsonMessage[256];

// Criando o objeto mqtt 
Mqtt mqtt(brokerServer, brokerPort, brokerUser, brokerPass);

// Criando o objeto wifi
Wifi wifi(SSID, PASS);

// Criando o objeto ldr
LDR ldr;

// Criando o objeto ac
AC ac;



void setup(){
    // Inicializa a comunicação serial
    Serial.begin(115200);
    delay(1000);

    // Conecta na rede WiFi
    Serial.print("Conectando na rede WiFi");
    wifi.connect();

    // Aguarda a conexão
    while (wifi.status()  != WL_CONNECTED ){
        Serial.print(".");
        delay(1000);
    }
    // Mostra o IP local
    Serial.println(WiFi.localIP());


    // Inicializa o mqtt
     if (mqtt.connect()) {		
      Serial.println("Conectado no broker MQTT com sucesso!");
    } else {
        Serial.print("Erro ao conectar-se no broker! Erro = ");
        Serial.println(mqtt.connectError());
    }

    // // Initial message to register on the server
    // sprintf(registerJsonMessage, "{\"name\":\"%s\",\"id\":\"%s\"}", name, ID);
    // mqtt.sendMessage(registerTopic, registerJsonMessage);

    // // Inicializa o ldr
    // ldr.begin();
    // ldr.configure();

    // // Inicializa o ac
    // ac.begin();
}

void loop() {
    // Mantém a conexão MQTT ativa
    // if (!mqtt.CONNECTED()) {
    //     Serial.println("MQTT desconectado. Tentando reconectar...");
    //     while (!mqtt.connect()) {
    //         Serial.print(".");
    //         delay(2000);
    //     }
    //     Serial.println("Reconectado ao MQTT!");
    // }

    // // mqtt.loop();  // Mantém a comunicação MQTT ativa
    // delay(1000);


}
