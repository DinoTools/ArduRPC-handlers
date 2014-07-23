/**
 * Control your Colorduino with ArduRPC
 *
 * Requirements:
 * - Adafruit_GFX - https://github.com/adafruit/Adafruit-GFX-Library
 * - Colorduino_GFX - https://github.com/DinoTools/Colorduino_GFX
 * - ArduRPC - https://github.com/DinoTools/ArduRPC
 * - ArduRPC_Colorduino_GFX - https://github.com/DinoTools/ArduRPC-handlers 
 */

// Include Required libs
#include <Adafruit_GFX.h>
#include <Colorduino_GFX.h>

#include <ArduRPC.h>
#include <ArduRPC_Colorduino_GFX.h>

// Define some values
#define RPC_NUM_HANDLERS 3
#define RPC_NUM_FUNCTIONS 0

// the serial port, it's also possible to use a software serial
#define RPC_SERIAL_PORT Serial
#define RPC_SERIAL_BAUD 9600

// Create a new rpc instance
ArduRPC rpc = ArduRPC(RPC_NUM_HANDLERS, RPC_NUM_FUNCTIONS);
// Create a new instance of the ArduRPC serial protocol handler
ArduRPC_Serial rpc_serial = ArduRPC_Serial(RPC_SERIAL_PORT, rpc);

// Create a new Colorduino instance
ColorduinoPanel Colorduino;
// Create a new ArduRPC wrapper for the Colorduino and name it 'matrix'
ArduRPC_Colorduino_GFX Colorduino_GFX_Wrapper(rpc, "matrix", Colorduino);

void setup() {
  // Initialize the serial port
  RPC_SERIAL_PORT.begin(RPC_SERIAL_BAUD);

  // Initialize and active the Colorduino
  Colorduino.init();
  Colorduino.begin();
}

void loop() {
  // read and process serial data
  rpc_serial.readData();
}
