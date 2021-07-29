/**
 **************************************************
 *
 * @file        RDM6300-SOLDERED.h
 * @brief       Main header for RDM6300 Library
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors     Zvonimir Haramustek for soldered.com
 ***************************************************/

#ifndef __RDM6300_SOLDERED__
#define __RDM6300_SOLDERED__

#include "Arduino.h"

#include "libs/rdm6300/src/rdm6300.h"

#ifdef __AVR__
#include <SoftwareSerial.h>
#else
#include "libs/espsoftwareserial/src/SoftwareSerial.h"
#endif

class RDM6300 : public Rdm6300
{
  public:
    RDM6300(int rx_pin = 8) : Rdm6300()
    {
        ss = new SoftwareSerial(rx_pin, -1);
    }

    void begin()
    {
        ss->begin(RDM6300_BAUDRATE);
        Rdm6300::begin(ss);
    }

  private:
    SoftwareSerial *ss;
};

#undef Rdm6300

#endif
