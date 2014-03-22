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

#include "ArduRPC_Colorduino_GFX.h"

uint8_t ArduRPC_Colorduino_GFX_Wrapper(uint8_t cmd_id, ArduRPC *rpc, void *args)
{
  uint16_t x;
  uint16_t y;
  uint8_t width;
  uint8_t height;
  uint8_t tmp_u8;
  uint16_t tmp_u16;
  uint8_t i, j;

  struct ArduRPC_Colorduino_GFX_options *options = (struct ArduRPC_Colorduino_GFX_options *)args;
  ColorduinoPanel *panel = (ColorduinoPanel*)options->panel;

  if (cmd_id == 0x01) {
    rpc->writeResult_uint8(3);
    return RPC_RETURN_SUCCESS;
  } else if (cmd_id == 0x02) {
    rpc->writeResult_uint16(panel->width());
    return RPC_RETURN_SUCCESS;
  } else if (cmd_id == 0x03) {
    rpc->writeResult_uint16(panel->height());
    return RPC_RETURN_SUCCESS;
  } else if(cmd_id == 0x11) {
    panel->drawPixel(
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      panel->color(
        rpc->getParam_uint8(),
        rpc->getParam_uint8(),
        rpc->getParam_uint8()
      )
    );
  } else if(cmd_id == 0x20) {
    panel->drawLine(
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      panel->color(
        rpc->getParam_uint8(),
        rpc->getParam_uint8(),
        rpc->getParam_uint8()
      )
    );
  } else if(cmd_id == 0x21) {
    panel->drawFastVLine(
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      panel->color(
        rpc->getParam_uint8(),
        rpc->getParam_uint8(),
        rpc->getParam_uint8()
      )
    );
  } else if(cmd_id == 0x22) {
    panel->drawFastHLine(
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      panel->color(
        rpc->getParam_uint8(),
        rpc->getParam_uint8(),
        rpc->getParam_uint8()
      )
    );
  } else if(cmd_id == 0x23) {
    panel->drawRect(
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      panel->color(
        rpc->getParam_uint8(),
        rpc->getParam_uint8(),
        rpc->getParam_uint8()
      )
    );
  } else if(cmd_id == 0x24) {
    panel->fillRect(
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      panel->color(
        rpc->getParam_uint8(),
        rpc->getParam_uint8(),
        rpc->getParam_uint8()
      )
    );
  } else if(cmd_id == 0x25) {
    panel->fillScreen(
      panel->color(
        rpc->getParam_uint8(),
        rpc->getParam_uint8(),
        rpc->getParam_uint8()
      )
    );
  } else if(cmd_id == 0x26) {
    // ToDo
  } else if(cmd_id == 0x30) {
    panel->drawCircle(
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      panel->color(
        rpc->getParam_uint8(),
        rpc->getParam_uint8(),
        rpc->getParam_uint8()
      )
    );
  } else if(cmd_id == 0x31) {
    panel->fillCircle(
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      panel->color(
        rpc->getParam_uint8(),
        rpc->getParam_uint8(),
        rpc->getParam_uint8()
      )
    );
  } else if(cmd_id == 0x32) {
    panel->drawTriangle(
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      panel->color(
        rpc->getParam_uint8(),
        rpc->getParam_uint8(),
        rpc->getParam_uint8()
      )
    );
  } else if(cmd_id == 0x33) {
    panel->fillTriangle(
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      panel->color(
        rpc->getParam_uint8(),
        rpc->getParam_uint8(),
        rpc->getParam_uint8()
      )
    );
  } else if(cmd_id == 0x34) {
    panel->drawRoundRect(
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      panel->color(
        rpc->getParam_uint8(),
        rpc->getParam_uint8(),
        rpc->getParam_uint8()
      )
    );
  } else if(cmd_id == 0x35) {
    panel->fillRoundRect(
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      panel->color(
        rpc->getParam_uint8(),
        rpc->getParam_uint8(),
        rpc->getParam_uint8()
      )
    );
  } else if(cmd_id == 0x40) {
    panel->drawChar(
      rpc->getParam_int16(),
      rpc->getParam_int16(),
      rpc->getParam_uint8(),
      panel->color(
        rpc->getParam_uint8(),
        rpc->getParam_uint8(),
        rpc->getParam_uint8()
      ),
      panel->color(
        rpc->getParam_uint8(),
        rpc->getParam_uint8(),
        rpc->getParam_uint8()
      ),
      rpc->getParam_uint8()
    );
  } else if(cmd_id == 0x41) {
    panel->setCursor(
      rpc->getParam_int16(),
      rpc->getParam_int16()
    );
  } else if(cmd_id == 0x42) {
    panel->setTextColor(
      panel->color(
        rpc->getParam_uint8(),
        rpc->getParam_uint8(),
        rpc->getParam_uint8()
      )
    );
  } else if(cmd_id == 0x43) {
    panel->setTextColor(
      panel->color(
        rpc->getParam_uint8(),
        rpc->getParam_uint8(),
        rpc->getParam_uint8()
      ),
      panel->color(
        rpc->getParam_uint8(),
        rpc->getParam_uint8(),
        rpc->getParam_uint8()
      )
    );
  } else if(cmd_id == 0x44) {
    panel->setTextSize(
      rpc->getParam_uint8()
    );
  } else if(cmd_id == 0x45) {
    panel->setTextWrap(
      rpc->getParam_uint8()
    );
  } else if(cmd_id == 0x46) {
    panel->write(
      rpc->getParam_uint8()
    );
  } else if(cmd_id == 0x50) {
    panel->setRotation(
      rpc->getParam_uint8()
    );
  } else if(cmd_id == 0x51) {
    if(rpc->getParam_uint8() == 1) {
      panel->swapBuffers(true);
    } else {
      panel->swapBuffers(false);
    }
    return RPC_RETURN_SUCCESS;
  } else if(cmd_id == 0x52) {
    options->auto_swap = rpc->getParam_uint8();
    return RPC_RETURN_SUCCESS;
  } else if(cmd_id == 0x60) {
    x = rpc->getParam_int16();
    y = rpc->getParam_int16();
    width = rpc->getParam_uint8();
    height = rpc->getParam_uint8();
    tmp_u8 = rpc->getParam_uint8();
    if (tmp_u8 == 0) {
      for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
          tmp_u8 = rpc->getParam_uint8();
          panel->drawPixel(
            x + j,
            y + i,
            panel->color(
              ((tmp_u8 & 0b11000000) >> 6) * 85,
              ((tmp_u8 & 0b00111000) >> 3) * 36,
              (tmp_u8 & 0b00000111) * 36
            )
          );
        }
      }
    } else if (tmp_u8 == 1) {
      for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
          tmp_u16 = rpc->getParam_uint16();
          panel->drawPixel(
            x + j,
            y + i,
            panel->color(
              ((tmp_u16 & 0b1111100000000000) >> 11) * 8,
              ((tmp_u16 & 0b0000011111100000) >> 5) * 4,
              ((tmp_u16 & 0b0000000000011111)) * 8
            )
          );
        }
      }
    } else if (tmp_u8 == 2) {
      for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
          panel->drawPixel(
            x + j,
            y + i,
            panel->color(
              rpc->getParam_uint8(),
              rpc->getParam_uint8(),
              rpc->getParam_uint8()
            )
          );
        }
      }
    }
  } else {
    return RPC_RETURN_COMMAND_NOT_FOUND;
  }
  if(options->auto_swap == 1)
    panel->swapBuffers(true);
}

rpc_handler_t get_ArduRPC_Colorduino_GFX_Wrapper(ColorduinoPanel &panel)
{
  struct ArduRPC_Colorduino_GFX_options *options = (struct ArduRPC_Colorduino_GFX_options *)malloc(sizeof(struct ArduRPC_Colorduino_GFX_options));
  options->auto_swap = 1;
  options->panel = &panel;
  rpc_handler_t h = {0x0280, (void *)ArduRPC_Colorduino_GFX_Wrapper, (void *)options};
  return h;
}
