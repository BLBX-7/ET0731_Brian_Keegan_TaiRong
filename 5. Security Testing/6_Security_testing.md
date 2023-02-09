# Security Testing
## Accessing Network

## With Kali Linux
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
