
# TR 64 Compliance Checklist

A Checklist is important in assessing how secure the IoT based project is. Below is a compliance checklist we adhered to.

## Attack Surface 1: Phone App
### Checklist:
- TR 64 : CS-01 **[done]**

	- Random number generator employed 
    
The Phone application will generate an OTP and send it to Amazon Web Services' simple email service(SES), the generated OTP will then be sent to the user's email, user keys in the OTP and is able to enter the application. Confirming it is him/her.
     
- TR 64 : AP-01 **[done]**

	- Lock-out mechanism employed to protect against repeated unauthorised attempts

attacker will attempt a brute-force attack to login into the app. With the lock-out mechanism, after 3 attempts the attacker wll be locked out and is no longer able to attempt anymore passwords. 

- TR 64 : AP-02 **[done]**

	- Multi-factor authentication 

2 forms authentication(2FA), first requiring a user login which includes attempts with username and password. Second is an OTP sent to their registered email as a form of 2FA.   


## Attack Surface 2: Amazon Web Service(AWS)
### Checklist:
- TR 64 : DP-04 **[done]**

    - Access control mechanisms employed 

We have made use AWS' Identity and Access Management(IAM) to create user groups with different policies. The first group is an administrator group which has full access to AWS' service, the second group is an ReadOnly group. This policy grants permissions to only view resources and basic metadata across all AWS services.

- TR 64: AP-02 **[done]**

    - Secured login using Google authenticator 

For both user and root access, 2FA is employed through the AWS' google authentication feature. This means that attackers will still have to get the six digit code to login to the console, every 30 seconds our 6 digit code will always change to ensure security.

      
- TR 64: MT-01 **[done]**
	
	- Stong Password policy is enforced for user login

For user and root accounts, it uses AWS' default Password Policy. 

	- Minimum Password length: 8 
	- Password strength include a minimum of three of the following mix of character types: Uppercase, Lowercase, Numbers & Non-alphanumeric characters 

- TR 64: RS-03 **[done]**

   - AWS Shield employed 
   
AWS Shield Standard is automatically available for AWS' management console. It defends against most common, frequently occurring network and transport layer DDoS attacks.

- TR 64: AU-01 **[done]**

   - significant events recorded
   
 We have made use AWS' CloudTrail service to record activities being performed in our console.
 
 	- This displays events such as: 
		- User login, logout and unsuccessful authentication attempts
		- Changes in access privilages
		- creation, modification & deletion of data
	and many more...

		
    
## Attack Surface 3: Azure  SQL Database
### Checklist:
- TR 64: CS-03 **[done]**

  - AES encryption using Transport Data encryption

Azure SQL database makes use of Transport Data Encyrption(TDE) which adds a layer of security to help protect data at rest from unauthorized or offline access to raw files or backups, encrypting the entire database using an AES encryption algorithm.
   
- TR 64: IA-01 **[done]**

  - User credential are hashed in the database

Using SHA256, we hashed the user's email and password and saved it to the database. As for the server's credentials, the Azure SQL database will provide a hashed version of the administrator's email and password for use in our Android application program (such that we don't login with plain text in our application program). 
    
- TR 64: NP-03 **[done]**

  - Transport layer security employed
   
Azure SQL database will enforce encryption (SSL/TLS) at all times for all connections. This ensures all data is encrypted "in transit" between the user and server irrespective of the setting of Encrypt or TrustServerCertificate in the connection string

- TR 64: NP-04 **[done]**

  - Secure connectivity using whitelisting
   
We have made use of Azure SQL database's firewall rules to only allow IP addresses, set in the SQL server, to access the database (essentially a whitelist)
    
- TR 64: RS-04 **[done]**
 
  - Back-up system deployed

Azure SQL database has a service and compute tier, which allows for backup storage redundancy

- TR 64: AU-01 **[done]**

  - Significant events recorded

Azure SQL database has a event logging service which allows administrators to see the history of activities taking place within the server
	     

## Attack Surface 4: ThingSpeak cloud

- TR 64 : NP-04 **[done]**

	- Secure connectivity with MQTT

We are sending our MQTT messages over port 1883 also known as TLS port. (Employing TLS when using MQTT)



## Attack Surface 5: ESP32

- TR 64 : NP-04 **[done]**

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
