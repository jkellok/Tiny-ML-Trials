// source: https://docs.arduino.cc/tutorials/portenta-h7/dual-core-processing
// Tools -> Target Core -> M4
void setup() {
    // initialize digital pin LED_BUILTIN as an output.
    pinMode(LEDG, OUTPUT);
}

void loop() {
    digitalWrite(LEDG, LOW); // turn the LED on (LOW is the voltage level)
    delay(500); // wait for half a second
    digitalWrite(LEDG, HIGH); // turn the LED off by making the voltage HIGH
    delay(500); // wait for half a second
}
