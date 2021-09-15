# SimpleTCP
Small ESP32 library to make it easier to prit via TCP
All included libraries should already be includerd in ESP32 arduino

How to use:
1. Initialise the SimpleTCP class
2. In the setup add the begin() function
3. In the main loop check connection and update connection use checkConnection
4. To print the "ptint" and "println" function can be used


API
SimpleTCP myTCP(ssid, password)

myTCP.begin()

myTCP.print(text)

myTCP.println(text)

myTCP.checkConnection()

