#include <LiquidCrystal.h>

#include <NewPing.h>

#define TRIGGER_PIN  53  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     52  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
LiquidCrystal lcd(2,3,4,5,6,7);

void setup() {
  // put your setup code here, to run once:
   delay(200);
   Serial.begin(2000000);
   Serial.println("Hello Board A2");

   lcd.begin(16,2);
   lcd.setCursor(0,0);
   lcd.print("Distance Test");
   lcd.setCursor(0,10);
   lcd.print("in centimeters");

   pinMode(LED_BUILTIN, OUTPUT);
   digitalWrite(LED_BUILTIN, LOW);
   delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(50);
  // Serial.print("Ping: ");
  //Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  //Serial.println("cm");

  lcd.clear();
  lcd.print("Ping: ");
  lcd.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  lcd.println("cm");
  
   digitalWrite(LED_BUILTIN, HIGH);
   //delay(1000);
   digitalWrite(LED_BUILTIN, LOW);
   //delay(1000);
}
