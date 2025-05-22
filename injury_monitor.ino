#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

void setup() {
  Serial.begin(9600);
  dht.begin();
  if (!accel.begin()) {
    Serial.println("ADXL345 not detected. Check wiring.");
    while (1);
  }
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  sensors_event_t event;
  accel.getEvent(&event);
  float x = event.acceleration.x;
  float y = event.acceleration.y;
  float z = event.acceleration.z;

  Serial.print(temp); Serial.print(",");
  Serial.print(hum); Serial.print(",");
  Serial.print(x); Serial.print(",");
  Serial.print(y); Serial.print(",");
  Serial.println(z);

  delay(1000); // Read every second
}
