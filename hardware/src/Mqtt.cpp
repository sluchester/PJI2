#include "Mqtt.h"

using namespace std;

//Este é o construtor da classe ELabMqtt
//Ele recebe como parâmetro o endereço do servidor MQTT, a porta, o usuário e a senha
Mqtt::Mqtt(const char* server, int port, const char* user, const char* pass) : mqttClient(wifiClient) {
    // Aloca espaço para as variáveis brokerServer, brokerPort, brokerUser e brokerPass
    this->brokerServer = strdup(server);
    this->brokerPort = port;
    this->brokerUser = strdup(user);
    this->brokerPass = strdup(pass);

    // Define o usuário e a senha do servidor MQTT
    mqttClient.setUsernamePassword(user, pass);
}

//Este é o destrutor da classe ELabMqtt
Mqtt::~Mqtt() {
    free(brokerServer);
    free(brokerUser);
    free(brokerPass);
}

//Este método conecta o ESP12E ao servidor MQTT
bool Mqtt::connect(){
    return mqttClient.connect(brokerServer, brokerPort);
}

//Este método retorna o estado da conexão
const int Mqtt::connectError(){
    return mqttClient.connectError();
}

// Este método que envia a mensagem para o servidor, recebe como parâmetro o tópico e a mensagem
void Mqtt::sendMessage(char topic[], char message[]){ 
    //Monitoramento do estado da conexão
    mqttClient.poll();
    //Se prepara para mandar mensagem no tópico
    mqttClient.beginMessage(topic);
    //Manda mensagem para o tópico
    mqttClient.print(message);
    //Finaliza a mensagem
    mqttClient.endMessage();
}

//Este método recebe como parâmetro o tópico e a função de callback
void Mqtt::receiveMessage(char topic[], void(*callback)(int)){
    //Chama a função de callback quando receber mensagem no tópico
    mqttClient.onMessage(callback);
    //Se inscreve no tópico
    mqttClient.subscribe(topic);
}

//Este garante a conexão com o servidor MQTT
void Mqtt::poll(){
    //Monitoramento do estado da conexão
    mqttClient.poll();
}

//Este método retorna o brokerUser, que é o usuário do servidor MQTT
const char* Mqtt::getUser() {
    return brokerUser;
}

//Este método retorna o brokerPass, que é a senha do servidor MQTT
const char* Mqtt::getPass() {
    return brokerPass;
}

//Este método retorna o brokerServer, que é o endereço do servidor MQTT
const char* Mqtt::getServer() {
    return brokerServer;
}

//Este método verifica se ainda possui caracteres a serem recebidos
int Mqtt::available() {
    return mqttClient.available();
}

//Este método lê os caracteres recebidos
int Mqtt::read() {
    return mqttClient.read();
}

//Este método retorna o tópico da mensagem recebida
String Mqtt::messageTopic(){
    return mqttClient.messageTopic();
}

//Este método ele chama a função de callback quando a mensagem é recebida
void Mqtt::onMessage(void(*callback)(int)){
    mqttClient.onMessage(callback);
}

//Este método retorna a mensagem recebida
string Mqtt::getMessage() {
    return message;
}
