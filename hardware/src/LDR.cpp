//Fazer programação para o sensor LDR (Sensor de Luz)
#include "LDR.h"

    //Construtor, inicializa o pino do sensor
    LDR::LDR(int pin){
        LDR::pin = pin;
    }

    //Mede e armazena um valor base para comparação
    void LDR::valorSensor(){
        currenteValor = analogRead(LDR::pin);
    }

    //Mede o valor atual com valorSensor() 
    //e define-o como o valor base (baseValue), para uso como referência em comparações futuras.
    void valorBaseSensor(){
        valorSensor();
        baseValor = currenteValor;
    }

    int LDR::getCorrente(){
        return currenteValor;
    }

    int LDR::getValorBase(){
        return baseValor;
    }

    //Determina o status do LDR com base em um limite.
    bool LDR::getStatus(){
        valorSensor();
        return currentValue < baseValue + 1000;
    }