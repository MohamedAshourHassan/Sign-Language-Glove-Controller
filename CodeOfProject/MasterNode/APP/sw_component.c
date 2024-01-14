/*
 * sw_componect.c
 *
 *  Created on: Jan 7, 2024
 *      Author: ACS
 */
#include "sw_component.h"
/*******
 * The implementation of function, used to Remap the value for each sensor to 0 to 180 , then store it in each index in array *
 **/
uint8 REMAP_valueFromVoltageLevelToAngleLevel(uint16 Levels)
{
  return ((Levels * (180.0)) / (1023.0));
}
char REMAP_valueFromAngleRangeToASCIILevel(uint8 angle)
{
  return (((angle * 159.0) / (180.0)) - 80);
}
