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
        SimpleTCP(char* ssid ,char* password);
        void begin(const char mDNS[]);
        void println(const char newString[]);
        void println(int newString);
        void print(const char newString[]);
        void checkConnection();
        int read();
        String readline();
        int available();
    private:
    char* _ssid;
    char* _password;
    WiFiServer wifiServer;
    WiFiClient client;
};