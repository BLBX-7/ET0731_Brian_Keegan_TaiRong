# Description </br>
The replacing for the need of a traditional key and shaft (key and lock), our Android Application is the newest
and most mordern way to unlocking a door. The complete removal for the need of a key to unlock a door
amplifies convenience, accessibility and security. </br>

## Sections covered: 
1 - Things needed </br>
2 - Steps to unlock door with Application </br>
3 - Cloud services used in Application </br>
4 - Application documentation </br>

# 1 - Things needed 
1. Android phone with internet/cellular connectivity
2. AWS Simple Email Service (SES): For sending of generated OTP to respective user
3. Azure SQL Server + Database: For storing of hashed user credentials 
4. ThingSpeak MQTT broker: For communication with Arduino locking system

# 2 -  Application flow </br>
1. User-login details to be provided on start up of Application. If identity
is incorrect, generic error message will be show. Login maximum attempt of 6 will decrement too; 
a 2 minute login lock-out will occur if max attempts used up. 

2. Upon successful login, user will receive an 8 digit OTP in the email they entered at login.
If OTP is entered wrongly thrice, user will be forced to re-login from login activity. 

3. After successful login and OTP authentication, user will then be brought to the main Application page -
A button to unlock the door. 

4. Pressing of the button will unlock their respective/assigned door.  

# 3 - Cloud services used in Application


# 4 - Application documentation
## 4.1. - Project prerequisites
### Files needed for project + Accounts in need of creation (Link the AWS SES)
(Talk about the jar files and cert)
### Dependencies needed for project
(Show code of dependencies added to project)
## 4.2. - Descriptive program flow
(Show image of program flow followed by the trust boundary)
