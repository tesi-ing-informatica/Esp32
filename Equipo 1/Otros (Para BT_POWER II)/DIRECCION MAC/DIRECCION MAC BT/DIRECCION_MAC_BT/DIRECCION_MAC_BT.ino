#include <BLEDevice.h>

void setup() {
  Serial.begin(115200);
  BLEDevice::init("");
  BLEAddress bleAddress = BLEDevice::getAddress();
  Serial.println(bleAddress.toString().c_str());
}

void loop() {
}
