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

ArduRPC_Adafruit_DHT::ArduRPC_Adafruit_DHT(ArduRPC &rpc, char *name, DHT &sensor, uint8_t sensor_type) : ArduRPCHandler()
{
  this->type = 0x0403;
  this->registerSelf(rpc, name, (void *)this);

  this->sensor = &sensor;
  this->sensor_type = sensor_type;
}

uint8_t ArduRPC_Adafruit_DHT::call(uint8_t cmd_id)
{
  if(cmd_id == 0x11) {
    if(this->sensor_type == DHT11)
      this->_rpc->writeResult_float(0.0f);
    else
      this->_rpc->writeResult_float(NAN);
  } else if(cmd_id == 0x12) {
    if(this->sensor_type == DHT11)
      this->_rpc->writeResult_float(50.0f);
    else
      this->_rpc->writeResult_float(NAN);
  } else if(cmd_id == 0x13) {
    if(this->sensor_type == DHT11)
      this->_rpc->writeResult_float(2.0f);
    else
      this->_rpc->writeResult_float(NAN);
  } else if(cmd_id == 0x14) {
    this->_rpc->writeResult_float(sensor->readTemperature());
  } else if(cmd_id == 0x21) {
    if(this->sensor_type == DHT11)
      this->_rpc->writeResult_float(20.0f);
    else
      this->_rpc->writeResult_float(NAN);
  } else if(cmd_id == 0x22) {
    if(this->sensor_type == DHT11)
      this->_rpc->writeResult_float(80.0f);
    else
      this->_rpc->writeResult_float(NAN);
  } else if(cmd_id == 0x23) {
    if(this->sensor_type == DHT11)
      this->_rpc->writeResult_float(5.0f);
    else
      this->_rpc->writeResult_float(NAN);
  } else if(cmd_id == 0x24) {
    this->_rpc->writeResult_float(sensor->readHumidity());
  } else {
    return RPC_RETURN_COMMAND_NOT_FOUND;
  }
  return RPC_RETURN_SUCCESS;
}
