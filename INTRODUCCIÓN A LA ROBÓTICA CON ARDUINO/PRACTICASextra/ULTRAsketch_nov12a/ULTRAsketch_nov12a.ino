#include <Servo.h>
Servo servo1;
/*
Sensor de proximidad y al ser inferior a 10cm 
envia un pulso de alarma por  el pin 13

 HC-SR04 conexiones:
  VCC al arduino 5v 
  GND al arduino GND
  Echo al Arduino pin 6 
  Trig al Arduino pin 7
 
 */
#define tono 1700
double zumbador = 8; //ZUMBADOR
int duracion2=2500;

 
#define Pecho 6
#define Ptrig 7
long duracion, distancia;   
int CONT=0; 

void setup() {                
  Serial.begin (9600);       // inicializa el puerto seria a 9600 baudios
  pinMode(Pecho, INPUT);     // define el pin 6 como entrada (echo)
  pinMode(Ptrig, OUTPUT);    // define el pin 7 como salida  (triger)
  pinMode(3, 1);            // Define el pin 13 como salida
  //servo1.attach(3);
  pinMode(zumbador, OUTPUT); // El zumbador como salida

  
  }
  
void loop() {
  
  digitalWrite(Ptrig, LOW);
  delayMicroseconds(2);
  digitalWrite(Ptrig, HIGH);   // genera el pulso de triger por 10ms
  delayMicroseconds(10);
  digitalWrite(Ptrig, LOW);
  
  duracion = pulseIn(Pecho, HIGH);
  distancia = (duracion/2) / 29;            // calcula la distancia en centimetros

   if (distancia <= 15 && distancia >= 1){
    CONT++;
    digitalWrite(13, HIGH);                     // en alto el pin 13 si la distancia es menor a 10cm
    Serial.println(CONT);         // envia la palabra Alarma por el puerto serial
    //servo1.write(90);
    tone(zumbador,tono,duracion2);
    delay(5000);
  }
  else{
    digitalWrite(13, LOW);                     // en alto el pin 13 si la distancia es menor a 10cm
    Serial.println("Alarma.......");         // envia la palabra Alarma por el puerto serial
    servo1.write(0);
    //delay(2000);
  }
  
  //delay(400);                                // espera 400ms para que se logre ver la distancia en la consola
}
