#ifndef Panel_h
#define Panel_h
#include <Arduino.h>

#define cmd_motor 0x01
#define cmd_motdone 0x04
#define setM 0x02
#define power 0x03

struct frame{
  unit8_t command;
  unit8_t param[3];
  }
  bool Movemotor(frame& nam,int pin){
    unit8_t position =nam.param[2];
    if (position==0x64){
      analogWrite(pin,255);
    }
    else if(position==0x32){
      analogWrite(pin,255/2);
    }
    nam.command=cmd_motdone;
    return true;
  }
bool setMotor(uint8_t pin){
  analogWrite(pin,0);
  nam.command=cmd_motdone;
  return true;
}
bool askPower(frame& nu,frame& nam,int pinv,int pinc){
  uint8_t currnt=analogRead(pinc);
  uint8_t Volta=analogRead(pinv);
  nam.command=power;
  nam.param[0]=currnt;
  nam.param[1]=volta;
  nam.param[2]=nu.param[2];
  nam.param[3]=nu.param[3];
  return true;

}
