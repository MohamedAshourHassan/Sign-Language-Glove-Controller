/*
 * mux8to1_interface.h
 *
 *  Created on: Dec 9, 2023
 *      Author: ACS
 */

#ifndef HAL_MUX_8_TO_1_MUX8TO1_INTERFACE_H_
#define HAL_MUX_8_TO_1_MUX8TO1_INTERFACE_H_
#include"../UTILS/STD_TYPES.h"


void MUX_initAndSetPinDirectionOfSelectionBits(uint8 PortName,uint8 SelectionBitsDirection);
void MUX_setValueOfItsSelectionBits(uint8 PortName,uint8 SelectionBitsValue);

#endif /* HAL_MUX_8_TO_1_MUX8TO1_INTERFACE_H_ */
