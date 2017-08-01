/*
  Blink fast, Blink Slow

  The LED should blink 5 times, once every half second, and then it
  should blink 5 more times, once every two seconds. The LED should
  continue to blink in this alternating fashion for as long as the
  Arduino receives power.
*/

int mode = 0;     // 1 for fast, 0 for slow
const int fast = 500;   // 500msec delay
const int slow = 2000;  // 2 sec delay
int blink_delay;  // delay variable

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {

  if (mode == 0) {
    mode = 1;
    blink_delay = fast;
  } else {
    mode = 0;
    blink_delay = slow;
  }
  for (int i = 0; i < 5; i++) {
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);              // wait for a second
    digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
    delay(blink_delay);              // wait for a second
  }
}
