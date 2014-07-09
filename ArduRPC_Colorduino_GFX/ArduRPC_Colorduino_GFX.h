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

#ifndef ARDURPC_COLORDUINO_GFX_H
#define ARDURPC_COLORDUINO_GFX_H

#include <avr/pgmspace.h>

#include "ArduRPC.h"
#include <Colorduino_GFX.h>

#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
 #include <pins_arduino.h>
#endif

class ArduRPC_Colorduino_GFX : public ArduRPCHandler
{
  public:
    ArduRPC_Colorduino_GFX(ArduRPC &rpc, char *name, ColorduinoPanel &panel);
    uint8_t
      call(uint8_t);
  private:
    ColorduinoPanel *panel;
    uint8_t auto_swap;
};

#endif
