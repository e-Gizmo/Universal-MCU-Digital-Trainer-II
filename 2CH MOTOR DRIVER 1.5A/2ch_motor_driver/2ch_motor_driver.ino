/*
   e-Gizmo Motor Driver Shield
 
 Sample codes
 
 Codes by:
 e-Gizmo Mechatronix Central
 http://www.e-gizmo.com

 */

int speed;

void setup() {                
  pinMode(8, OUTPUT);     
  pinMode(9, OUTPUT);     
  pinMode(10, OUTPUT);     
  pinMode(11, OUTPUT);     
}

void loop()  {
  digitalWrite(8, LOW);
  digitalWrite(11, LOW);
  for (speed=0; speed<256; speed++){
    analogWrite(9, speed);    
    analogWrite(10, speed);    
    delay(10);      // wait for a second
  }    
  for (speed=255; speed>0; speed--){
    analogWrite(9, speed);    
    analogWrite(10, speed);    
    delay(10);              // wait for a second
  }    
  digitalWrite(8, HIGH);
  digitalWrite(11, HIGH);
  for (speed=0; speed<256; speed++){
    analogWrite(9, speed);    
    analogWrite(10, speed);    
    delay(10);              // wait for a second
  }    
  for (speed=255; speed>0; speed--){
    analogWrite(9, speed);    
    analogWrite(10, speed);    
    delay(10);              // wait for a second
  }    
}