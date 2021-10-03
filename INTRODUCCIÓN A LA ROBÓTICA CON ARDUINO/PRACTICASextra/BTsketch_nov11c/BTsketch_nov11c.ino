#include <Servo.h>

int led13=13;
int estado=0;
Servo servo1;

void setup(){
  Serial.begin(9600);
  pinMode(led13,OUTPUT);
  servo1.attach(3);
}

void loop(){
 if(Serial.available()>0){
 estado = Serial.read();
 }
 if (estado =='1'){
   digitalWrite(led13,HIGH);
   servo1.write(180);
   delay(2000);
  }
if(estado=='2'){
   digitalWrite(led13,LOW);
   servo1.write(0);
   delay(2000);
  }
}  
