/*
  User controlled LED

  When the program is started, the LED should be off. The user should 
  open the serial monitor to communicate with the Arduino. If the user 
  sends the character '1' through the serial monitor then the LED 
  should turn on. If the user sends the character '0' through the 
  serial monitor then the LED should turn off.
*/

int input = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);   // initialize the serial communication:
  pinMode(13, OUTPUT);  // initialize digital pin 13 as an output.
  digitalWrite(13, LOW);
  while (!Serial) {
    ; // wait for serial port to connect.
  }

  // prints title ending with a line break
  Serial.println("Press 1 to turn on LED. Press 0 to turn off LED.");

}

// the loop function runs over and over again forever
void loop() {

  if (Serial.available()) {
    int(input) = Serial.read();
    if (input == 48) {      // This is the value for an ASCII zero.
      digitalWrite(13, LOW);
    }
    if (input == 49) {      // This is the value for an ASCII one.
      digitalWrite(13, HIGH);
    }
    if (input != 48 && input != 49) { // The user did not enter a 1 or a 0.
      Serial.println();
      Serial.println("There are 10 kinds of states for this LED, and that was not one of them...");
      Serial.println("Please try again.");
      Serial.println();
    }
  }
}
