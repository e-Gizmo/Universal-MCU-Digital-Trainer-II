/////////////////////////////////////
// Analog voltage source           //
// eGizmo Universal MCU Trainer    //
//                                 //
// Reads analog voltage from       //
// three voltage sources provided  //
// in the trainer. Max of 5V       //
//                                 //
// Simply connect VR1, VR2 and VR3 //
// to A0, A1 and A2 respectively   //
//                                 //
// Codes by:                       //
// Dan                             //
// eGizmo Mechatronix Central      //
// Taft, Manila, Philippines       //
// http://www.egizmo.com           //
/////////////////////////////////////
 
const int D = 50; 
// Delay for voltage reading. Maintain a low value so that
// voltage can be controlled easier.
 
void setup() 
{  
  Serial.begin(9600); // Begin serial communication
}
 
 
void loop() {
 
  int VR1 = analogRead(A0);
  int VR2 = analogRead(A1);
  int VR3 = analogRead(A2);
  
  float V1 = VR1 * (5.0 / 1023.0); // Formula for voltage reading 1
  float V2 = VR2 * (5.0 / 1023.0); // Formula for voltage reading 2
  float V3 = VR3 * (5.0 / 1023.0); // Formula for voltage reading 3
  
  Serial.print(V1); Serial.print(" ");   Serial.print(V2); Serial.print(" ");   Serial.print(V3); Serial.print(" "); 
  Serial.print("\n");
  delay(D);
}
