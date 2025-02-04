#include "AC.h"

AC::AC(int pin)
    : ac(pin, DHT22){
        ac.begin();
        pinMode(pin, INPUT);
}

float AC::temperatura(){
    float Temperature = ac.readTemperature(); // Obtém os valores da temperatura
    return Temperature;
}

float AC::umidade(){
    float Humidity = ac.readHumidity(); // Obtém os valores da temperatura
    return Humidity;
}

/*
#include "AC.h"

AC::AC(int pin)
    : pin(pin), ac(pin, DHT22) {  // Agora 'ac' é um membro da classe
    ac.begin();
    pinMode(pin, INPUT);
}

float AC::temperatura() {
    return ac.readTemperature(); // Retorna diretamente a temperatura
}

float AC::umidade() {
    return ac.readHumidity(); // Retorna diretamente a umidade
}*/