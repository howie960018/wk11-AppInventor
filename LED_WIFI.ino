#include <BluetoothSerial.h>

BluetoothSerial BT;

void setup() {
  
pinMode(14,OUTPUT);
Serial.begin(115200);
BT.begin("Howie");
}

void loop() {
  while(BT.available()){
    
    String BTdata=BT.readString();
    Serial.println(BTdata);
    if(BTdata=="a"){
       Serial.println("HIGH");
      digitalWrite(14,HIGH);
      }
    else{
      Serial.println("LOW");
      digitalWrite(14,LOW);
      }
    delay(1);
}
}
