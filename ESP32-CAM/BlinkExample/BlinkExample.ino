/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Based on Arduino IDE Examples -> Basic -> Blink
  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

#define LED_BUILTIN 33      // led for ESP32-CAM

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED on
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, HIGH);    // turn the LED off by making the voltage HIGH
  delay(1000);                       // wait for a second
}
