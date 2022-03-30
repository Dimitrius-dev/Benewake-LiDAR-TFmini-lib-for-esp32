#include "LidarBTm.h"

LidarBTm::LidarBTm()
{
  Serial2.begin(115200);
}

void LidarBTm::update_all()
{
  if (Serial2.available()) //check if serial port has data input
  {
  if(rec_debug_state == 0x01)
      {  //the first byte
        uart[0]=Serial2.read();
        if(uart[0] == 0x59)
            {
              check = uart[0];
              rec_debug_state = 0x02;
            }
      }
  else if(rec_debug_state == 0x02)
   {//the second byte
    uart[1]=Serial2.read();
    if(uart[1] == 0x59)
        {
          check += uart[1];
          rec_debug_state = 0x03;
        }
    else{
          rec_debug_state = 0x01;
        }
    }

  else if(rec_debug_state == 0x03)
      {
        uart[2]=Serial2.read();
        check += uart[2];
        rec_debug_state = 0x04;
      }
  else if(rec_debug_state == 0x04)
      {
        uart[3]=Serial2.read();
        check += uart[3];
        rec_debug_state = 0x05;
      }
  else if(rec_debug_state == 0x05)
      {
        uart[4]=Serial2.read();
        check += uart[4];
        rec_debug_state = 0x06;
      }
  else if(rec_debug_state == 0x06)
      {
        uart[5]=Serial2.read();
        check += uart[5];
        rec_debug_state = 0x07;
      }
  else if(rec_debug_state == 0x07)
      {
        uart[6]=Serial2.read();
        check += uart[6];
        rec_debug_state = 0x08;
      }
  else if(rec_debug_state == 0x08)
      {
        uart[7]=Serial2.read();
        check += uart[7];
        rec_debug_state = 0x09;
      }
  else if(rec_debug_state == 0x09)
      {
        uart[8]=Serial2.read();
        if(uart[8] == check)
          {
            
            dist = uart[2] + uart[3]*256;//the distance
            strength = uart[4] + uart[5]*256;//the strength
            temprature = uart[6] + uart[7] *256;//calculate chip temprature
            temprature = temprature/8 - 256;
                                            
            while(Serial2.available()){Serial2.read();} // This part is added becuase some previous packets are there in the buffer so to clear serial buffer and get fresh data.    

           }
        rec_debug_state = 0x01;
      }
  }
}

float LidarBTm::get_temperature()
{
  return temprature;
}

int LidarBTm::get_dist()
{
  return dist;
}

int LidarBTm::get_strength()
{
  return strength;
}
