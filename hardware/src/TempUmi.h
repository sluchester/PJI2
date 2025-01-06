#ifndef _TempUmi_H_
#define _TempUmi_H_

#include <Arduino.h>
#include "DHT.h" //Biblioteca para o sensor de temperatura e umidade (Sensor utilizado: DHT22)

//DHT22 (AM2302): Sensor mais avançado, com maior precisão e faixa de medição.
//Temperatura: -40–80°C, precisão ±0.5°C.
//Umidade: 0–100%, precisão ±2–5%.

class TempUmi{
    public:

        //Construtor
        TempUmi(int pin = 12);

        //Realiza uma leitura dos valores de temperatura e umidade a partir do sensor.
        void valorSensor();

        //Mede a temperatura atual e a define como o valor base 
        void valorBaseTemperatura();

        //Retorna o valor da temperatura atual (
        float getTemperaturaAtual();

        //Retorna o valor base da temperatura
        float getValorBaseTemperatura();

        //Retorna o valor anterior da temperatura 
        float getTemperaturaAnterior();

        //Retorna o valor da umidade atual 
        float getUmidadeAtual();

        //Retorna o valor da umidade anterior
        float getUmidadeAnterior();

        //Destrutor
        ~TempUmi() {};


    private:
        float baseTemperatura = 0;
        float temperaturaAnterior = 0;
        float temperaturalAtual = 0;
        float UmidadeAnterior = 0;
        float UmidadeAtual = 0;
        DHT dht;



};

#endif