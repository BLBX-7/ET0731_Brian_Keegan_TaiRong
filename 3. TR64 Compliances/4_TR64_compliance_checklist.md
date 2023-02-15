
# TR 64 Compliance Checklist
TR64 is used as a guideline to safegaurd CIA for our IoT system. It provides holistic approches in identifying and mitigating threats and vulnerabilities.

Attack Surface|TR64 Reference|Description
--------------|--------------|-----------
Phone app|MT-01, CS-01, IA-01, AP-01, AP-02|Strong password policies, Employment of random number generator, Secure storage of user credentials, protection against repeated attempts & Multi factor Authentication 
Amazon Web Service|NP-04, DP-04, AP-02, MT-01, RS-03, UA-01|Secured connectivity is enforced, Access control mechanism, Multi-Factor Authentication, Strong password policies, able to withstand malicious attacks & significant events recorded
Azure SQL Database|MT-01, CS-03, IA-01, NP-03, NP-04, RS-04, AU-01|Strong password policies, AES encryption, Client credential's stored securely, transport layer security employed, Whitelisting, regular backup of system data, significant events recorded
Thingspeak MQTT Broker|MT-01, NP-04|Strong password policies, Secure connectivity based on industry best practices
Hardware|AP-04|Tamper resistant hardware
Entire System|LP-01, LP-02, LP-07|Conducted threat modeling to identify threats, System is designed and developed using secure systems engineering approach and best practices, Penetration-testing and vulnerability assessment


## Attack Surface 1: Phone App
### Checklist:
- TR 64: MT-01 **[done]**
	
	- Stong Password policy is enforced for user login

User enforces default strong Password Policy.
![Physical system architecture](Img/) 

- TR 64 : CS-01 **[done]**

	- Random number generator employed 
    
The Phone application will generate an OTP and send it to Amazon Web Services' simple email service (SES), the generated OTP will then be sent to the user's email, user keys in the OTP and is able to enter the application. Confirming it is him/her.

![Physical system architecture](Img/) 

- TR 64 : IA-01 **[done]**

	- User's Password and Email is hashed in database
 
User will input their username and password at the login page, and as the SQL database has the hashed variant of the user's credentials, it (the Phone app) will convert the user inputted email and password (in plain text form) to its hashed form before comparing it with the hashed credentials stored in the database.

![Physical system architecture](Img/) 

- TR 64 : AP-01 **[done]**

	- Lock-out mechanism employed to protect against repeated unauthorised attempts

Attacker will attempt a brute-force attack to login into the app. With the lock-out mechanism, after 3 attempts the attacker wll be locked out and is no longer able to attempt anymore passwords. 

![Physical system architecture](Img/) 

- TR 64 : AP-02 **[done]**

	- Multi-factor authentication 

2 Factor Authentication (2FA), first requiring a user to login with his/her register email and complex password. Second is an OTP sent, that has to be cross-verified in application, to their registered email as the form of 2FA.   

![Physical system architecture](Img/) 

## Attack Surface 2: Amazon Web Service(AWS)
### Checklist:
- TR 64 : NP-04 **[done]**

    - Secured connectivity is enforced
    
Android Appliaction communicates with Amazon SES SMTP endpoint on port 587 (the communication port used by AWS SES for STARTTLS communication).

- TR 64 : DP-04 **[done]**

    - Access control mechanisms employed 

We have made use AWS' Identity and Access Management (IAM) to create user groups with different policies. The first group is an administrator group which has full access to AWS' service, the second group is an ReadOnly group. This policy grants permissions to only view resources and basic metadata across all AWS services.

![Physical system architecture](Img/) 

- TR 64: AP-02 **[done]**

    - Secured login using Google authenticator 

For both user and root access, 2FA is employed through the AWS' google authentication feature. This means that attackers will still have to get the six digit code to login to the console, every 30 seconds our 6 digit code will always change to ensure security.

![Physical system architecture](Img/) 
      
- TR 64: MT-01 **[done]**
	
	- Stong Password policy is enforced for user login

