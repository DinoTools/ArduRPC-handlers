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

#include "ArduRPC_Arduino_LiquidCrystal.h"

ArduRPC_Arduino_LiquidCrystal::ArduRPC_Arduino_LiquidCrystal(ArduRPC &rpc, char *name, LiquidCrystal &lcd, uint8_t width, uint8_t height) : ArduRPCHandler()
{
  this->type = 0x0300;
  this->registerSelf(rpc, name, (void *)this);

  this->lcd = &lcd;
  this->width = width;
  this->height = height;
}

uint8_t ArduRPC_Arduino_LiquidCrystal::call(uint8_t cmd_id)
{
  uint8_t i, tmp_len;
  if (cmd_id == 0x01) {
    // getWidth()
    this->_rpc->writeResult_uint8(this->width);
  } else if (cmd_id == 0x02) {
    // getHeight
    this->_rpc->writeResult_uint8(this->height);
  } else if(cmd_id == 0x11) {
    // clear()
    this->lcd->clear();
  } else if(cmd_id == 0x12) {
    // home()
    this->lcd->home();
  } else if(cmd_id == 0x13) {
    // setCursor()
    this->lcd->setCursor(
      this->_rpc->getParam_uint8(),
      this->_rpc->getParam_uint8()
    );
  } else if(cmd_id == 0x21) {
    // write()
    this->lcd->write(
      this->_rpc->getParam_uint8()
    );
  } else if(cmd_id == 0x22) {
    // print()
    tmp_len = this->_rpc->getParam_uint8();
    for (i = 0; i < tmp_len; i++)
      this->lcd->write(
        this->_rpc->getParam_uint8()
      );
  } else {
    return RPC_RETURN_COMMAND_NOT_FOUND;
  }
  return RPC_RETURN_SUCCESS;
}
