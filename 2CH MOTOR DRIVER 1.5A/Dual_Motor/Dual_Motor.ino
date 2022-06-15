/*************************************
   Dual Channel DC Motor Driver Board
    Code Written by Idayu - MYBOTIC
 *************************************/

int IN_A1 = 11;
int IN_A2 = 10;
int IN_B1 = 9;
int IN_B2 = 8;

void setup()
{
  pinMode(IN_A1, OUTPUT);
  pinMode(IN_A2, OUTPUT);
  pinMode(IN_B1, OUTPUT);
  pinMode(IN_B2, OUTPUT);

  Serial.begin(9600);
  Serial.println("Enter number for control option:");
  Serial.println("1. FORWARD");
  Serial.println("2. REVERSE");
  Serial.println("3. STOP");
  Serial.println();
}

void loop()
{
  char user_input;

  while (Serial.available())
  {
    user_input = Serial.read();
   // digitalWrite(IN_A2, LOW); //OFF
    //digitalWrite(IN_B1, LOW);

    if (user_input == '1')
    {
      Forward();
    }
    else if (user_input == '2')
    {
      Reverse();
    }
    else if (user_input == '3')
    {
      Stop();
    }
    else
    {
      Serial.println("Invalid option entered.");
    }
  }
}


void Forward()
{
  digitalWrite(IN_A1, HIGH); //OFF
  digitalWrite(IN_A2, LOW);
  Serial.print("Motor 1 Forward");
  Serial.println();

  digitalWrite(IN_B2, HIGH); //OFF
  digitalWrite(IN_B1, LOW);
  Serial.println("Motor 2 Forward");
  Serial.println();
}

void Reverse()
{
  digitalWrite(IN_A1, LOW); //OFF
  digitalWrite(IN_A2, HIGH);
  Serial.print("Motor 2 Reverse");
  Serial.println();

  digitalWrite(IN_B2, LOW); //OFF
  digitalWrite(IN_B1, HIGH);
  Serial.println("Motor 2 Reverse");
  Serial.println();
}

void Stop()
{
  digitalWrite(IN_A1, LOW); //OFF
  digitalWrite(IN_A2, LOW);
  Serial.print("Motor 1 Stop");
  Serial.println();

  digitalWrite(IN_B2, LOW); //OFF
  digitalWrite(IN_B1, LOW);
  Serial.println("Motor 2 Stop");
  Serial.println();

}
