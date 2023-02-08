# Description </br>
The replacing for the need of a traditional key and shaft (key and lock), our Android Application is the newest
and most mordern way to unlocking a door. The complete removal for the need of a key to unlock a door
amplifies convenience, accessibility and security. </br>

## Sections covered: 
1 - Things needed </br>
2 - Steps to unlock door with Application </br>
3 - Application documentation </br>

# 1 - Things needed 
1. Android phone with internet/cellular connectivity
2. AWS Simple Email Service (SES): For sending of generated OTP to respective user
3. Azure SQL Server + Database: For storing of hashed user credentials 
4. ThingSpeak MQTT broker: For communication with Arduino locking system

# 2 -  Application flow </br>
1. User-login credentials to be provided on start up of Application. If credential(s)
is/are incorrect, generic error message will be shown. Login maximum attempt of 4 will decrement too; a 2 minute login lock-out will occur if max attempts are used up. 

2. Upon successful login, user will receive an 8 digit OTP in the email they entered at login.
If OTP is entered wrongly thrice, user will be forced to re-login from login activity. 

3. After successful login and OTP authentication, user will then be brought to the main Application page - A button to unlock the door. 

4. Pressing of the button will unlock their respective/assigned door.  

With that knowledge in mind, this is the detailed Application flow diagram:
![Application flow diagram](Img/App_flow.JPG)

# 3 - Application documentation
## 3.1. - Project prerequisites
### Files needed for project + Accounts in need of creation (Link the AWS SES)
(Talk about the jar files and cert)
### Dependencies needed for project
(Show code of dependencies added to project)

## 3.2. - Descriptive program flow
(Show image of program flow followed by the trust boundary)
