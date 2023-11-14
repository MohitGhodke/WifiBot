// Download Blynk app on your phone or tab.
// After adding a new device, you will recieve below details on registered mail. 
#define BLYNK_TEMPLATE_ID "<YOUR TEMPLATE ID>"
#define BLYNK_TEMPLATE_NAME "<YOUR TEMPLATE NAME>"
#define BLYNK_AUTH_TOKEN "<YOUR AUTH TOKEN>>"

// Make sure below libraries are installed.
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Add your WiFi SSID and Password for the same.
// This will help Node MCU to connect to internet when it boots.
char ssid[] = "<YOUR SSID>";        //WiFi Name
char pass[] = "<YOUR PASSWORD>";    //WiFi Password

// Below are the parameters and pin mappings for Node MCU <-> Arduino.
// No need to modify these variables.
int vValue = 0;
int m1 = 16;  //pin0
int m2 = 5;   //pin1
int m3 = 4;   //pin2
int m4 = 14;  //pin5

void setup() {

  // Port for monitoring.
  Serial.begin(9600);

  // Letting Blynk find your bot.
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Initialize all pins.
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);

  // Keeping all pins low to keep bot stopped when booted.
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
}

BLYNK_WRITE(V2) {
  vValue = param.asInt();
  Serial.println(vValue);
}

void loop() {

  Blynk.run();

  if (vValue == 1) {  //FORWARD
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
  }

  if (vValue == 2) {  //LEFT
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, HIGH);
  }

  if (vValue == 3) {  //RIGHT
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
  }

  if (vValue == 4) {  //BACKWARD
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    digitalWrite(m3, LOW);
    digitalWrite(m4, HIGH);
  }

  if (vValue == 0) {  //STOP
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
  }
}
