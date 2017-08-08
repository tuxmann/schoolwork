#include <EEPROM.h>

void setup() {
  Serial.begin(9600);   // initialize the serial communication:
  pinMode(13, OUTPUT);  // initialize digital pin 13 as an output.
  digitalWrite(13, LOW);
  while (!Serial) {
    ; // wait for serial port to connect.
  }

  // prints title ending with a line break
  delay(100);
  Serial.println("This sketch gives the user access to the EEPROM.");
  Serial.println("To read, type 'read <address>'. Example: read 3");
  Serial.println("To write, type 'write <address>. Example write 3 10");

}

void loop() {
  if (Serial.available()) {

    ReadWrite = Serial.readStringUntil('\n'); 
        
    
    if (input == '0') {      // This is the value for an ASCII zero.
      digitalWrite(13, LOW);
    }
    if (input == '1') {      // This is the value for an ASCII one.
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
