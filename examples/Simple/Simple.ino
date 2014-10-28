// TCRT5K - Library for TCRT5000 IR proximity sensor.
// GitHub: https://github.com/cediddi/TCRT5000
// #### LICENSE ####
// This code is licensed under MIT license. 
// Umut Karci ( http://www.umutkarci.com ).


// pin 2 is between 5Kohm and anode leg of Phototransistor (black one)
// pin 3 is connected to anode leg of IR-diode (blue one)
// you can just connect IR-Diode to 5v with 100ohm resistor
// but the IR-diode would drain 100mW for no reason

#include "tcrt5k.h"
TCRT5000 tcrt(2, 3);
// TCRT5000 tcrt(2);  // IR-diode connected to 5v with 100ohm resistor

void setup() {
  Serial.begin(9600);  // We'll see the output from Serial
}

void loop()
{
  if (tcrt.isClose()) {  // check tcrt5k
    Serial.println("CLOSE!");
  } else {
    Serial.println("Not so close.");
  }
  delay(333);
}