For user and root accounts, it enforces AWS' default Password Policy. 

![Physical system architecture](Img/) 

- TR 64: RS-03 **[done]**

   - AWS Shield employed 
   
AWS Shield Standard is automatically available for AWS' management console. It defends against most common, frequently occurring network and transport layer DDoS attacks.

- TR 64: AU-01 **[done]**

   - Significant events recorded
   
 We have made use AWS' CloudTrail service to record activities being performed in our console.
 
![Physical system architecture](Img/) 


## Attack Surface 3: Azure SQL Database
### Checklist:
- TR 64: MT-01 **[done]**
	
	- Stong Password policy is enforced for user login

For user accounts, it enforces default strong Password Policy.

![Physical system architecture](Img/) 

- TR 64: CS-03 **[done]**

  - AES encryption using Transport Data encryption

Azure SQL database makes use of Transport Data Encyrption (TDE) which adds a layer of security to help protect data at rest from unauthorized or offline access to raw files or backups, encrypting the entire database using an AES encryption algorithm.
   
- TR 64: IA-01 **[done]**

  - User credential are hashed in the database

Using SHA256, we hashed the user's email and password and saved it to the SQL Database.

![Physical system architecture](Img/) 
    
- TR 64: NP-03 **[done]**

  - Transport layer security employed
   
Azure SQL database will enforce encryption (SSL/TLS) at all times for all connections. This ensures all data is encrypted and secured "in-transit" between the user and server because of the connection string used: Encrypt=True and TrustServerCertificate=False. 

- TR 64: NP-04 **[done]**

  - Secure connectivity using whitelisting
   
We have made use of Azure SQL database's firewall rules to only allow IP addresses, set in the SQL server, to access the database (essentially a whitelist).

![Physical system architecture](Img/) 
    
- TR 64: RS-04 **[done]**
 
  - Back-up system deployed

Azure SQL database, by default, automatically backs up the databases with no user action needed
![Physical system architecture](Img/) 

- TR 64: AU-01 **[done]**

  - Significant events recorded

Azure SQL database has a event logging service which allows administrators to see the history of activities taking place within the server
![Physical system architecture](Img/) 	     

## Attack Surface 4: ThingSpeak MQTT Broker
- TR 64 : MT-01 **[done]**

	- Strong password policies

In order for a client to publish or subscribe to an MQTT broker, the client has to provide generated strong username and password for authentication and authorization.
![Physical system architecture](Img/) 

- TR 64 : NP-04 **[done]**

	- Secure connectivity with MQTT

We are sending our MQTT messages over port 8883 also known as TLS port. (Employing TLS when using MQTT)
![Physical system architecture](Img/) 

## Attack Surface 5: Hardware

- TR 64 : AP-04 **[Done through Concept]*

	-  Provide a Temper resistant case for Hardware 

 By using Security Torx screws, we will secure our hardware by applying the screws into the box system. The screwdriver needed to unbox the system is very speciific. Thus, providing better security against physical tampering of the hardware. The tamper resistant case will also prevent our SD card in the ESP32-CAM to be stolen or destroyed.
 
 ![Physical system architecture](Img/) 
    
## Attack Surface 6: System as a whole
### Checklist:
- TR 64 : LP-01  **[done]**

    - Conducted threat modeling to analyse threats
  
 The team used the DREAD tool to Rate threats on the network architecture, which then led to this compliance checklist. 
    
- TR 64 : LP-02 

    - System designed in a secure way **[done]**
    
 We made use of MQTT with TLS for our communication protocol to ensure security for data in transit. Communication with cloud services also done in a secure way, and data stored in cloud are auto encrypted with security.
    
- TR 64 : LP-07 

    - Penetration-testing or vulnerability assessment conducted **[done]**

Through the use of Kali linux and other theoratical attacks, we were able to perform penetration-testing and assess the vulnerability of our system.

# Next Up
<a href="/4. Vulnerability Assessment/5_Vulnerability_assessment.md">5. Vulnerability Assessment </a>
