#pragma once
#include <Arduino.h>

class LidarBTm
{
private:
  //Serial2 on frequency 115200
  //for esp32
  const int RXD2 = 16;
  const int TXD2 = 17;

  int dist = 0; /*----actual distance measurements of LiDAR---*/
  int strength = 0; /*----signal strength of LiDAR----------------*/
  float temprature = 0; //celcius degree
  unsigned char check;

  unsigned char uart[9];
  const int HEADER=0x59;
  int rec_debug_state = 0x01;
  
public:
  LidarBTm();
  void update_all();
  
  float get_temperature();
  int get_dist();
  int get_strength();
};
