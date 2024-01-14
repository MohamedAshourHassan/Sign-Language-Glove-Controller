/****************************************************************************
*****************************************************************************
*****************************************************************************
***************** Author: Mohamed Ashour Hassan *****************************
***************** SW_component: ADC Drive **********************************
***************** Date:  29/8/2023 ******************************************
*/
#ifndef ADC_CONFIGURATOIN_H_
#define ADC_CONFIGURATOIN_H_

/******** Redefine for bits of ADC registers **************/
/******** For bits of ADC Multiplexer Selection register ********************/
#define ADC_SELE_REFE_SOURCE_BIT7             0X80
#define ADC_SELE_REFE_SOURCE_BIT6             0X40
#define ADC_SELE_CHANNEL_BIT4                 0X10
#define ADC_SELE_CHANNEL_BIT3                 0X08
#define ADC_SELE_CHANNEL_BIT2                 0X04
#define ADC_SELE_CHANNEL_BIT1                 0X02
#define ADC_SELE_CHANNEL_BIT0                 0X01
/******** For bits of ADC Control and Status register *********************/
#define ADC_ENABLE_BIT7                       0X80
#define ADC_START_CONVERSION_BIT6             0X40
#define ADC_INT_FLAG_BIT4                     0X10
#define ADC_INT_ENABLE_BIT3                   0X08
#define ADC_SELE_CKL_BIT2                     0X04
#define ADC_SELE_CKL_BIT1                     0X02
#define ADC_SELE_CKL_BIT0                     0X01
/**** some of definitions for ADC module *****/
/**** Setting for interrupt state ************/
#define ADC_INTERRUPT_ENABLE		ADC_INT_ENABLE_BIT3
#define ADC_INTERRUPT_DISABLE		0X00
/**** Setting for select the voltage source ************/
#define SYSTEM_AREF_VCC				0X00
#define EXTERNAL_AREF_AVCC			0X40
#define INTERNAL_2_56				0XC0
/**** Setting for select the pre_scaler ******************/
#define CLK_2						0X01
#define CLK_4						0X02
#define CLK_8						0X03
#define CLK_16						0X04
#define CLK_32						0X05
#define CLK_64						0X06
#define CLK_128						0X07
/***** Some of definitions for ADC module ***/
#define CH0							0
#define CH1							1
#define CH2							2
#define CH3							3
#define CH4							4
#define CH5							5
#define CH6							6
#define CH7							7
#define ADC_MAXIMUM_VALUE			1024
#endif /* MCAL_ADC_ADC_CONFIGURATOIN_H_ */
