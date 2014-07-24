/**
 * Read and write pin values of an Arduino board.
 *
 * Requirements:
 * - ArduRPC - https://github.com/DinoTools/ArduRPC
 * - ArduRPC_Board - https://github.com/DinoTools/ArduRPC-handlers 
 */

// Include Required libs
#include <ArduRPC.h>
#include <ArduRPC_Board.h>

#define RPC_NUM_HANDLERS 3
#define RPC_NUM_FUNCTIONS 0

// the serial port, it's also possible to use software serial
#define RPC_SERIAL_PORT Serial
#define RPC_SERIAL_BAUD 9600

// Create a new rpc instance
ArduRPC rpc = ArduRPC(RPC_NUM_HANDLERS, RPC_NUM_FUNCTIONS);
// Create a new instance of the ArduRPC serial protocol handler
ArduRPC_Serial rpc_serial = ArduRPC_Serial(RPC_SERIAL_PORT, rpc);

// Create a new ArduRPC wrapper for the Board and name it 'board'
// Params:
// 1. RPC object
// 2. Handler name
// 3. Number of analog input pins used
// 4. Number of digital input pins used
// 5. Number of digital output pins used
// 6. Number of pwm output pins used

ArduRPC_Board Board(rpc, "board", 1, 1, 1, 1);

void setup() {
  // Initialize the serial port
  RPC_SERIAL_PORT.begin(RPC_SERIAL_BAUD);

  // Analog input pin
  Board.addAnalogInput(A1);
  pinMode(A1, INPUT);

  // Digital input pin
  Board.addDigitalInput(2);
  pinMode(2, INPUT);
  
  // Digital output pin
  Board.addDigitalOutput(4);
  pinMode(4, OUTPUT);

  // PWM pin
  Board.addPWMOutput(3);
  pinMode(3, OUTPUT);
}

void loop() {
  // Process data
  rpc_serial.readData();
}
