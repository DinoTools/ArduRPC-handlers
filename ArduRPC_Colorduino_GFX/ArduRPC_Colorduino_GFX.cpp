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

ArduRPC_Colorduino_GFX::ArduRPC_Colorduino_GFX(ArduRPC &rpc, char *name, ColorduinoPanel &panel) : ArduRPCHandler()
{
  this->type = 0x0280;
  this->registerSelf(rpc, name, (void *)this);

  this->panel = &panel;
  this->auto_swap = 1;
}

uint8_t ArduRPC_Colorduino_GFX::call(uint8_t cmd_id)
{
  uint16_t x;
  uint16_t y;
  uint8_t width;
  uint8_t height;
  uint8_t tmp_u8;
  uint16_t tmp_u16;
  uint8_t i, j;
  if (cmd_id == 0x01) {
    this->_rpc->writeResult_uint8(3);
    return RPC_RETURN_SUCCESS;
  } else if (cmd_id == 0x02) {
    this->_rpc->writeResult_uint16(this->panel->width());
    return RPC_RETURN_SUCCESS;
  } else if (cmd_id == 0x03) {
    this->_rpc->writeResult_uint16(this->panel->height());
    return RPC_RETURN_SUCCESS;
  } else if(cmd_id == 0x11) {
    this->panel->drawPixel(
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->panel->color(
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8()
      )
    );
  } else if(cmd_id == 0x20) {
    this->panel->drawLine(
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->panel->color(
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8()
      )
    );
  } else if(cmd_id == 0x21) {
    this->panel->drawFastVLine(
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->panel->color(
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8()
      )
    );
  } else if(cmd_id == 0x22) {
    this->panel->drawFastHLine(
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->panel->color(
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8()
      )
    );
  } else if(cmd_id == 0x23) {
    this->panel->drawRect(
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->panel->color(
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8()
      )
    );
  } else if(cmd_id == 0x24) {
    this->panel->fillRect(
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->panel->color(
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8()
      )
    );
  } else if(cmd_id == 0x25) {
    this->panel->fillScreen(
      this->panel->color(
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8()
      )
    );
  } else if(cmd_id == 0x26) {
    // ToDo
  } else if(cmd_id == 0x30) {
    this->panel->drawCircle(
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->panel->color(
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8()
      )
    );
  } else if(cmd_id == 0x31) {
    this->panel->fillCircle(
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->panel->color(
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8()
      )
    );
  } else if(cmd_id == 0x32) {
    this->panel->drawTriangle(
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->panel->color(
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8()
      )
    );
  } else if(cmd_id == 0x33) {
    this->panel->fillTriangle(
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->panel->color(
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8()
      )
    );
  } else if(cmd_id == 0x34) {
    this->panel->drawRoundRect(
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->panel->color(
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8()
      )
    );
  } else if(cmd_id == 0x35) {
    this->panel->fillRoundRect(
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->panel->color(
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8()
      )
    );
  } else if(cmd_id == 0x40) {
    this->panel->drawChar(
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_uint8(),
      this->panel->color(
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8()
      ),
      this->panel->color(
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8()
      ),
      this->_rpc->getParam_uint8()
    );
  } else if(cmd_id == 0x41) {
    this->panel->setCursor(
      this->_rpc->getParam_int16(),
      this->_rpc->getParam_int16()
    );
  } else if(cmd_id == 0x42) {
    this->panel->setTextColor(
      this->panel->color(
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8()
      )
    );
  } else if(cmd_id == 0x43) {
    this->panel->setTextColor(
      this->panel->color(
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8()
      ),
      this->panel->color(
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8(),
        this->_rpc->getParam_uint8()
      )
    );
  } else if(cmd_id == 0x44) {
    this->panel->setTextSize(
      this->_rpc->getParam_uint8()
    );
  } else if(cmd_id == 0x45) {
    this->panel->setTextWrap(
      this->_rpc->getParam_uint8()
    );
  } else if(cmd_id == 0x46) {
    this->panel->write(
      this->_rpc->getParam_uint8()
    );
  } else if(cmd_id == 0x50) {
    this->panel->setRotation(
      this->_rpc->getParam_uint8()
    );
  } else if(cmd_id == 0x51) {
    if(this->_rpc->getParam_uint8() == 1) {
      this->panel->swapBuffers(true);
    } else {
      this->panel->swapBuffers(false);
    }
    return RPC_RETURN_SUCCESS;
  } else if(cmd_id == 0x52) {
    this->auto_swap = this->_rpc->getParam_uint8();
    return RPC_RETURN_SUCCESS;
  } else if(cmd_id == 0x60) {
    x = this->_rpc->getParam_int16();
    y = this->_rpc->getParam_int16();
    width = this->_rpc->getParam_uint8();
    height = this->_rpc->getParam_uint8();
    tmp_u8 = this->_rpc->getParam_uint8();
    if (tmp_u8 == 0) {
      for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
          tmp_u8 = this->_rpc->getParam_uint8();
          this->panel->drawPixel(
            x + j,
            y + i,
            this->panel->color(
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
          tmp_u16 = this->_rpc->getParam_uint16();
          this->panel->drawPixel(
            x + j,
            y + i,
            this->panel->color(
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
          this->panel->drawPixel(
            x + j,
            y + i,
            this->panel->color(
              this->_rpc->getParam_uint8(),
              this->_rpc->getParam_uint8(),
              this->_rpc->getParam_uint8()
            )
          );
        }
      }
    }
  } else {
    return RPC_RETURN_COMMAND_NOT_FOUND;
  }
  if(this->auto_swap == 1)
    this->panel->swapBuffers(true);

  return RPC_RETURN_SUCCESS;
}
