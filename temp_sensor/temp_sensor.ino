#include <OneWire.h>
#include <DallasTemperature.h>
// GPIO 
const int oneWireBus = 4;

// Setting up a oneWire instance
OneWire onewire(oneWireBus);

//Pass OneWire reference to Dallas Temperature Sensor
DallasTemperature sensors(&oneWire);

void setup() {
  // Start the Serial Monitor
  Serial.begin(115200);
  // Start the DS18B20 sensor
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);
  float tempF = sensors.getTempFByIndex(0);
  Serial.print(tempC);
  Serial.println("°C");
  Serial.print(tempF);
  Serial.println("°F");
  delay(5000);
}