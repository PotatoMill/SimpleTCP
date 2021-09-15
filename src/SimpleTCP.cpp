//Small ESP32 library to make it easier to prit via TCP
//All included libraries should already be includerd in ESP32 arduino
//Setup the class with SimpleTCP
//In the setup add the begin() function
//Then print using print or println
//to check connection and update connection use checkConnection

#include "SimpleTCP.h"
#include "Arduino.h"
#include "WiFi.h"
#include "ESPmDNS.h"

SimpleTCP::SimpleTCP(char* ssid , char* password){
    _ssid = ssid;
    _password = password;
    WiFiServer wifiServer(80);
    WiFiClient client;
}
void SimpleTCP::begin(){
    WiFi.begin(_ssid, _password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi..");
    }

    if(!MDNS.begin("esp32")){
        Serial.println("Error starting mDNS");
    }

    Serial.println("Connected to the WiFi network");
    Serial.println(WiFi.localIP());

    wifiServer.begin();
    MDNS.addService("http", "tcp", 80);
}
void SimpleTCP::println(char newString[]){
    if(client.connected()){
        client.println(newString);
        Serial.print("Sending: ");
        Serial.println(newString);
    }
    else Serial.println("failed to send info");
}
void SimpleTCP::print(char newString[]){
    if(client.connected()){
        client.print(newString);
        Serial.print("Sending: ");
        Serial.println(newString);
    }
    else Serial.println("failed to send info");
}
void SimpleTCP::checkConnection(){
    if(wifiServer.hasClient()){ //sjekker om er det en klient som prøver å koble til. "Er det noen i butikken som vil sjoppe?"
    if(client.connected()){ //hvis det allerede er koblet til skal den ikke gjøre noe
      Serial.println("New client tries to connect ");
    }
    else { //hvis det ikke er koblet til skal den stoppe tilkoblingen og starte å oppdatere klient objektet
      client.stop();
      Serial.println("stopped connection ");
      client = wifiServer.available();
      Serial.println("looking for new client");
    }
  }
}