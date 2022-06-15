int IN_A1 = 11;
int IN_A2 = 10;
int IN_B1 = 9;
int IN_B2 = 8;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(IN_A1, OUTPUT);
  pinMode(IN_A2, OUTPUT);
  pinMode(IN_B1, OUTPUT);
  pinMode(IN_B2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i <= 255; i ++) {
    digitalWrite( IN_A1, HIGH );
    digitalWrite( IN_B2, HIGH );
    analogWrite( IN_A2, ~i );
    analogWrite( IN_B1, ~i );
    Serial.println(i);
    delay(50);
  }
  for (int i = 255; i>= 0; i--) {
    digitalWrite( IN_A1, HIGH );
    digitalWrite( IN_B2, HIGH );
    analogWrite( IN_A2, ~i );
    analogWrite( IN_B1, ~i );
    Serial.println(i);
    delay(50);
  }
}
