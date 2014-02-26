/**
 * Read temperature and humidity values from DHT sensors with ArduRPC
 *
 * Requirements:
 * - DHT - https://github.com/adafruit/DHT-sensor-library
 * - ArduRPC
 * - ArduRPC_Adafruit_DHT - https://github.com/DinoTools/ArduRPC-handlers 
 */
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

#include <ArduRPC.h>
#include <ArduRPC_Adafruit_DHT.h>

#define RPC_NUM_HANDLERS 3
#define RPC_NUM_FUNCTIONS 0

// the serial port, it's also possible to use software serial
#define RPC_SERIAL_PORT Serial
#define RPC_SERIAL_BAUD 9600

ArduRPC rpc = ArduRPC(RPC_NUM_HANDLERS, RPC_NUM_FUNCTIONS);
ArduRPCSerial rpc_serial = ArduRPCSerial(RPC_SERIAL_PORT, rpc);

void setup() {
  uint8_t handler_id;
  
  RPC_SERIAL_PORT.begin(RPC_SERIAL_BAUD);

  dht.begin();

  handler_id = rpc.connectHandler(get_ArduRPC_Adafruit_DHT_Wrapper(dht, DHTTYPE));
  rpc.setHandlerName(handler_id, "dht");
}

void loop() {
  rpc_serial.readData();
}
