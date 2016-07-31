unsigned int p1 = 0;
unsigned int p2 = 0;
bool flag1,flag2;

void setup() {
  pinMode(7,INPUT);
  pinMode(9,INPUT);

  Serial.begin(9600);
  Serial.println("Ready");

}

void loop() {

  flag1 = false;
  flag2 = false;
  while(flag1 == false && flag2 == false)
  {
  flag1 = false;
  flag2 = false;
  if(digitalRead(7) == HIGH)
  {
    p1 = micros();
    flag1 = true;
  }
  if(digitalRead(9) == HIGH)
  {
    p2 = micros();
    flag2 = true;
  }

  if(flag1 && flag2)
  {
    if(p1<p2)
    {
      Serial.println("Player 1");
    }
    else
    Serial.println("Player 2");
  }
  else if(flag1)
  Serial.println("Player 1");
  else if(flag2)
  Serial.println("Player 2");
  }

  delay(1000);
  Serial.println("Next");

}
