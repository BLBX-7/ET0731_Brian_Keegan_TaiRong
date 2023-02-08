## Description </br>
Our ESP8266 is the main physical mechanism, in charge of locking and securing the place of
interest. It will be controlled, via the internet, by the Android application. 

### Devices needed </br>
1. ESP8266 (Microcontroller of our door)
2. ESP32 Camera (Surveillance of our door)
2. Servo Motor (Physical lock)
3. Ultra-sonic Sensor (Auto-relocking of door/Taking of picture)

### Door algorithm </br>
Upon unlocking via application, the door works as follows...
1. ESP8266 subscribe to ThingSpeak MQTT broker to wait for the message "unlocked".
2. Upon receiving "unlocked" MQTT message, servo motor turns to unlock the smart door.
3. If Ultra-sonic sensor reads above a certain distance threshold, it indicates that Smart Door is open.
4. If smart door is open and smart door is unlocked, initiate picture taking of doorway via ESP32-CAM.
5. If Ultra-sonic sensor reads that below distance threshold, it means smart door is closed.
6. If smart door is closed, it will auto-lock the door but turning the servo motor.
