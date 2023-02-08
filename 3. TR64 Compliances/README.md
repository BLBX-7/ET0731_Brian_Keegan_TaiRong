
# TR 64 Compliance Checklist

A Checklist is important in assessing how secure the IoT based project is. Below is a compliance checklist we adhered to.

## Attack Surface 1: Phone App
### Checklist:
- TR 64 : CS-01 **[done]**

	- Random number generator employed 
    
application uses an online random number generator for OTP
     
- TR 64 : AP-01 **[done]**

	- Lock-out mechanism employed

User will get locked out after 3 incorrect attempts in the log in page.

- TR 64 : AP-02 **[done]**

	- Multi-factor authentication 

2 forms authentication(2FA), first requiring a user login which includes attempts with username and password. Second is an OTP sent to their registered email as a form of 2FA.   


## Attack Surface 2: Amazon Web Service(AWS)
### Checklist:
- TR 64 : DP-04 **[done]**

    - Access control mechanisms employed 

We have made use AWS' Identity and Access Management(IAM) to create user groups with different policies. The first group is an administrator group which has full access to AWS' service, 
the second group is an ReadOnly group. This policy grants permissions to only view resources and basic metadata across all AWS services.

- TR 64 : AP-02 **[done]**

    - Secured login using Google authenticator 

For both user and root access, 2FA is employed through the AWS' google authentication 

      
- TR 64 : MT-01 **[done]**
	
	- Stong Password policy is enforced for user login

For user and root accounts, it uses AWS' default Password Policy

- TR 64: RS-03 **[done]**

   - AWS Shield employed
   
AWS Shield Standard defends against most common, frequently occurring network and transport layer DDoS attacks.

- TR 64: AU-01 **[done]**

   - significant events recorded
   
 We have made use AWS' CloudTrail service to record activities being performed in our console.
    
## Attack Surface  3: Azure  SQL Database
### Checklist:
- TR 64: CS-03

  - AES encryption uaing Transport Data encryption

Azure SQL database makes use of Transport Data Encyrption(TDE) which adds a layer of security to help protect data at rest from unauthorized or offline access to raw files or backups.
It encrypts the entire database using an AES encryption algorithm.
   
- TR 64: IA-01

  - User credential hashed

The users password and email has been hashed in the database and the communication between the user and database is encrypted
    
- TR 64: NP-03

  - Transport layer security employed
   
Azure SQL database will enforce encryption (SSL/TLS) at all times for all connections.
This ensures all data is encrypted "in transit" between the client and server irrespective of the setting of Encrypt or TrustServerCertificate in the connection string

- TR 64: NP-05/NP-04

  - Segeregation of communication channels employed
   
We have made use of Azure SQL database's firewall rules to allow specified addresses into the server
    

- TR 64: RS-04
 
  - Back-up system deployed

Azure SQL database has a service and compute tier, which allows for backup storage redundancy

- TR 64: AU-01

  - Significant events recorded

Azure SQL database has a event logging service which allows administrators to see the history of activities taking place within the server
	     

## Attack Surface 4: ThingSpeak cloud

- TR 64 : NP-04

	- Secure connectivity with MQTT

We are sending our MQTT messages over port 8883 also known as TLS port.



## Attack Surface 5: ESP32

- TR 64 : NP-04

	- Secure connectivity with MQTT

We are sending our MQTT messages over port 8883 also known as TLS port.


    
## Attack Surface 4; System as a whole (REALLY NOT SURE)
### Checklist:
- TR 64 : LP-01  **[done]**

    - Conducted threat modeling to identify threats
    The team used the STRIDE tool to identify threats on the network architecture, which then led to this compliance checklist. 
    
- TR 64 : LP-02 

    - System designed in a secure way **[done]**
    
    All HTTP and MQTT versions of the web app has been changed to HTTPS and MQTTS, some prototyping ideas such as ESP32 web server has also been abolished in order to decerase attack surface
