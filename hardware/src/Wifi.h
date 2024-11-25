#ifndef _WIFI_H_
#define _WIFI_H_

#include <cstring>
#include <ESP8266WiFi.h>

class Wifi {
    public:
       Wifi(const char* ssid, const char* pass);

       ~Wifi();

       void connect();

       void disconnect();

       bool status();

       const char* getSSID();

       const char* getPass();

       String localIP();

    private:
       char* wifiSSID;
       char* wifiPass;
}; 

#endif