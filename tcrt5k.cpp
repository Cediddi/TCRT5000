/*
TCRT5K - A library for TCRT5000/l IR proximity sensors
Github: https://github.com/cediddi/TCRT5000
This code is licensed under CC BY-SA 3.0 license.
Original Code : Ultrasonic by https://github.com/JRodrigoTech

This library is a small interface for TCRT5000/l proximity sensors
You can use with receiver pin alone or both receiver and transmitter pins
If you use with transmitter pin connected to arduino, it will blink for 20us
  when you check the sensor, thus lower the power consumption

Please visit Ultrasonic library for HC-SR04 ultrasonic distance sensor too! 

Umut Karci ( http://www.umutkarci.com )
*/


#include "tcrt5k.h"

TCRT5000::TCRT5000(int RP){
    pinMode(RP,INPUT);
    _rp = RP;
}

TCRT5000::TCRT5000(int RP, int LP){
    pinMode(RP,INPUT);
    pinMode(LP,OUTPUT);
    _rp = RP;
    _lp = LP;
}

bool TCRT5000::isClose(){
    if (_lp == -1) {
        return !digitalRead(_rp);  // just check for it
    } else {
        bool status;
        digitalWrite(_lp, HIGH);  // lit the diode
        delayMicroseconds(100);  // diode should power up in 100 us
        status = !digitalRead(_rp);  // save status
        digitalWrite(_lp, LOW);  // dim the diode
        return status;
    }
}
