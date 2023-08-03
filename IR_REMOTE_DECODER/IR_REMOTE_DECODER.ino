#include <IRremote.h>

#define IR_PIN 3

IRrecv ir_sensor(IR_PIN);

void setup() {
  ir_sensor.enableIRIn();
  Serial.begin(9600);
}

void loop() {
  if(ir_sensor.decode()){
        Serial.println(ir_sensor.decodedIRData.decodedRawData, HEX);
    }

}
