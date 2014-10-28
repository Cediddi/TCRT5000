// TCRT5K - Library for TCRT5000 IR proximity sensor.
// GitHub: https://github.com/cediddi/TCRT5000
// #### LICENSE ####
// This code is licensed under MIT license. 
// Umut Karci ( http://www.umutkarci.com ).

#ifndef tcrt5k_h
#define tcrt5k_h

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class TCRT5000
{
  public:
    TCRT5000(int RP);
    TCRT5000(int RP, int LP);
    bool isClose();
  private:
    int _rp;
    int _lp = -1;
};

#endif
