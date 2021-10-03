#include <Servo.h>

Servo servo1, servo2, servo3;

void setup(){ 
  servo1.attach(1);
  servo2.attach(4);
  servo3.attach(9);
}
void loop(){
  servo1.write(45);
  servo2.write(45);
  servo3.write(135);
  delay(1000);
  servo1.write(135);
  servo2.write(135);
  servo3.write(455);
  delay(1000);
}
