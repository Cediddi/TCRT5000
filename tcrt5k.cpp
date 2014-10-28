// TCRT5K - Library for TCRT5000 IR proximity sensor.
// GitHub: https://github.com/cediddi/TCRT5000
// #### LICENSE ####
// This code is licensed under MIT license. 
// Umut Karci ( http://www.umutkarci.com ).

#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

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

bool TCRT5000::isClose()
{
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
