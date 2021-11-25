/*
 * Getting the human readable distance from Ultrasonic sensor.
 *
 * @author e3stpavel
 * 
 * @param sensor Sensor place on the module (meaning esL - left or esR - right). 1 - stands for LEFT, 0 - stands for RIGHT, 
 * BUT depends on connecting order in main.cpp, for now ESR and then ESL
 * @return int Human readable distance from ultrasonic sensor in cm
 */ 

int get_ultrasonic_distance(uint8_t sensor)
{
  // ping_cm returns unsigned long, so its a lot of space so i decided to go with simple integer 
  int distance = sonar[sensor].ping_cm();

  return distance;
}