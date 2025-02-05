/*void Task2code( void * pvParameters ){
 
   for(;;){
   
    enviarMedicao();

    }
}*/

void Task2code(void * pvParameters) {
    for (;;) {
        enviarMedicao();
        vTaskDelay(10000 / portTICK_PERIOD_MS); // Envia a cada 10 segundos
    }
}

