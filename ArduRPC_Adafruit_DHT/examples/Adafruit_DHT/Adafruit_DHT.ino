/**
 * Read temperature and humidity values from DHT sensors with ArduRPC
 *
 * Requirements:
 * - DHT - https://github.com/adafruit/DHT-sensor-library
 * - ArduRPC - https://github.com/DinoTools/ArduRPC
 * - ArduRPC_Adafruit_DHT - https://github.com/DinoTools/ArduRPC-handlers 
 */

// Include Required libs
#include <DHT.h>
#include <ArduRPC.h>
#include <ArduRPC_Adafruit_DHT.h>

// Define some values
#define DHTPIN 2
#define DHTTYPE DHT22

#define RPC_NUM_HANDLERS 3
#define RPC_NUM_FUNCTIONS 0

// the serial port, it's also possible to use software serial
#define RPC_SERIAL_PORT Serial
#define RPC_SERIAL_BAUD 9600

// Create a new rpc instance
ArduRPC rpc = ArduRPC(RPC_NUM_HANDLERS, RPC_NUM_FUNCTIONS);
// Create a new instance of the ArduRPC serial protocol handler
ArduRPC_Serial rpc_serial = ArduRPC_Serial(RPC_SERIAL_PORT, rpc);

// Create a new DHT instance
DHT dht(DHTPIN, DHTTYPE);
// Create a new ArduRPC wrapper for the DHT and name it 'sensor'
ArduRPC_Adafruit_DHT Adafruit_DHT_Wrapper(rpc, "sensor", dht, DHTTYPE));

void setup() {
  // Initialize the serial port
  RPC_SERIAL_PORT.begin(RPC_SERIAL_BAUD);

  // Initialize the DHT sensor.
  dht.begin();
}

void loop() {
  // Process data
  rpc_serial.readData();
}
