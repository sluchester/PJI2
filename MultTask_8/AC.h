#ifndef __AC__
#define __AC__

#include <Arduino.h>
#include <SimpleDHT.h>
#include "DHT.h"
#include <string>

// #define DHTTYPE DHT22     // DHT 22  (AM2302), AM2321

class AC {
    public:
        AC(int pin = 4);

        float temperatura();

        float umidade();

    private:
        int pin = 0;
        float Temperature = 0;
        float Humidity = 0;
        DHT ac;
};

#endif