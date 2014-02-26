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

#ifndef ARDURPC_DHT_H
#define ARDURPC_DHT_H

#include <avr/pgmspace.h>

#include "ArduRPC.h"
#include <DHT.h>

#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
 #include <pins_arduino.h>
#endif

struct ArduRPC_Adafruit_DHT_options {
  DHT *sensor;
  uint8_t type;
};

uint8_t ArduRPC_Adafruit_DHT_Wrapper(uint8_t cmd_id, ArduRPC *rpc, void *args);

rpc_handler_t get_ArduRPC_Adafruit_DHT_Wrapper(DHT &sensor, uint8_t type);

#endif
