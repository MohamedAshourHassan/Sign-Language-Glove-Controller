/*
 * gpio.h
 *
 *  Created on: Apr 28, 2023
 *      Author: ACS
 */

#ifndef GPIO_H_
#define GPIO_H_
#include"../../UTILS/STD_TYPES.h"
#include "gpio_configuration.h"

/****************************** Prototype of function, use to determine the pin mode: *****************************/
void GPIO_setupPinDirection(uint8 port_num,uint8 pin_num,GPIO_PinDircetonType direction);
/****************************** Prototype of function, use to determine the pin value: *****************************/
void GPIO_writePin(uint8 port_num,uint8 pin_num,uint8 value);
/****************************** Prototype of function, use to read the pin value: *****************************/
uint8 GPIO_readPin(uint8 port_num,uint8 pin_num);
/****************************** Prototype of function, use to determine the port mode: *****************************/
void GPIO_setupPortDirection(uint8 port_num,GPIO_PinDircetonType direction);
/****************************** Prototype of function, use to determine the port value: *****************************/
void GPIO_writePort(uint8 port_num,uint8 value);
/****************************** Prototype of function, use to read the port value: *****************************/
uint8 GPIO_readPort(uint8 port_num);

#endif /* GPIO_H_ */
