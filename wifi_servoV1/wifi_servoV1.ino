#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).

char auth[] = "Paste your Auth Token Her";   

// Your WiFi credentials.
// Set password to "" for open networks.

char ssid[] = "Enter your Wifi User Name"; 
char pass[] = "Enter your Wifi Password"; 


Servo servo;

BLYNK_WRITE(D1)
{
  servo.write(param.asInt());
  Serial.println("D1");
}


void connectToWifi(){
  // funtion to connect to WiFi
  //WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("\n\nconnecting");
  while (WiFi.status() != WL_CONNECTED) {
    //digitalWrite(LED, !digitalRead(LED));   // blink internal LED
    Serial.print(".");
    delay(500);
  }
  Serial.print("\nconnected: ");
  Serial.println(WiFi.localIP());
  //digitalWrite(LED, HIGH);
}

void loop()
{
  Blynk.run();
}
