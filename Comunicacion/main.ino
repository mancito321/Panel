#include "Panel.h"

frame inmsg;
frame outmsg;
MotorPin=#pin;
currP=#pin;
VolP=#pin;

void setup(){
  Serial.begin(9600);
  setMotor(MotorPin);
}
void loop(){
  if(newMessage(Serial,inmsg)){
    if(inmsg.command==cmd_motor){
      Movemotor(inmsg,MotorPin);
      sendMessage(Serial,inmsg);
    }
    else if(inmsg.command==setM){
      setMotor(MotorPin);
      sendMessage(Serial,inmsg);
    }
    else if(inmsg.command==power){
      askPower(inmsg, outmsg, VolP, currP);
      sendMessage(Serial,outmsg);
    }
  }
}
bool readMessage(Stream& uart ,frame& nam){
  if(uart.available()){
    if(uart.read() == 0x7E){
      unit8_t inbuffer[6];
      unit16_t check=0;
      uart.readBytes(inbuffer,6);
      for(int i=0; i<5; i++){
        check += inbuffer[i];
        }
      check = (0xFF-byte(check));
      if(tem_check == tem_buffer[5]){
        nam.command = tem_buffer[0];
        for(int i=0; i<4; i++){
          inp.params[i] = tem_buffer[i+1];
        }
        return true;
      }
  }}return false;
}
bool sendMessage(Stream& uart, frame nam){
  unit8_t output[7];
  output[0]=0x7E;
  output[1]=nam.command;
  unit16_t sum=nam.command;
  for(int i=0;i<4;i++){
    output[i+2]=inp.param[i];
    sum += inp.param[i];
  }
  output[6]=(0xFF -byte(sum));
  for(int i=0; i<7; i++){
    uart.write(output[i]);
  }

}
