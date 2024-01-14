/****************************************************************************
*****************************************************************************
*****************************************************************************
***************** Author: Mohamed Ashour Hassan *****************************
***************** SW_component: ADC Drive **********************************
***************** Date:  29/8/2023 ******************************************
*/
#ifndef ADC_REGISTERS_H_
#define ADC_REGISTERS_H_
#include "../../UTILS/STD_TYPES.h"
/******** Redefine the ADC registers **************/
/******** For ADC Multiplexer Selection register ********************/
#define ADC_MUX_SELE_REG       (*((volatile uint8 *)(0X27)))
/******** For ADC Control and Status register *********************/
#define ADC_CTL_STATUS_REG     (*((volatile uint8 *)(0X26)))
/******** For ADC Data  register **********************************/
#define ADC_DATA_REG           (*((volatile uint16 *)(0X24)))



#endif /* MCAL_ADC_ADC_REGISTERS_H_ */
