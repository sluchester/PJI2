#include <base64.h>
#include <HTTPClient.h>
#include <WiFi.h>
#include "string.h"
#include <FreeRTOS.h>
#include <Task.h>

const char* ssid     = "LuanGalaxy22Plus";     // your network SSID (name of wifi network)
const char* password = "ismt5131"; // your network password

const char *server = "script.google.com";  // Server URL

//const char *GScriptId = "1vxQ1JhOYHAAWV5OfgQz30TILqFPsZ_J-pCbBPeH5H2U"; //planilha teste
const char *GScriptId = "AKfycbw0LKF0WB2zTUAvLcaHzsf6aE8XoKk0UZjPvL6D3stXECL7ovhI-X4a6UKbmxkQnh6E7Q";
                
const int httpsPort = 443;
//na minha rede de casa deu como a reposta era 200
//const int httpsPort = 200;

TaskHandle_t Task1;
TaskHandle_t Task2;

WiFiClient client;

void setup() {
  Serial.begin(115200); 

  connect_wifi();

  //create a task that will be executed in the Task1code() function, with priority 1 and executed on core 0
  xTaskCreatePinnedToCore(
                    Task1code,   /* Task function. */
                    "Task1",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Task1,      /* Task handle to keep track of created task */
                    1);          /* pin task to core 0 */                  
 
  //create a task that will be executed in the Task2code() function, with priority 1 and executed on core 1
  xTaskCreatePinnedToCore(
                    Task2code,   /* Task function. */
                    "Task2",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Task2,      /* Task handle to keep track of created task */
                    0);          /* pin task to core 1 */
 
}

void loop() {
 //disableCore0WDT();
 }