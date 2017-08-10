#include <EEPROM.h>

String input;

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
  Serial.println();

}

void loop() {
  if (Serial.available()) {

    input = Serial.readStringUntil('\n'); // Read the serial line.
    input.toLowerCase();                  // Change all char to lower case. Dec not affected.
    Serial.println(input);                // Echo what was sent to the Arduino.
    String ReadWrite = input;
    ReadWrite.remove(5);                  // Strip everything after the 5th char.

    if (ReadWrite == "read ") {
      int Addr = input.substring(5).toInt(); // Set the address.
      
      if (Addr > 1023 || Addr < 0) {
        Serial.println("Please enter a valid address from 0 to 1023");      
      } else {
        int value = EEPROM.read(Addr);    // Read the EEPROM and print it.
        Serial.print("Address: "); Serial.print(Addr, DEC);
        Serial.print("      Value: "); Serial.println(value, DEC);
        }
    }

    if (ReadWrite == "write") {
      String Args = input; Args.remove(0,6);    // Create Args string and remove "write".
      int Arg_length = Args.indexOf(' ');     // Find character size of address
      int Addr = Args.substring(0, Arg_length).toInt(); // Set the address.
      Serial.print("Writing to Address: '"); Serial.print(Addr, DEC);
      Args.remove(0, Arg_length+1);
      int value = Args.toInt();
      Serial.print("' with value of "); Serial.print(value, DEC); Serial.println(".");
      
      if (Addr < 0 || Addr > 1023 || value < 0 || value > 255) {
        Serial.println("Error, Address or Value is out of range");
      }

      else { 
        EEPROM.write(Addr, value);
      }
    }
  }
}
