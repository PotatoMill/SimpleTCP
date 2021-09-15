#include "SimpleTCP.h"

SimpleTCP myTCP("ssid","password");

void setup() {
    Serial.begin(115200);
    myTCP.begin();
}
 
void loop() {
    myTCP.checkConnection();
    myTCP.println("test text");
    delay(500);
}
