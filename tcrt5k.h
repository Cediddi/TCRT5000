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

#ifndef tcrt5k_h
    #define tcrt5k_h

    #if defined(ARDUINO) && ARDUINO >= 100
        #include "Arduino.h"
    #else
        #include "WProgram.h"
    #endif

    class TCRT5000{
        public:
            TCRT5000(int RP);
            TCRT5000(int RP, int LP);
            bool isClose();
        private:
            int _rp;
            int _lp = -1;
    };
#endif
