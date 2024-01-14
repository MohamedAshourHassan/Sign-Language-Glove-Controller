/****************************************************************************
*****************************************************************************
*****************************************************************************
***************** Author: Mohamed Ashour Hassan *****************************
***************** SW_component: ADC Drive **********************************
***************** Date:  29/8/2023 ******************************************
*/
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_
#include "../../UTILS/STD_TYPES.h"
#include "../GPIO/gpio_configuration.h"
#include "adc_configuration.h"
/*** Global variable for ADC Reading value *************/
extern volatile uint16 g_adcResult;
/*** Select the voltage reference ************************/
#define ADC_VOLTAGE_REFE_SOURCE                     EXTERNAL_AREF_AVCC
/*** ADC interrupt enable ******************************/
#define ADC_INTERRUT_STATE                          ADC_INTERRUPT_DISABLE
/*** ADC PORT COnnection *******************************/
#define ADC_PORT_CONNECTION                    		PORTA_ID
/*** The size of ADC channels to determine the array size ***/
#define ADC_0TH_CHANNEL                        ENABLE
#define ADC_1TH_CHANNEL                        ENABLE
#define ADC_2TH_CHANNEL                        ENABLE
#define ADC_3TH_CHANNEL                        ENABLE
#define ADC_4TH_CHANNEL                        ENABLE
#define ADC_5TH_CHANNEL                        DISABLE
#define ADC_6TH_CHANNEL                        DISABLE
#define ADC_7TH_CHANNEL                        DISABLE
/*** ADC pr_scaler selection ***************************/
#define ADC_CLK_SELE								CLK_64
/*** Define the value of reference voltage ***/
#if ADC_VOLTAGE_REFE_SOURCE == SYSTEM_AREF_VCC
#define VOLTAGE_REFFERNCE 			5
#elif ADC_VOLTAGE_REFE_SOURCE == EXTERNAL_AREF_AVCC
#define VOLTAGE_REFFERNCE 			5
#elif ADC_VOLTAGE_REFE_SOURCE == INTERNAL_2_56
#define VOLTAGE_REFFERNCE 			2.56
#endif
/**** The prototype of ADC initial function ************/
void ADC_init(void);
/**** The prototype of ADC read the selected channel function *****/
uint8 ADC_readChannel(uint8 ch);

#endif /* ADC_INTERFACE_H_ */
