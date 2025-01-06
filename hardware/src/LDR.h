//Fazer programação para o sensor LDR (Sensor de Luz)
#ifndef _LDR_H_
#define _LDR_H_

#include <Arduino.h>

class LDR{
    public:
        // Construtor
        LDR(int pin = 15);

        // Valor do Sensor
        void valorSensor();
        
        //Mede e armazena um valor base para comparação.
        void valorBaseSensor();

        int getCorrete();

        //Retorna o valor base armazenado
        int getrValorBase();

        //Determina o status do LDR com base em um limite.
        bool getStatus();

        ~LDR() {};


    private:
        //Faixa de valores para o LDR
        int VMax = 4095;
        int VMin = 2500;

        // int PorcentagemMin = 0;
        // int PorcentagemMax = 100;
        int pin = 0;

        //Valor base para comparação
        int baseValor = 0;

        //Valor atual do sensor
        int currenteValor = 0;
};

#endif
