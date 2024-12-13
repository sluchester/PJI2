//Fazer programação para o sensor LDR (Sensor de Luz)
#ifndef _LDR_H_
#define _LDR_H_

#include "LDR.h"

LDR::LightSensor(int pin) {
    sensorPin = pin;
}

void LDR::begin() {
    // Inicializa a comunicação serial
    Serial.begin(9600);
}

int LDR::readValue() {
    // Lê o valor do sensor no pino analógico
    return analogRead(sensorPin);
}

void LDR::statusLuminosidade(int valorAnalogico) {
    Serial.print("Analog Value = ");
    Serial.print(valorAnalogico);   // Valor bruto da leitura analógica

    // Definindo as faixas de luminosidade
    if (analogValue < 40) {
        Serial.println(" => Apagado");
    } else if (analogValue < 800) {
        Serial.println(" => Escurecendo");
    } else if (analogValue < 2000) {
        Serial.println(" => Ligado");
    } else if (analogValue < 3200) {
        Serial.println(" => Brilhante");
    } else {
        Serial.println(" => Muito Brilhante");
    }
}