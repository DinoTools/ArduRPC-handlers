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

#include "ArduRPC_Adafruit_DHT.h"

uint8_t ArduRPC_Adafruit_DHT_Wrapper(uint8_t cmd_id, ArduRPC *rpc, void *args)
{
  struct ArduRPC_Adafruit_DHT_options *options = (struct ArduRPC_Adafruit_DHT_options *)args;
  DHT *sensor = (DHT*)options->sensor;
  uint8_t type = options->type;

  if(cmd_id == 0x11) {
    if(type == DHT11)
      rpc->writeResult_float(0.0f);
    else
      rpc->writeResult_float(NAN);
  } else if(cmd_id == 0x12) {
    if(type == DHT11)
      rpc->writeResult_float(50.0f);
    else
      rpc->writeResult_float(NAN);
  } else if(cmd_id == 0x13) {
    if(type == DHT11)
      rpc->writeResult_float(2.0f);
    else
      rpc->writeResult_float(NAN);
  } else if(cmd_id == 0x14) {
    rpc->writeResult_float(sensor->readTemperature());
  } else if(cmd_id == 0x21) {
    if(type == DHT11)
      rpc->writeResult_float(20.0f);
    else
      rpc->writeResult_float(NAN);
  } else if(cmd_id == 0x22) {
    if(type == DHT11)
      rpc->writeResult_float(80.0f);
    else
      rpc->writeResult_float(NAN);
  } else if(cmd_id == 0x23) {
    if(type == DHT11)
      rpc->writeResult_float(5.0f);
    else
      rpc->writeResult_float(NAN);
  } else if(cmd_id == 0x24) {
    rpc->writeResult_float(sensor->readHumidity());
  } else {
    return RPC_RETURN_COMMAND_NOT_FOUND;
  }
  return RPC_RETURN_SUCCESS;
}

rpc_handler_t get_ArduRPC_Adafruit_DHT_Wrapper(DHT &sensor, uint8_t type)
{
  struct ArduRPC_Adafruit_DHT_options *options = (struct ArduRPC_Adafruit_DHT_options *)malloc(sizeof(struct ArduRPC_Adafruit_DHT_options));
  options->type = type;
  options->sensor = &sensor;
  rpc_handler_t h = {0x0403, (void *)ArduRPC_Adafruit_DHT_Wrapper, (void *)options};
  return h;
}
