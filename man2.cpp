@@ -1,44 +1,51 @@
/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram)\n visit https://esp32io.com/tutorials/esp32-force-sensor
 */
#include <Arduino.h>

// put function declarations here:
#define FORCE_SENSOR_PIN 36 // ESP32 pin GPIO36 (ADC0): the FSR and 10K pulldown are connected to A0
#define OUTPUT_PIN 39
  

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial);


  pinMode(OUTPUT_PIN, OUTPUT);
  Serial.print("\n");

}

void loop() {
  digitalWrite(OUTPUT_PIN, HIGH); // Set the OUTPUT_PIN high
  delay(1000); // Wait for a second
  Serial.writeln(analogRead(FORCE_SENSOR_PIN);
  Serial.print();
  digitalWrite(OUTPUT_PIN, LOW); // Set the OUTPUT_PIN low
  delay(1000); // Wait for a second
}
