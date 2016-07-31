long time;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  
  Serial.print("Time: ");
  time = millis();
  Serial.println(time);
}
