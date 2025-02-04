#ifndef _WIFI_H_
#define _WIFI_H_

#include <cstring>
#include <WiFi.h>
#include <esp_wifi.h>
#include <string>

class Wifi {
    public:
       Wifi(const char* ssid, const char* pass);

       ~Wifi();

       void connect();

       void disconnect();

       bool status();

       const char* getSSID();

       const char* getPass();

       const char* local();

    private:
       char* wifiSSID;
       char* wifiPass;
       String ip;
}; 

#endif