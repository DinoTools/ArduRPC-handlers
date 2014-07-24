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

#include "ArduRPC_Board.h"

ArduRPC_Board::ArduRPC_Board(ArduRPC &rpc, char *name, uint8_t num_analog_input, uint8_t num_digital_input, uint8_t num_digital_output, uint8_t num_pwm_output) : ArduRPCHandler()
{
  // ToDo; Change this
  this->type = 0xff01;
  this->registerSelf(rpc, name, (void *)this);

  this->num_analog_input = num_analog_input;
  this->num_digital_input = num_digital_input;
  this->num_digital_output = num_digital_output;
  this->num_pwm_output = num_pwm_output;
  this->cur_analog_input = 0;
  this->cur_digital_input = 0;
  this->cur_digital_output = 0;
  this->cur_pwm_output = 0;
  this->pins_analog_input = (uint8_t *)malloc(num_analog_input);
  this->pins_digital_input = (uint8_t *)malloc(num_digital_input);
  this->pins_digital_output = (uint8_t *)malloc(num_digital_output);
  this->pins_pwm_output = (uint8_t *)malloc(num_pwm_output);
}

uint8_t ArduRPC_Board::addAnalogInput(uint8_t pin)
{
  if (this->cur_analog_input >= this->num_analog_input)
    return 1;
  this->pins_analog_input[this->cur_analog_input] = pin;
  this->cur_analog_input++;
  return 0;
}

uint8_t ArduRPC_Board::addDigitalInput(uint8_t pin)
{
  if (this->cur_digital_input >= this->num_digital_input)
    return 1;
  this->pins_digital_input[this->cur_digital_input] = pin;
  this->cur_digital_input++;
  return 0;
}

uint8_t ArduRPC_Board::addDigitalOutput(uint8_t pin)
{
  if (this->cur_digital_output >= this->num_digital_output)
    return 1;
  this->pins_digital_output[this->cur_digital_output] = pin;
  this->cur_digital_output++;
  return 0;
}

uint8_t ArduRPC_Board::addPWMOutput(uint8_t pin)
{
  if (this->cur_pwm_output >= this->num_pwm_output)
    return 1;
  this->pins_pwm_output[this->cur_pwm_output] = pin;
  this->cur_pwm_output++;
  return 0;
}

uint8_t ArduRPC_Board::call(uint8_t cmd_id)
{
  uint8_t pin;
  uint8_t i;
  uint8_t found;
  uint8_t val;

  found = 0;
  // getAnalogInput
  if(cmd_id == 0x11) {
    pin = this->_rpc->getParam_uint8();
    for (i = 0; i < this->cur_analog_input; i++) {
      if (this->pins_analog_input[i] != pin)
        continue;
      found = 1;
      break;
    }
    if (found == 0)
      return 2;
    this->_rpc->writeResult_uint16(analogRead(pin));
  } else if(cmd_id == 0x21) {
    // getDigitalInput
    pin = this->_rpc->getParam_uint8();
    for (i = 0; i < this->cur_digital_input; i++) {
      if (this->pins_digital_input[i] != pin)
        continue;
      found = 1;
      break;
    }
    if (found == 0)
      return 2;
    this->_rpc->writeResult_uint8(digitalRead(pin));
  } else if(cmd_id == 0x22) {
    // setDigitalOutput
    pin = this->_rpc->getParam_uint8();
    val = this->_rpc->getParam_uint8();

    for (i = 0; i < this->cur_digital_output; i++) {
      if (this->pins_digital_output[i] != pin)
        continue;
      found = 1;
      break;
    }
    if (found == 0)
      return 2;
    digitalWrite(pin, val);
  } else if(cmd_id == 0x31) {
    // setPWMOutput
    pin = this->_rpc->getParam_uint8();
    val = this->_rpc->getParam_uint8();

    for (i = 0; i < this->cur_pwm_output; i++) {
      if (this->pins_pwm_output[i] != pin)
        continue;
      found = 1;
      break;
    }
    if (found == 0)
      return 2;
    analogWrite(pin, val);
  } else {
    return RPC_RETURN_COMMAND_NOT_FOUND;
  }
  return RPC_RETURN_SUCCESS;
}
