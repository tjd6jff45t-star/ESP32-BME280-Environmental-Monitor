#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

Adafruit_BME280 bme;
unsigned long previousMillis = 0;
const unsigned long interval = 2000; // Interval between readings in milliseconds
const int LED_PIN = 2; 

void setup() {
  Serial.begin(115200);

  Wire.begin(21, 22);

  pinMode(LED_PIN, OUTPUT);

  if (!bme.begin(0x76)) {
    Serial.println("BME280 not found!");
    while (1);
  }

  digitalWrite(LED_PIN, HIGH); // Turn on the LED to indicate successful connection
  Serial.println("BME280 connected!");
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    float temperature = bme.readTemperature();
    float humidity = bme.readHumidity();
    float pressure = bme.readPressure() / 100.0F;

    if (isnan(temperature) || isnan(humidity) || isnan(pressure)) {
  Serial.println("ERROR: Failed to read from BME280!");

  digitalWrite(LED_PIN, LOW); // Turn off the LED to indicate an error
  delay(200);
  digitalWrite(LED_PIN, HIGH); // Turn on the LED to indicate a successful reading
  delay(200);
  return;
  }
  Serial.println("Sensor Status: OK");

    Serial.println("===== BME280 DATA =====");

    Serial.print("Temperature: ");
    Serial.print(temperature, 2);
    Serial.println(" C");

    Serial.print("Humidity: ");
    Serial.print(humidity, 2);
    Serial.println(" %");

    Serial.print("Pressure: ");
    Serial.print(pressure, 2);
    Serial.println(" hPa");

    Serial.println("=======================");
    Serial.println();
  }
}