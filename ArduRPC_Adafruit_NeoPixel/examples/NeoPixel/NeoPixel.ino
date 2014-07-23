/**
 * Control NeoPixels with ArduRPC
 *
 * Requirements:
 * - Adafruit_NeoPixel - https://github.com/adafruit/Adafruit_NeoPixel
 * - ArduRPC - https://github.com/DinoTools/ArduRPC
 * - ArduRPC_Adafruit_NeoPixel - https://github.com/DinoTools/ArduRPC-handlers 
 */

// Include Required libs
#include <Adafruit_NeoPixel.h>
#include <ArduRPC.h>
#include <ArduRPC_Adafruit_NeoPixel.h>

// Define some values

#define RPC_NUM_HANDLERS 3
#define RPC_NUM_FUNCTIONS 0

// the serial port, it's also possible to use software serial
#define RPC_SERIAL_PORT Serial
#define RPC_SERIAL_BAUD 9600

// Create a new rpc instance
ArduRPC rpc = ArduRPC(RPC_NUM_HANDLERS, RPC_NUM_FUNCTIONS);
// Create a new instance of the ArduRPC serial protocol handler
ArduRPC_Serial rpc_serial = ArduRPC_Serial(RPC_SERIAL_PORT, rpc);

// Copy&Paste from Adafruit_NeoPixel example
#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

// Create a new ArduRPC wrapper for the strip and name it 'strip'
ArduRPC_Adafruit_NeoPixel NeoPixel_Wrapper(rpc, "strip", strip);

void setup() {
  // Initialize the serial port
  RPC_SERIAL_PORT.begin(RPC_SERIAL_BAUD);

  // Initialize the strip
  strip.begin();
  strip.show();
}

void loop() {
  // Process data
  rpc_serial.readData();
}
