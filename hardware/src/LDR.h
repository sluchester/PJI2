//Fazer programação para o sensor LDR (Sensor de Luz)
#ifndef _LDR_H_
#define _LDR_H_

#include <Arduino.h>


using namespace std;

class LDR{
    public:
    LDR(int pin);

    void setup();

    void loop();

    int getValor(); //Retorna o valor lido do LDR


    private:
  

};

#endif