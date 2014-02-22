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

uint8_t ArduRPC_Adafruit_NeoPixel_Wrapper(uint8_t cmd_id, ArduRPC *rpc, void *args)
{
  uint32_t color;
  uint16_t start;
  uint16_t end;
  uint16_t i;

  struct ArduRPC_Adafruit_NeoPixel_options *options = (struct ArduRPC_Adafruit_NeoPixel_options *)args;
  Adafruit_NeoPixel *strip = (Adafruit_NeoPixel*)options->strip;

  if (cmd_id == 0x01) {
    rpc->writeResult_uint8(3);
    return RPC_RETURN_SUCCESS;
  } else if (cmd_id == 0x02) {
    rpc->writeResult_uint16(strip->numPixels());
    return RPC_RETURN_SUCCESS;
  } else if (cmd_id == 0x11) {
    strip->setPixelColor(
      rpc->getParam_uint16(),
      strip->Color(
        rpc->getParam_uint8(),
        rpc->getParam_uint8(),
        rpc->getParam_uint8()
      )
    );
  } else if (cmd_id == 0x12) {
    start = rpc->getParam_uint16();
    end = rpc->getParam_uint16();
    color = strip->Color(
        rpc->getParam_uint8(),
        rpc->getParam_uint8(),
        rpc->getParam_uint8()
    );

    if (start > end) {
      i = end;
      end = start;
      start = i;
    }

    for (i = start; i < end; i++) {
      strip->setPixelColor(i, color);
    }
  }
  strip->show();
  return RPC_RETURN_SUCCESS;
}

rpc_handler_t get_ArduRPC_Adafruit_NeoPixel_Wrapper(Adafruit_NeoPixel &strip)
{
  struct ArduRPC_Adafruit_NeoPixel_options *options = (struct ArduRPC_Adafruit_NeoPixel_options *)malloc(sizeof(struct ArduRPC_Adafruit_NeoPixel_options));
  options->strip = &strip;
  rpc_handler_t h = {0x0181, (void *)ArduRPC_Adafruit_NeoPixel_Wrapper, (void *)options};
  return h;
}
