# SimpleTCP
Small ESP32 library to make it easier to prit via TCP  
All included libraries should already be included in ESP32 arduino  
The mDSN is set to ESP32 so ESP32.local can be used if zeroconf is set up

note, ADC2 does not work with WiFi wich is GPIO0, GPIO2, GPIO4, GPIO12 - GPIO15, GOIO25 - GPIO27


How to use:
1. Initialise the SimpleTCP class
2. In the setup add the begin() function
3. In the main loop use checkConnection(), to check the connection and try to reconnect if the connection is lost
4. To print the "ptint" and "println" function can be used


API
SimpleTCP myTCP(ssid, password)

myTCP.begin()

myTCP.print(text)

myTCP.println(text)

myTCP.checkConnection()

install by adding the line below in the platformio.ini text file

```
lib_deps =
  https://github.com/PotatoMill/SimpleTCP.git
```
