/*
 * sw_componect.h
 *
 *  Created on: Jan 7, 2024
 *      Author: ACS
 */

#ifndef APP_SW_COMPONENT_H_
#define APP_SW_COMPONENT_H_
#include "../UTILS/STD_TYPES.h"
#define ARRAY_SIZE  (6)
/********Enum of sensor's names to make the code readable ***************************************/
typedef enum{
  SENSOR_1 = 0, SENSOR_2, SENSOR_3, SENSOR_4, SENSOR_5
}SENSORS_ID;
/*** The prototype of function, used to Remap the value for each sensor to 0 to 180 , then store it in each index in array ***/
uint8 REMAP_valueFromVoltageLevelToAngleLevel(uint16 Levels);
char REMAP_valueFromAngleRangeToASCIILevel(uint8 angle);

#endif /* APP_SW_COMPONENT_H_ */
