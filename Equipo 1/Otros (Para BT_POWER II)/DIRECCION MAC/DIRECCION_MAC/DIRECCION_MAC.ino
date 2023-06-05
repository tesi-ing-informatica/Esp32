#include "WiFi.h"

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("La direccion MAC de la placa es: ");
  Serial.println(WiFi.macAddress());
}

void loop() {
}
