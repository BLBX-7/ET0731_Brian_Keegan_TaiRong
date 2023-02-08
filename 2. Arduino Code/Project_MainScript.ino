// Ensure correct credentials to connect to your WiFi Network.
// Ensure correct credentials to connect to your WiFi Network.
char ssid[] = "Keegan";
char pass[] = "qwerty1234";
// Ensure that the credentials here allow you to publish and subscribe to the ThingSpeak channel.
#define channelID 2021671
const char mqttUserName[] = "GSYbAz0VHygoBgkeKhEsOB4"; // Use any name
const char mqttPass[] = "edX0sbXPZNj4xyn01lQejyQe"; // Change to MQTT API Key from Account > MyProfile
const char clientID[] = "GSYbAz0VHygoBgkeKhEsOB4";

// It is strongly recommended to use secure connections. However, certain hardware does not work with the WiFiClientSecure library.

// Comment out the following #define to use non-secure MQTT connections to ThingSpeak server.
#define USESECUREMQTT //It will use port 8883

// Comment the following line if not using an ESP8266.
#define ESP8266BOARD

#include <ESP8266WiFi.h>

//ThingSPeak fingerprint SHA-1
const char* PROGMEM thingspeak_cert_thumbprint = "97 80 C2 50 78 53 2F C0 FD 03 DA E0 1B FD 8C 92 3F FF 98 78";

#include <PubSubClient.h>

#ifdef USESECUREMQTT
#include <WiFiClientSecure.h>
#define mqttPort 8883
WiFiClientSecure client;
#else
#define mqttPort 1883
WiFiClient client;
#endif
const char* server = "mqtt3.thingspeak.com";
int status = WL_IDLE_STATUS;
long lastPublishMillis = 0;
int connectionDelay = 1;
int updateInterval = 15;
PubSubClient mqttClient( client );

//Servo setup
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
bool uflag = 0;
bool lflag = 0;

const int trigPin = 12;
const int echoPin = 14;
#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701
long duration;
float distanceCm;
float distanceInch;


// Function to handle messages from MQTT subscription.
void mqttSubscriptionCallback( char* topic, byte* payload, unsigned int length ) {
  Serial.println("-----------------------");
  char p[length+1];
  Serial.print("Received message:");
  Serial.println(p);

  
  memcpy(p, payload, length);
  p[length]=NULL;
  Serial.println("Answer: ");
  Serial.println(String(p));

  if (String(p)=="unlocked"){
    //turn unlock door
    myservo.write(180);
    }

}

// Subscribe to ThingSpeak channel for updates.
void mqttSubscribe( long subChannelID ) {
  String myTopic = "channels/" + String( subChannelID ) + "/subscribe/fields/field1";
  mqttClient.subscribe(myTopic.c_str());
}

// Publish messages to a ThingSpeak channel.
void mqttPublish(long pubChannelID, String message) {
 String topicString = "channels/" + String( pubChannelID ) + "/publish";
 mqttClient.publish( topicString.c_str(), message.c_str() );
}
// Connect to WiFi.
void connectWifi()
{
  Serial.println( "Connecting to Wi-Fi..." );
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" ");
  Serial.println("WiFi connected");
  Serial.print("Got IP: ");  Serial.println(WiFi.localIP());
}

// Connect to MQTT server.
void mqttConnect() {
  byte mac[5]; // create client ID from mac address
  WiFi.macAddress(mac); // get mac address
  // String clientID = String(mac[0]) + String(mac[4]) ; // use mac address to create clientID
  // Loop until connected.
  while ( !mqttClient.connected() )
  {
    // Connect to the MQTT broker.
    if ( mqttClient.connect( clientID , mqttUserName, mqttPass ) ) {
      Serial.print( "MQTT to " );
      Serial.print( server );
      Serial.print (" at port ");
      Serial.print( mqttPort );
      Serial.println( " successful." );
    } else {
      Serial.print( "MQTT connection failed, rc = " );
      // See https://pubsubclient.knolleary.net/api.html#state for the failure code explanation.
      Serial.print( mqttClient.state() );
      Serial.println( " Will try again in a few seconds" );
      delay( connectionDelay * 1000 );
    }
  }
}


void UltrasonicSensor(){
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distanceCm = duration * SOUND_VELOCITY/2;
}
void setup() {
  Serial.begin( 115200 );
  // Delay to allow serial monitor to come up.
  delay(3000);
  Serial.println(thingspeak_cert_thumbprint);
  // Connect to Wi-Fi network.
  connectWifi();
  // Configure the MQTT client
  mqttClient.setServer( server, mqttPort );
  // Set the MQTT message handler function.
  mqttClient.setCallback( mqttSubscriptionCallback );
  // Set the buffer to handle the returned JSON. NOTE: A buffer overflow of the message buffer will result in your callback not being invoked.
  mqttClient.setBufferSize( 2048 );
  // Use secure MQTT connections if defined.
  client.setFingerprint(thingspeak_cert_thumbprint);

   // servo motor setup for locked
  myservo.attach(2);  // attaches the servo on pin 2 AKA D4 to the servo object
  myservo.write(50); //locked

  //Camera Setup
  pinMode(13, OUTPUT); // Initiate Camera Pin 13 AKA D7

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}

void loop() {

//Threshold for door
int threshold = 10;

  // Reconnect to WiFi if it gets disconnected.
  if (WiFi.status() != WL_CONNECTED) {
    connectWifi();
  }

  // Connect if MQTT client is not connected and resubscribe to channel updates.
  if (!mqttClient.connected()) {
    mqttConnect();
    mqttSubscribe( channelID );
  }

   // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distanceCm = duration * SOUND_VELOCITY/2;
  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);

//Wait until door open
while(distanceCm < threshold){
  UltrasonicSensor();
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  mqttClient.loop();
}

//Take picture 
 delay(500);
    digitalWrite(13, HIGH); // sets the digital pin 13 on
    digitalWrite(13, LOW);  // sets the digital pin 13 off
    
//Wait until soon is closed
  while(distanceCm > threshold){
    Serial.print("Door Still Open");
    UltrasonicSensor();
    Serial.print(" Distance (cm): ");
    Serial.println(distanceCm);
  }

  //lock door
   myservo.write(50);


}