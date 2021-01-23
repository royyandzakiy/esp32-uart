#include <HardwareSerial.h>

HardwareSerial ArduinoSerial(2); // RX, TX

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ArduinoSerial.begin(9600);
  Serial.println("Setup done.");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()) {
    String str = Serial.readStringUntil('\n');
    Serial.println(str);
    ArduinoSerial.println(str);
    delay(10);
  }
  if(ArduinoSerial.available()) {
    String str = ArduinoSerial.readStringUntil('\n');
    Serial.println(str);
    delay(10);
  }
}
