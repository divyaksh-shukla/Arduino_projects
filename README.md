# Arduino_projects
This repository stores all the codes compatible with arduino uno. All are tested on more than one arduino and tested throughly for bugs. Any associated header files or codes are also attached. 
## _7_segment_display ##
Arduino code to control 2 7-segment display connected as per the diagram shown in the figure to count upto 100 seconds (common anode). For common anode please replace all the values saying HIGH with LOW and vice-versa under the segmentWrite() function. 

## _7_segment_display_tester ##
This is to test the working of any 7-segment display that you may have (common anode). It counts upto 10 seconds.

## _7_segment_using_shift_register ##
Another program to control a seven segment display using the arduino and 74HC595 (8-bit shift register). Here, only 3 pins from the microcontroller are used instead of 8. Serial data is sent to the shift register.

***PAY ATTENTION: D0 is connected to bit "a" from the diagram D1-b D2-c D3-d ... and so on.***

## adafruit_8LED_74HC595_shift_register##
This is the mother code explaining how a shift register works. You can also make the register light up LEDs at random (*to make your own disco*). I leave that task to you.

## Fastest_finger_first ##
A small game of two players stimulating the scenario in a popular game show (*I hope you know it already*). The player who presses the finger first (within a difference of a microsecond) will show up on the screen.

## freeduino_robo_shield##
A small code to controll a motor attached to the freeduino robo_shield (*popular in India*).
