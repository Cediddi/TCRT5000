/*
TCRT5K - A library for TCRT5000/l IR proximity sensors
Github: https://github.com/cediddi/TCRT5000
This code is licensed under CC BY-SA 3.0 license.
Original Code : Ultrasonic by https://github.com/JRodrigoTech

pin 2 is between 5Kohm and anode leg of Phototransistor (black one)
pin 3 is connected to anode leg of IR-diode (blue one)
you can just connect IR-Diode to 5v with 100ohm resistor
but the IR-diode would drain 100mW for no reason

Umut Karci ( http://www.umutkarci.com )
*/

#include "tcrt5k.h"
TCRT5000 tcrt(2, 3);
// TCRT5000 tcrt(2);  // IR-diode connected to 5v with 100ohm resistor

void setup() {
    Serial.begin(9600);  // We'll see the output from Serial
}

void loop(){
    if (tcrt.isClose()) {  // check tcrt5k
        Serial.println("CLOSE!");
    } else {
        Serial.println("Not so close.");
    }
    delay(333);
}
