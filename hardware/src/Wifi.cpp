#include "Wifi.h"

//Este método é o construtor da classe, ele é chamado quando um objeto é criado
Wifi::Wifi(const char* ssid, const char* pass) {
    //Aqui é feita uma cópia dos parâmetros passados para o construtor
    this->wifiSSID = strdup(ssid);
    this->wifiPass = strdup(pass);
}

//Este método librei a memória alocada para os parâmetros do ElabWifi
Wifi::~Wifi() {
    free(wifiSSID);
    free(wifiPass);
}

//Este método se conecta na rede Wifi
void Wifi::connect() {
    WiFi.enableInsecureWEP(); 
    WiFi.mode(WIFI_STA);
    WiFi.begin(wifiSSID, wifiPass);
}

//Este método desconecta da rede Wifi
void Wifi::disconnect() {
    WiFi.disconnect();
}

//Este método retorna o status da conexão Wifi
bool Wifi::status(){
    return WiFi.status() == WL_CONNECTED;
}

//Este método retorna o SSID da rede Wifi
const char* Wifi::getSSID() {
    return wifiSSID;
}

//Este método retorna a senha da rede Wifi
const char* Wifi::getPass() {
    return wifiPass;
}

//Este método retorna o IP local da rede Wifi
String Wifi::localIP(){
    return WiFi.localIP().toString();
}