/**
 * Control your LCD with ArduRPC
 *
 * Requirements:
 * - LiquidCrystal - Included since Arduino 1.0.5
 * - ArduRPC - https://github.com/DinoTools/ArduRPC
 * - ArduRPC_Colorduino_GFX - https://github.com/DinoTools/ArduRPC-handlers 
 */

// Include Required libs
#include <LiquidCrystal.h>

#include <ArduRPC.h>
#include <ArduRPC_Arduino_LiquidCrystal.h>

// Define some values
#define RPC_NUM_HANDLERS 3
#define RPC_NUM_FUNCTIONS 0

#define LCD_WIDTH 16
#define LCD_HEIGHT 2

// the serial port, it's also possible to use a software serial
#define RPC_SERIAL_PORT Serial
#define RPC_SERIAL_BAUD 9600

// Create a new rpc instance
ArduRPC rpc = ArduRPC(RPC_NUM_HANDLERS, RPC_NUM_FUNCTIONS);
// Create a new instance of the ArduRPC serial protocol handler
ArduRPC_Serial rpc_serial = ArduRPC_Serial(RPC_SERIAL_PORT, rpc);

// Create a new LiqudCrystal instance
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// Create a new ArduRPC wrapper for the LCD and name it 'lcd'
ArduRPC_Arduino_LiquidCrystal LCD_Wrapper(rpc, "lcd", lcd, LCD_WIDTH, LCD_HEIGHT);

void setup() {
  // Initialize the serial port
  RPC_SERIAL_PORT.begin(RPC_SERIAL_BAUD);

  // Initialize and active the LCD
  lcd.begin(LCD_WIDTH, LCD_HEIGHT);
}

void loop() {
  // read and process serial data
  rpc_serial.readData();
}
