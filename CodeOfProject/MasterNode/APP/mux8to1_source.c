/*
 * mux8t01_source.c
 *
 *  Created on: Dec 9, 2023
 *      Author: ACS
 */
#include "mux8to1_interface.h"
#include "../MCAL/GPIO/gpio.h"
void MUX_initAndSetPinDirectionOfSelectionBits(uint8 PortName,uint8 SelectionBitsDirection)
{
	GPIO_setupPortDirection(PortName,SelectionBitsDirection);
}
void MUX_setValueOfItsSelectionBits(uint8 PortName,uint8 SelectionBitsValue)
{
	GPIO_writePort(PortName,SelectionBitsValue);
}
