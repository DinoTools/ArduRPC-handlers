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

#include "ArduRPC_Adafruit_NeoPixel.h"

ArduRPC_Adafruit_NeoPixel::ArduRPC_Adafruit_NeoPixel(ArduRPC &rpc, char *name, Adafruit_NeoPixel &strip) : ArduRPCHandler()
{
  this->type = 0x0181;
  this->registerSelf(rpc, name, (void *)this);

  this->strip = &strip;
}

uint8_t ArduRPC_Adafruit_NeoPixel::call(uint8_t cmd_id)
{
  uint32_t color;
  uint16_t start;
  uint16_t end;
  uint16_t i;

  if (cmd_id == 0x01) {
    this->_rpc->writeResult_uint8(3);
    return RPC_RETURN_SUCCESS;
  } else if (cmd_id == 0x02) {
    this->_rpc->writeResult_uint16(this->strip->numPixels());
    return RPC_RETURN_SUCCESS;
  } else if (cmd_id == 0x11) {
    this->strip->setPixelColor(
      this->_rpc->getParam_uint16(),
      this->strip->Color(
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8()
      )
    );
  } else if (cmd_id == 0x12) {
    start = this->_rpc->getParam_uint16();
    end = this->_rpc->getParam_uint16();
    color = this->strip->Color(
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8()
    );

    if (start > end) {
      i = end;
      end = start;
      start = i;
    }

    for (i = start; i < end; i++) {
      this->strip->setPixelColor(i, color);
    }
  }
  this->strip->show();
  return RPC_RETURN_SUCCESS;
}
