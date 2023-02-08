//sharath kumar's
//this project indicates the level of water and you can control the switch through your mobile
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "" //template id which you will get in blynk web
#define BLYNK_DEVICE_NAME ""//device name that you have created
#define BLYNK_AUTH_TOKEN "" //blynk token
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define trig 13
#define echo 12
#define relay 4
#define VPIN V0
#define VPIN1 V1
char auth[] = ""; //fill token here also cz the new versions only support above 
char ssid[] = "";  // wifi user name
char pass[] = "";   // your wifi password

char s[]="tank is low";  //this indicates when tank is low
char p[]="tank is full";  //this indicates when tank is full

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(relay, OUTPUT);
  Blynk.begin(auth, ssid, pass);
}
//the below code describes the lenghth of tank needed to be fill or filled
//just a distance measurement from water to top
void loop(){
  digitalWrite(trig, LOW);
  delayMicroseconds(4);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long t = pulseIn(echo, HIGH);
  long cm = t / 29 / 2;
  Serial.println(cm); 
  Blynk.virtualWrite(VPIN, cm);  // writes the value in cm on your display in  the app
  Blynk.run();
  delay(1000);
  if(cm<=5){
    Blynk.virtualWrite(VPIN1,s);  //writes the low on your display in  the app
     
  }
  else if(cm>=30){
    Blynk.virtualWrite(VPIN1,p);   //writes the high on your display in  the app
  }
 
}
