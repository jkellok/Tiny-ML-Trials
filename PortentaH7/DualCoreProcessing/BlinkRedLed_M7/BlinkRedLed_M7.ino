// source: https://docs.arduino.cc/tutorials/portenta-h7/dual-core-processing
void setup() {
  // force boot M4 core
  bootM4();
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LEDR, OUTPUT);
}

void loop() {
  digitalWrite(LEDR, HIGH); // turn the LED off (HIGH is the voltage level)
  delay(200); // wait for 200 milliseconds
  digitalWrite(LEDR, LOW); // turn the LED on by making the voltage LOW
  delay(200); // wait for 200 milliseconds
}
