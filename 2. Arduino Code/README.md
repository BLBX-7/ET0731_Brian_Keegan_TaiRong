# Description </br>
Our ESP8266 is the main physical mechanism, in charge of locking and securing the place of
interest. It will be controlled, via the internet, by the Android application. 

# Devices Needed </br>
1. ESP8266 (Microcontroller of our door)
2. ESP32 Camera (Surveillance of our door)
2. Servo Motor (Physical lock)
3. Ultra-sonic Sensor (Auto-relocking of door/Taking of picture)

# Door Algorithm </br>
Upon unlocking via application, the door works as follows...
1. Smart Door is locked with the servo motor at a certain position.
2. ESP8266 subscribe to ThingSpeak MQTT broker to wait for the message "unlocked".
3. Upon receiving "unlocked" MQTT message, servo motor turns to unlock the smart door.
4. If Ultra-sonic sensor reads above a certain distance threshold, it indicates that Smart Door is open.
5. If smart door is open and smart door is unlocked, initiate picture taking of doorway via ESP32-CAM.
6. If Ultra-sonic sensor reads that below distance threshold, it means smart door is closed.
7. If smart door is closed, it will auto-lock the door but turning the servo motor.
