# Description
This documentation will walk you through the steps to get the project Android application up and running. The things needing change in the Android application program have been marked with the comment "*TO SUPPLY OWN INFORMATION HERE:*" in the project code.</br>
After going through this, it is strongly recommended that you go through [2_Program_Details.md](2_Program_Details.md) to get a better understanding of the appliation program and how it works.

# Pre-requisites
## For Azure SQL:
0. To have created Azure SQL Server, Database and Database table. Database table to have the 3 following columns: id (PRIMARY KEY), email (VARCHAR 64), pw (VARCHAR 64); 'email' and 'pw' column will be filled with hashed values of said column.
![Azure SQL DB Table with Columns](Img/Azure_DBtableCOLUMN.JPG)

1. To have added the Android phone's (where the app will run on) public IP address into Azure SQL Server's whitelist firewall.
![Azure SQL Server whitelist firewall](Img/Azure_Public_IP.JPG)

2. To have attained the Azure SQL Database's JDBC connection string.
![Azure SQL DB connection string](Img/Azure_connectionString.JPG) 

## For AWS Simple Email Service (SES)
0. To have created an AWS account with SES configured and running.

1. To have validated the emails (both sender and recipient) in use for this application.
![AWS SES Validated Identities](Img/AWSses_validatedIdentities.JPG)

2. To have SMTP credentials in order for application program to work with AWS SES. Below are 2 methods if to obtain SMTP credentials. </br></br>
2.1. Method 1: Downloaded credentials at first creation of SMTP credentials.</br>
![AWS SES SMTP Credentials](Img/Azure_SMTPCredential.JPG) </br></br>
2.2. Method 2: Go to Amazon SES > SMTP settings > Create SMTP credentials. !Remember to save credentials this time round! </br>
![AWS SES SMTP Credential Creation](Img/Azure_SMTPCredentialCreation.JPG) </br></br>

3. To have host name (region) of SES.
![AWS SES SMTP Region](Img/Azure_region.JPG)

## For ThingSpeak MQTT Broker
0. To have craeted Channel and Channel field. To also have ThingSpeak certificate (provided in '2_Program_details')

1. To have created ThingSpeak MQTT credentials for publisher.
![ThingSpeak credentials created](Img/Thingspeak_createdCred.JPG)
1.1. If you have forgotten your password, you can regenerate it with the following steps:
![ThingSpeak credentials regeneration](Img/Azure_SMTPCredentialRegen.JPG)

# Next Up
[2_Program_Details.md](2_Program_Details.md)
