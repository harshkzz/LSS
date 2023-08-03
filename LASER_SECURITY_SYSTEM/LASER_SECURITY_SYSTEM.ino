#include <IRremote.h>

#define IR_PIN 3
#define buzzer_pin 5
#define pin_laser A1

#define upper_intensity 130
#define lower_intensity 100

#define alarm_off 0xF30CFF00
#define alarm_test 0xE718FF00
#define system_enable 0xA15EFF00
#define system_disable 0xF708FF00

boolean system_state = true;
boolean buzzer_state = false;

IRrecv ir_sensor(IR_PIN);

void buzzer(){
    tone(buzzer_pin,500,700);
    delay(1000);
    noTone(buzzer_pin);
  }

void setup() {
  ir_sensor.enableIRIn();

}

void loop() {
  
  if(system_state == true){
      if( ! ( lower_intensity < analogRead(pin_laser) < upper_intensity )){
         buzzer_state = true;
        }

      if( buzzer_state == true || ir_sensor.decodedIRData.decodedRawData == alarm_test ){
         buzzer();
        }
  }

  if(ir_sensor.decodedIRData.decodedRawData == alarm_off ){
      buzzer_state = false;
    }

  if(ir_sensor.decodedIRData.decodedRawData == system_enable ){
      buzzer_state = true;
    }
  if(ir_sensor.decodedIRData.decodedRawData == system_disable ){
      buzzer_state = false;
    }
}
