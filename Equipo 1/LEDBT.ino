#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth no activado! Activa la conexion Bluetooth.
#endif

BluetoothSerial SerialBT;

char caracter;
#define LED12 12 // LED en terminal D12
#define LED14 14 // LED en terminal D14
#define LED2 2 // LED en terminal D02

void setup() { 
SerialBT.begin("ESP32test"); //Nombre del Bluetooth (personalizable)
pinMode(LED12, OUTPUT);
pinMode(LED14, OUTPUT); 
pinMode(LED2, OUTPUT); 
}

void loop() { 
  if(SerialBT.available()) {
  caracter = SerialBT.read();
  
  if(caracter == '1')
  { 
  digitalWrite(LED12, HIGH);
  }
  
  if(caracter == '2')
  { 
  digitalWrite(LED12, LOW);
  } 
  
  if(caracter == '3')
  { 
  digitalWrite(LED14, HIGH);
  }
  
  if(caracter == '4')
  { 
  digitalWrite(LED14, LOW);
  }

  if(caracter == '5')
  { 
  digitalWrite(LED2, HIGH);
  }
  
  if(caracter == '6')
  { 
  digitalWrite(LED2, LOW);
  }
  
  } 
} 
