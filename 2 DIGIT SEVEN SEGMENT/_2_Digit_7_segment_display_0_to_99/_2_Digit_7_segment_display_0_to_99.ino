
////////////////////////////////////////////////
// 2-DIGIT 7-SEGMENT DISPLAY                  //
// FOR eGizmo UNIVERSAL MCU TRAINER           //
//                                            //
// This serves as a sample program for        //
// 2 digit 7 segment displays wherein         //
// in counts from 0 to 99                     //
//                                            // 
// See manual for pin and segment connections //
//                                            //
// Codes by:                                  //
// eGizmo Mechatronix Central                 //
// Taft, Manila, Philippines                  //
// http://www.egizmo.com                      //
// April 11, 2013                             //
////////////////////////////////////////////////
 
 
#define D1 13 // DIGIT1 display as pin 13
#define D0 12 // DIGIT0 display as pin 12
#define MPX 10 // Delay for Multiplexing (this can only be from 1-10)
 
const int numberPin[7] = {0,1,2,3,4,5,6}; // Sets pins 0-7 as number pins
 
// Segments that make each number
const byte numbers[10] = 
{//  abcdefg
    B1000000, // 0 
    B1111001, // 1
    B0100100, // 2
    B0110000, // 3
    B0011001, // 4
    B0010010, // 5
    B0000010, // 6
    B1111000, // 7
    B0000000, // 8
    B0010000  // 9
 }; 
 
 
void setup() {
  for(int i =0; i<=7; i++)
  {
  pinMode(i, OUTPUT);   // Sets pins 0-7 as OUTPUT
  }
  pinMode(D1, OUTPUT);  // Sets DIGIT1 (Pin 13) as OUTPUT
  pinMode(D0, OUTPUT);  // Sets DIGIT0 (Pin 12) as OUTPUT
  digitalWrite(7,HIGH); // Turns off DP segment, replace HIGH with LOW to enable decimals
}
 
 
void loop() {
  for (int digit1=0; digit1<=9; digit1++)    // Variable for second digit from 0 to 9
  {
    for (int digit0=0; digit0<=9; digit0++)  // Variable for first digit from 0 to 9 
    {
      unsigned long startTime = millis();
      for (unsigned long elapsed = 0; elapsed <= 1000; elapsed = millis() - startTime) // This is wherein one sets the delay for each digit 1000ms or 1s as default
      {
        lightDigit1(numbers[digit1]);  // Quickly turns off DIGIT1 so that data is stored
        delay(MPX);                    
        lightDigit0(numbers[digit0]);  // Quickly turns off DIGIT0 so that data is stored
        delay(MPX);
      }
    }
  }
}
 
// Function for writing segments
void numberWrite(byte number) 
{
  for (int i = 0; i < 7; i++) 
  {
    int bit = bitRead(number, i);
    digitalWrite(numberPin[i], bit);
  }
}
 
// Functions for Multiplexing
void lightDigit1(byte number) 
{
  digitalWrite(D1, LOW);   // Turns on display for second digit
  digitalWrite(D0, HIGH);  // Turns off display for first digit
  numberWrite(number);
}
void lightDigit0(byte number) 
{
  digitalWrite(D1, HIGH); // Turns off display for second digit
  digitalWrite(D0, LOW);  // Turns on display for first digit
  numberWrite(number);
}
