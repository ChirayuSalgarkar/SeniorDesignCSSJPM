/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram)\n visit https://esp32io.com/tutorials/esp32-force-sensor
 */
#include <Arduino.h>

#define FORCE_SENSOR_PIN 36 // ESP32 pin GPIO36 (ADC0): the FSR and 10K pulldown are connected to A0

void setup() {
  Serial.begin(9600);

  Serial.print("\n");
  
}

void loop() {
  int analogReading1 = analogRead(36);
  int analogReading2 = analogRead(39);
  int analogReading3 = analogRead(34);
  int analogReading4 = analogRead(35);
  int analogReading5 = analogRead(32);
  int analogReading6 = analogRead(33);
  int analogReading7 = analogRead(25);


  Serial.print("\nS1\n");
  Serial.print(analogReading1); // print the raw analog reading

  Serial.print("\nS2\n");
  Serial.print(analogReading2);

    Serial.print("\nS3\n");
  Serial.print(analogReading3);

    Serial.print("\nS4\n");
  Serial.print(analogReading4);

    Serial.print("\nS5\n");
  Serial.print(analogReading5);

    Serial.print("\nS6\n");
  Serial.print(analogReading6);

    Serial.print("\nS7\n");
  Serial.print(analogReading7);

  delay(1000);
}