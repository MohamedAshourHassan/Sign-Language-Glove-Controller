/****************************************************************************
*****************************************************************************
*****************************************************************************
***************** Author: Mohamed Ashour Hassan *****************************
***************** SW_component: ADC Drive **********************************
***************** Date:  29/8/2023 ******************************************
*/
#include "adc_interface.h"
#include "adc_registers.h"
#include "../GPIO/gpio.h"
/*** Global variable for ADC Reading value *************/
volatile uint16 g_adcResult = 0;
/**** The implementation of ADC initial function ************/
void ADC_init(void)
{
/**************** Set direction for ADC selection channels *************/
#if (ADC_0TH_CHANNEL           ==             ENABLE)
		GPIO_setupPinDirection(ADC_PORT_CONNECTION,CH0,PIN_INPUT);
#endif
#if (ADC_1TH_CHANNEL           ==             ENABLE)
		GPIO_setupPinDirection(ADC_PORT_CONNECTION,CH1,PIN_INPUT);
#endif
#if (ADC_2TH_CHANNEL           ==             ENABLE)
		GPIO_setupPinDirection(ADC_PORT_CONNECTION,CH2,PIN_INPUT);
#endif
#if (ADC_3TH_CHANNEL           ==             ENABLE)
		GPIO_setupPinDirection(ADC_PORT_CONNECTION,CH3,PIN_INPUT);
#endif
#if (ADC_4TH_CHANNEL           ==             ENABLE)
		GPIO_setupPinDirection(ADC_PORT_CONNECTION,CH4,PIN_INPUT);
#endif
#if (ADC_5TH_CHANNEL           ==             ENABLE)
		GPIO_setupPinDirection(ADC_PORT_CONNECTION,CH5,PIN_INPUT);
#endif
#if (ADC_6TH_CHANNEL           ==             ENABLE)
		GPIO_setupPinDirection(ADC_PORT_CONNECTION,CH6,PIN_INPUT);
#endif
#if (ADC_7TH_CHANNEL           ==             ENABLE)
		GPIO_setupPinDirection(ADC_PORT_CONNECTION,CH7,PIN_INPUT);
#endif
		/*** Set the configuration of ADC ***/
		/*** Clear the ADC data register ***/
		ADC_DATA_REG = 0;
		/*
		 * Set the reference voltage.
		 * Enable the ADC module.
		 * Set the input clock for ADC.
		 * Set the ADC interrupt state.
		 * Disable the Auto Trigger.
		 * Disable the Left Adjust Result.
		 */
		ADC_MUX_SELE_REG = (ADC_VOLTAGE_REFE_SOURCE);
		ADC_CTL_STATUS_REG = (ADC_ENABLE_BIT7) | (ADC_CLK_SELE) | (ADC_INTERRUT_STATE);
}
/**** The implementation of ADC read the selected channel function *****/
uint8 ADC_readChannel(uint8 channel)
{
	/*** This object use for error detection ***/
	uint8 Error_state = NOTOK;
	/*** Check the input value of channels ***/
	if((channel >= CH0) && (channel <= CH7) )
	{
		/*** Set the selection channel ***/
		ADC_MUX_SELE_REG = (ADC_MUX_SELE_REG & 0XE0) | (channel & 0X07);
		/*** Set the ADC module to start conversion ***/
		ADC_CTL_STATUS_REG |= (ADC_START_CONVERSION_BIT6);
		/*** Select the polling  or interrupt technique to read conversion value ***/
#if ADC_INTERRUT_STATE == ADC_INTERRUPT_DISABLE
		/*** Stuck at ADC rise its flag ****/
		while(!(((ADC_CTL_STATUS_REG & ADC_INT_FLAG_BIT4) >> 0x04) & 0X01));
		/*** Clear the flag by set it by one ***/
		ADC_CTL_STATUS_REG |= (ADC_INT_FLAG_BIT4);
		/*** Up_data the Global resource ***/
		g_adcResult = ADC_DATA_REG;
#endif
		Error_state = OK;
	}
	return Error_state;
}
/*** The Handler of ADC module *****************/
#if ADC_INTERRUT_STATE == ADC_INTERRUPT_ENABLE
void __vector_16(void)            __attribute__((signal));
void __vector_16(void)
{
	/*** Up_data the Global resource ***/
	g_adcResult = ADC_DATA_REG;
}
#endif
