/**
 * Arduino Remote Procedure Calls - ArduRPC
 * Copyright (C) 2013-2014 DinoTools
 *
 * This file is part of ArduRPC.
 *
 * ArduRPC is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * ArduRPC is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public 
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ARDURPC_BOARD_H
#define ARDURPC_BOARD_H

#include <avr/pgmspace.h>

#include "ArduRPC.h"

#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
 #include <pins_arduino.h>
#endif

class ArduRPC_Board : public ArduRPCHandler
{
  public:
    ArduRPC_Board(ArduRPC &, char *, uint8_t, uint8_t , uint8_t, uint8_t);
    uint8_t
      addAnalogInput(uint8_t),
      addDigitalInput(uint8_t),
      addDigitalOutput(uint8_t),
      addPWMOutput(uint8_t),
      call(uint8_t);
  private:
    uint8_t
      cur_analog_input,
      cur_digital_input,
      cur_digital_output,
      cur_pwm_output,
      num_analog_input,
      num_digital_input,
      num_digital_output,
      num_pwm_output;
    uint8_t
      *pins_analog_input,
      *pins_digital_input,
      *pins_digital_output,
      *pins_pwm_output;
};

#endif
