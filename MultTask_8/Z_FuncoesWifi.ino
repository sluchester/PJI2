void connect_wifi(void)
{
  Serial.println("Connecting to wifi: ");
  Serial.println(ssid);
  Serial.flush();
  WiFi.begin(ssid, password);

  int retry_count = 0;
  while (WiFi.status() != WL_CONNECTED && retry_count < 10)
  {
    delay(1000);
    Serial.print(WiFi.status());
    Serial.print(".");
      if (retry_count == 10) {
        ESP.restart(); // Reinicia o dispositivo após várias tentativas
        Serial.print("cant connect to wifi");
        delay(10000);
        Serial.print("should leave...");
        delay(10000);
    }
    retry_count++;
  }

  /*if (retry_count == 10) {
    //ESP.restart(); // Reinicia o dispositivo após várias tentativas
    Serial.print("cant connect to wifi");
    delay(10000);
    Serial.print("should leave...");
    delay(10000);
  }*/

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void enviarMedicao()
{
  HTTPClient http;

  tempoEnvio = millis() - tempoEnvio;
  /*String url = String("https://script.google.com") + "/a/macros/aluno.ifsc.edu.br/s/" + GScriptId + "/exec?" + "value1=" + 
                      tensaoFinal + "&value2=" + String(correnteFinal, 2) + "&value3=" + tempoEnvio;*/
  /*String url = String("https://script.google.com") + "/macros/s/" + GScriptId + "/exec?" + "value1=" + tensaoFinal + "&value2=" + 
                      String(correnteFinal, 2) + "&value3=" + tempoEnvio;*/
  String url = String("https://script.google.com") + "/macros/s/" + GScriptId + "/exec?" + "value1=" + 552 + "&value2=" + 
                      String(1235, 2) + "&value3=" + 5;
  tempoEnvio = millis();
  
  Serial.println("Making a request");
  Serial.println(url);

  http.begin(url.c_str()); //Specify the URL and certific22Plusate
  http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
  int httpCode = http.GET();
  Serial.println(httpCode);
  //int httpCode = 200;
  String payload;
  /*if (httpCode > 0) { //Check for the returning code
    payload = http.getString();

    Serial.println("Porta http " + httpCode);
    Serial.println(payload);
    //testdrawstyles(payload);
    //if (httpCode == 200 or httpCode == 201) tempPing.Saida(0);  
  }
    else {
    Serial.println("Error on HTTP request");
  }
  */
  if (httpCode > 0) {
    Serial.println("HTTP Response Code: " + String(httpCode));
    payload = http.getString();
    Serial.println("Payload: " + payload);
  } else {
    Serial.println("Error on HTTP request, Code: " + String(httpCode));
  }
  http.end();
}