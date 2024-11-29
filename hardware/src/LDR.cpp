//Fazer programação para o sensor LDR (Sensor de Luz)
#include "LDR.h"

const int LDR_PIN = 0; //Verificar qual a porta correta

void setup(){
    Serial.begin(9600);
}

void loop(){
    int statusLuz = analogRead(LDR_PIN);

    if(statusLuz == HIGH){
        Serial.println("Apagada");
    }else Serial.println("Ligada");
}
