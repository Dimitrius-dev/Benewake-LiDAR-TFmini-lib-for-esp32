#include "LidarBTm.h"

LidarBTm lidar;

void setup() {
  delay(2000);
  Serial.begin(115200);
}

void loop() {
  lidar.update_all();
  Serial.print("dist = ");
  Serial.println(lidar.get_dist());
  
  Serial.print("temp = ");
  Serial.println(lidar.get_temperature());
  delay(10);
}
