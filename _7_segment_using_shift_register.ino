/**
 * Name: Divyaksh Shukla
 * Arduino controlling 7 segment display via 74HC595 Shift register
 * Created On:22/06/2016
 * v1.0

  PINOUT DIAGRAM FOR THIS CODE
  
 
          ______________ 
         |              |
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
         |______________|
*/

const int a = 1;
const int b = 2;
const int c = 4;
const int d = 8;
const int e = 16;
const int f = 32;
const int g = 64;
const int h = 128;

const int latchPin = 5;
const int clockPin = 6;
const int dataPin = 4;

void setup() {

  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  int i = 0;
  for(i = 0;i<=10;i++)
  {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, segmentWrite(i));
    digitalWrite(latchPin, HIGH);
    delay(500);
  }
}

void segmentWrite(int value)
{
  //Serial.println(value);
  switch(value)
  {
    case 0:
    return a+e;

    case 1:
    return a+c+d+e+f+g;

    case 2:
    return b+e+f;

    case 3:
    return b+e+h;

    case 4:
    return c+e+g+h;

    case 5:
    return d+e+h;

    case 6:
    return d+e;

    case 7:
    return a+b+e+g+h;

    case 8:
    return e;

    case 9:
    return e+h;
  }
}

