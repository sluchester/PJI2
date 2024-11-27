#ifndef _MQTT_H_
#define _MQTT_H_

#include <cstring>
#include <ESP8266WiFi.h>
#include <ArduinoMqttClient.h>
#include <string>

using namespace std;

class Mqtt {
    public:
       Mqtt(const char* server, int port, const char* user, const char* pass);

       ~Mqtt();

       bool connect();

       void sendMessage(char topic[], char message[]);

       void receiveMessage(char topic[], void(*)(int));

       bool getStatus();

       const int connectError();

       const char* getUser();

       const char* getPass();

       const char* getServer();

      //  int read();

      //  void poll();

      //  int available();

      //  String messageTopic();

      //  void onMessage(void(*)(int));

      //  string getMessage();


    private:
       char* brokerServer;
       int brokerPort = 0;
       char* brokerUser;
       char* brokerPass;
       WiFiClient wifiClient;
       MqttClient mqttClient;
       string message;
}; 

#endif