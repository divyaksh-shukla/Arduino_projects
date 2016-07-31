/**

  PINOUT DIAGRAM FOR THIS CODE
  
 
          ______________ 
   5  6  |  7  8        |
   a  b  |  c  d        |
   |  |  |  |  |        |
  |+++++++++++++|       |
  |  _________  |       |
  | | _______ | |       |
  | | |     | | |       |
  | | |     | | |       |
  | \ \_____/ / |       |
  |    _____    |       |
  | / /     \ \ |       |
  | | |     | | |       |==============[+5V]
  | | |     | | |       |
  | | |_____| | |       |           [LT542]
  | |_________| |       |        COMMON ANODE
  |             |       |
  |+++++++++++++|       |
   |  |  |  |  |        |
   h  g  |  f  e        |
   9  10 |__11_12_______|
*/

#define DELAY 5
const int tenth = 4;
const int unit = 13;

const int a = 5;
const int b = 6;
const int c = 7;
const int d = 8;
const int h = 9;
const int g = 10;
const int f = 11;
const int e = 12;
int counter = 0;
unsigned long n = 0;
unsigned long currenttime = 0;
unsigned long previoustime = 0;
unsigned long interval = 1000;

void setup() {
  
  //seeting the number to be displayed
  counter = 0;
  
  //setting up the pins for 7 segment display
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(h,OUTPUT);
  
  pinMode(tenth,OUTPUT);
  pinMode(unit,OUTPUT);
  
  //initializing the 7 segment pins
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(h,HIGH);
  
  digitalWrite(tenth,LOW);
  digitalWrite(unit,LOW);
  
  //setting up user display on computer
  Serial.begin(9600);
}

void loop() {
  
  /*code to print all numbers from 0 to 10 on
  a two digit 7 segment display*/
    while(true)
    {
      //resetting counter value
      if(counter == 100)
        counter = 0;
        
        
      currenttime = millis();
      //Displaying tenths place
      digitalWrite(tenth,LOW);
      digitalWrite(unit,LOW);
      segmentWrite((int)counter/10);
      digitalWrite(tenth,HIGH);
    
      //displaying units place
      digitalWrite(tenth,LOW);
      digitalWrite(unit,LOW);
      segmentWrite((int)counter%10);
      digitalWrite(unit,HIGH);
      /*Serial.print(n);
      Serial.print("    ");
      Serial.println(counter);*/
      
      if(currenttime-previoustime>=interval)
      {
         counter++;
         previoustime = currenttime;
         break;
      }
      
    }
}

void clear_all()
{
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(h,HIGH);
}

void segmentWrite(int value)
{
  //Serial.println(value);
  switch(value)
  {
  case 0:
    digitalWrite(a,HIGH);
    digitalWrite(b,LOW);
    digitalWrite(c,LOW);
    digitalWrite(d,LOW);
    digitalWrite(e,HIGH);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);
    digitalWrite(h,LOW);
    break;
  case 1:
    digitalWrite(a,HIGH);
    digitalWrite(b,LOW);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
    digitalWrite(h,LOW);
    break;
  case 2:
    digitalWrite(a,LOW);
    digitalWrite(b,HIGH);
    digitalWrite(c,LOW);
    digitalWrite(d,LOW);
    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,LOW);
    digitalWrite(h,LOW);
    break;
  case 3:
    digitalWrite(a,LOW);
    digitalWrite(b,HIGH);
    digitalWrite(c,LOW);
    digitalWrite(d,LOW);
    digitalWrite(e,HIGH);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);
    digitalWrite(h,HIGH);
    break;
  case 4:
    digitalWrite(a,LOW);
    digitalWrite(b,LOW);
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW);
    digitalWrite(e,HIGH);
    digitalWrite(f,LOW);
    digitalWrite(g,HIGH);
    digitalWrite(h,HIGH);
    break;
  case 5:
    digitalWrite(a,LOW);
    digitalWrite(b,LOW);
    digitalWrite(c,LOW);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);
    digitalWrite(h,HIGH);
    break;
  case 6:
    digitalWrite(a,LOW);
    digitalWrite(b,LOW);
    digitalWrite(c,LOW);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);
    digitalWrite(h,LOW);
    break;
  case 7:
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,LOW);
    digitalWrite(d,LOW);
    digitalWrite(e,HIGH);
    digitalWrite(f,LOW);
    digitalWrite(g,HIGH);
    digitalWrite(h,HIGH);
    break;
  case 8:
    digitalWrite(a,LOW);
    digitalWrite(b,LOW);
    digitalWrite(c,LOW);
    digitalWrite(d,LOW);
    digitalWrite(e,HIGH);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);
    digitalWrite(h,LOW);
    break;
  case 9:
    digitalWrite(a,LOW);
    digitalWrite(b,LOW);
    digitalWrite(c,LOW);
    digitalWrite(d,LOW);
    digitalWrite(e,HIGH);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);
    digitalWrite(h,HIGH);
    break;
    
  default:
    Serial.println("NOT VALID");
  }
}
