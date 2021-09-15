//Small ESP32 library to make it easier to prit via TCP
//All included libraries should already be includerd in ESP32 arduino
//Setup the class with SimpleTCP
//In the setup add the begin() function
//Then print using print or println
//to check connection and update connection use checkConnection

#include "Arduino.h"
#include "WiFi.h"
#include "ESPmDNS.h"

class SimpleTCP
{
    public:
        SimpleTCP(char* ssid , char* password);
        void begin(char mDNS[] = "esp32");
        void println(char newString[]);
        void print(char newString[]);
        void checkConnection();
    private:
    char* _ssid;
    char* _password;
    WiFiServer wifiServer;
    WiFiClient client;
};