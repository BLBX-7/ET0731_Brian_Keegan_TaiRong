# Description </br>
Our ESP8266 is the main physical mechanism, in charge of locking and securing the place of
interest. It will be controlled, via the internet, by the Android application. 

# Devices Needed </br>
1. ESP8266 (Microcontroller of our door)
2. ESP32-Camera (Surveillance of our door)
2. Servo Motor (Physical lock)
3. Ultra-sonic Sensor (Auto-relocking of door/Taking of picture)

# Door Algorithm </br>
Upon unlocking via application, the door works as follows...
1. Initiallly, Smart Door is locked with the servo motor at its lock position.
2. ESP8266 subscribe to ThingSpeak MQTT broker to wait for the message "unlocked".
3. Upon receiving "unlocked" MQTT message, servo motor turns to unlock the smart door.
4. Once the door is unlocked, it will keep waiting for the door, through the use of an ultra-sonic sensor
4. Ultra-sonic sensor reads above a certain distance threshold to indicate that door is open.
5. Once the door is opened, inititate picture taking of doorway via ESP32-Camera.
6. While door is opened, wait until door is closed.
7. Ultra-sonic sensor reads below distance threshold to indicate that door is closed.
8. Once door is closed, it will auto-lock the door but turning the servo motor.
9. Wait for MQTT message "unlocked" again.

# Hardware Integration </br>
- Front View:
![- Front View](/Img/HardwareConnections.jpeg) </br>
- Side View:
![- Side View](/Img/HardwareConnections_2.jpeg)
