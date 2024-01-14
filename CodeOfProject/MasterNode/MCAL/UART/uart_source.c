/****************************************************************************
*****************************************************************************
*****************************************************************************
***************** Author: Mohamed Ashour Hassan *****************************
***************** SW_component: UART Drive ********************
***************** Date:  12/9/2023 ******************************************
*/
/*** The prototype of initial function use to setup the UART module ***/
#include "uart_registers.h"
#include "uart_configuration.h"
#include "uart_interface.h"
#include "../GPIO/gpio.h"
#if (UART_TX_INTERRUPT_STATE		==		UART_TX_INTERRUPT_ENABLE) || (UART_EMTY_REG_INTERRUPT_STATE	==	UART_EMPTY_REG_INTERRUPT_ENABLE)
/*** This object using for send the data ***/
volatile uint8 g_WriteData = 0;
#endif
#if (UART_RX_INTERRUPT_STATE		==		UART_RX_INTERRUPT_ENABLE)
/*** This object using for receive the data ***/
volatile uint8 g_ReadData = 0;
#endif
void UART_init(uint32 BaudRate)
{
	/*** This variable use to store the value of baud_rate register ***/
	uint16 BaudRateValue = 0;
	/*** The pins direction ***/
	GPIO_setupPinDirection(UART_TX_PORT_ID,UART_TX_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(UART_RX_PORT_ID,UART_RX_PIN_ID,PIN_INPUT);
	/*** Setup the configurations for control register A ***/
	UART_CTRL_STATAUS_REG_A = (UART_SPEED_MODE);
	/*** Setup the configurations for control register B ***/
	UART_CTRL_STATAUS_REG_B = ((UART_TX_INTERRUPT_STATE) | (UART_RX_INTERRUPT_STATE) | (UART_EMTY_REG_INTERRUPT_STATE) | (UART_RX_MODULE_STATE) | (UART_TX_MODULE_STATE));
	/*** Setup the configurations for control register C ***/
	UART_CTRL_STATAUS_REG_C = ((UART_ENABLE_CTR_REG_C) | (UART_SELE_PARITY_MODE) | (UART_SELE_STOP_BIT_MODE) | (UART_8TH_DATA_SIZE_MODE));
	/*** Setup the baud_rate ***/
#if UART_SPEED_MODE    		==			UART_DOUBLE_SPEED_MODE
	/*** for double speed ***/
	BaudRateValue = (uint16)(((F_CPU / (BaudRate * 8UL))) - 1);
#elif UART_SPEED_MODE    		==			UART_NORMAL_SPEED_MODE
	/*** for normal speed ***/
	BaudRateValue = (uint16)(((F_CPU / (BaudRate * 16UL))) - 1);
#endif
	/*** First 8 bits from the BAUD_PRESCALE inside UBRRL and last 4 bits in UBRRH ***/
	UART_BAUD_RATE_HIGH_REG = BaudRateValue >> 8;
	UART_BAUD_RATE_LOW_REG =  BaudRateValue;
}
#if (UART_TX_INTERRUPT_STATE		==		UART_TX_INTERRUPT_DISABLE) && (UART_EMTY_REG_INTERRUPT_STATE	==	UART_EMPTY_REG_INTERRUPT_DISABLE)
/*** The implementation of function use to send character ***/
void UART_sendByte(const uint8 data)
{
	/*** By using the Empty flag ***/
	/*
	 * UDRE flag is set when the Tx buffer (UDR) is empty and ready for
	 * transmitting a new byte so wait until this flag is set to one
	 */
	while(!(( UART_CTRL_STATAUS_REG_A & UART_DATA_EMPTY_FLAG_BIT) >> 5));
	/*
	 * Put the required data in the UDR register and it also clear the UDRE flag as
	 * the UDR register is not empty now
	 */
	UART_TX_WRITE_DATA_REG = data;

/********************* Another method by using the TX_flag **********************/

	/*** Set the the data register by data ***
	 *** polling untill the module set the flag by one ***
	UART_TX_WRITE_DATA_REG = data;
	while(!(( UART_CTRL_STATAUS_REG_A & UART_TRANSMITTER_FLAG_BIT) >> 6));*/
}
#endif
#if UART_RX_INTERRUPT_STATE		==		UART_RX_INTERRUPT_DISABLE
/*** The implementation of function use to receive character ***/
uint8 UART_receiveByte(void)
{
	/**** polling untill the module set the flag by one ***/
	/*** RXC flag is set when the UART receive data so wait until this flag is set to one ***/
	while(!(( UART_CTRL_STATAUS_REG_A & UART_RECEIVER_FLAG_BIT) >> 7));
	/*
	 * Read the received data from the Rx buffer (UDR)
	 * The RXC flag will be cleared after read the data
	 */
	return UART_RX_READ_DATA_REG;
}
#endif
/*** The implementation of function use to send string ***/
void UART_sendString(const uint8 *Text)
{
	/*** Looping or tracking on each character in input string to null ***/
	while(*(Text) != '\0')
	{
#if (UART_TX_INTERRUPT_STATE		==		UART_TX_INTERRUPT_DISABLE) && (UART_EMTY_REG_INTERRUPT_STATE	==	UART_EMPTY_REG_INTERRUPT_DISABLE)
		UART_sendByte(*Text);
#else
		g_WriteData = *Text;
#endif
		Text++;
	}

}
/*** The implementation of function use to receive string ***/
void UART_receiveString(uint8 *Text)
{
	do
	{
#if UART_RX_INTERRUPT_STATE		==		UART_RX_INTERRUPT_DISABLE
		*Text =	UART_receiveByte();
#else
		*Text = g_ReadData;
#endif
		Text ++;
	}while(*(Text - 1) != '@');
	/*** Add the null_character in the end of string ***/
	*(Text - 1) = '\0';

}
/******************************* ISR for UART Module ****************************/
#if (UART_TX_INTERRUPT_STATE		==		UART_TX_INTERRUPT_ENABLE)
/*** For UART_TX ISR ***/
void __vector_15(void)                   __attribute__((signal));
void __vector_15(void)
{
	UART_TX_WRITE_DATA_REG = g_WriteData;
}
#endif
#if (UART_RX_INTERRUPT_STATE		==		UART_RX_INTERRUPT_ENABLE)
/*** For UART_RX ISR ***/
void __vector_13(void)                   __attribute__((signal));
void __vector_13(void)
{
	g_ReadData = UART_RX_READ_DATA_REG;
}
#endif
#if (UART_EMTY_REG_INTERRUPT_STATE	==	UART_EMPTY_REG_INTERRUPT_ENABLE)
/*** For UART_Empty register ISR ***/
void __vector_14(void)                   __attribute__((signal));
void __vector_14(void)
{
	UART_TX_WRITE_DATA_REG = g_WriteData;
}
#endif


