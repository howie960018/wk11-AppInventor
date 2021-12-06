#include <BluetoothSerial.h>
BluetoothSerial BT;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  BT.begin("EXP32");//請改名
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(27,OUTPUT);
}
int a =0;
int b =0;
void loop() {
  // put your main code here, to run repeatedly:
  while (BT.available()) {
    //讀取藍芽資料
    String BTdata=BT.readString();
    //顯示在序列視窗
    Serial.println(BTdata);
     if(BTdata=="P1 get one point"){
      a+=1;
      }
     if(a ==1){
      digitalWrite(12,HIGH);
      }
      if(a ==2){
      digitalWrite(13,HIGH);
      a=0;
      }
      if(BTdata=="P2 get one point"){
      b+=1;
      }
     if(b ==1){
      digitalWrite(14,HIGH);
      }
      if(b ==2){
      digitalWrite(27,HIGH);
      b=0;
      }
      if(BTdata=="NEW GAME"){
        digitalWrite(12,LOW);
        digitalWrite(13,LOW);
        digitalWrite(14,LOW);
        digitalWrite(27,LOW);
        }
    
  }
  delay(1);
}
