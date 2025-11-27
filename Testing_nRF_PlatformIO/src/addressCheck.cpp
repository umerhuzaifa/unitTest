
// address check for the I2C devices
#include <Arduino.h>
#include <Wire.h>

TwoWire myWire(
    NRF_TWIM0,     // TWIM peripheral (Master)
    NRF_TWIS0,     // TWIS peripheral (Slave)
    1, // IRQ number for TWIM0/TWIS0
    20,            // SDA pin (adjust based on your board)
    19             // SCL pin (adjust based on your board)
);
void setup() {
    Wire.setPins(20, 19); // nRF 52832 default I2C pins
    Wire.begin(); // Initialize I2C with default pins
    
  Serial.begin(115200);
  Serial.println("Scanning I2C...");

  for (uint8_t addr = 1; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) {
      Serial.print("Found device at 0x");
      Serial.println(addr, HEX);
    }
  }
}

void loop() {}