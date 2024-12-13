//Fazer programação para o sensor LDR (Sensor de Luz)
#include "LDR.h"
#include <Arduino.h>

class LightSensor {

public:
    // Construtor
    LDR(int pin);
    
    // Método para inicializar a comunicação
    void begin();
    
    // Método para ler o valor do sensor
    int readValue();
    
    // Método para exibir o status de luminosidade
    void statusLuminosidade(int valorAnalogico);
    
private:
    int sensorPin;
};

#endif // LIGHT_SENSOR_H