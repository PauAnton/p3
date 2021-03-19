#include <Arduino.h>
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
int LED=2;

void setup() {
  Serial.begin(9600);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  
  pinMode(LED, OUTPUT);
  Serial.println("When connected, select an option");
    Serial.println();
    Serial.println("1. LED on 500ms.");
    Serial.println("2. LED blink 3000ms.");
    Serial.println("3. LED on.");
    Serial.println("4. LED off.");
}

void loop() {

  if (Serial.available()) {
    
    SerialBT.write(Serial.read());
  }  

  if (SerialBT.available()) {
    Serial.println();
    
    char opc;
    
    opc=SerialBT.read();
    Serial.print("Option "); Serial.print(opc); Serial.println(" selected");

    if(opc=='1'){
      digitalWrite(LED,HIGH);
      delay(2000);
      digitalWrite(LED,LOW);
      }
    else if(opc=='2'){
      int i=0;
      while(i<6){ 
      digitalWrite(LED,HIGH);
      delay(500);
      digitalWrite(LED,LOW);
      delay(500);
      i++;}

    }
    else if(opc=='3'){
      digitalWrite(LED,HIGH);
      delay(500);
    }  
    else if(opc=='4'){
      digitalWrite(LED,LOW);
      delay(500);
    }
    else  {Serial.println("Option does not match delimiters.");} 

    opc=SerialBT.read();
    opc=SerialBT.read();

    Serial.println();
    Serial.println("Select new option");
    Serial.println("1. LED on 2000ms.");
    Serial.println("2. LED blink 3000ms.");
    Serial.println("3. LED on.");
    Serial.println("4. LED off.");
   
    
  }

}