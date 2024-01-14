/****************************************************************************
*****************************************************************************
*****************************************************************************
***************** Author: Mohamed Ashour Hassan *****************************
***************** SW_component: UART Drive ********************
***************** Date:  12/9/2023 ******************************************
*/
#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_
#include "../../UTILS/STD_TYPES.h"
/*** Setup some of configuration for UART module ***/
/*** Setup the MCU frequency value ***/
//#define F_CPU           16000000UL
/*** Select the UART speed mode ***/
#define UART_SPEED_MODE    					UART_DOUBLE_SPEED_MODE
/*** Select the interrupt state for UART_TX  ***/
#define UART_TX_INTERRUPT_STATE				UART_TX_INTERRUPT_DISABLE
/*** Select the interrupt state for UART_RX  ***/
#define UART_RX_INTERRUPT_STATE				UART_RX_INTERRUPT_DISABLE
/*** Select the interrupt state for UART_EMTY_REG ***/
#define UART_EMTY_REG_INTERRUPT_STATE		UART_EMPTY_REG_INTERRUPT_DISABLE
/*** Select the state for UART_RX  ***/
#define UART_RX_MODULE_STATE				UART_RX_ENABLE_MODULE
/*** Select the state for UART_TX  ***/
#define UART_TX_MODULE_STATE				UART_TX_ENABLE_MODULE
/*** Select the state for Parity bit mode ***/
#define UART_SELE_PARITY_MODE				UART_PRTIY_DISABLE_MODE
/*** Select the state for Stop bit mode ***/
#define UART_SELE_STOP_BIT_MODE 			UART_1TH_STOP_BIT_MODE
/*** Configuration port and RX And TX pins ***/
#define UART_TX_PORT_ID                                     PORTD_ID
#define UART_RX_PORT_ID                                     PORTD_ID
#define UART_TX_PIN_ID                                      PIN1
#define UART_RX_PIN_ID                                      PIN0
/*** Shear these object to another files in the all project ****/
#if (UART_TX_INTERRUPT_STATE		==		UART_TX_INTERRUPT_ENABLE) || (UART_EMTY_REG_INTERRUPT_STATE	==	UART_EMPTY_REG_INTERRUPT_ENABLE)
/*** This object using for send the data ***/
extern volatile uint8 g_WriteData;
#endif
#if (UART_RX_INTERRUPT_STATE		==		UART_RX_INTERRUPT_ENABLE)
/*** This object using for receive the data ***/
extern volatile uint8 g_ReadData;
#endif
/*** The prototype of initial function use to setup the UART module ***/
void UART_init(uint32 BaudRate);
#if (UART_TX_INTERRUPT_STATE		==		UART_TX_INTERRUPT_DISABLE) && (UART_EMTY_REG_INTERRUPT_STATE	==	UART_EMPTY_REG_INTERRUPT_DISABLE)
/*** The prototype of function use to send character ***/
void UART_sendByte(const uint8 data);
#endif
#if UART_RX_INTERRUPT_STATE		==		UART_RX_INTERRUPT_DISABLE
/*** The prototype of function use to receive character ***/
uint8 UART_receiveByte(void);
#endif
/*** The prototype of function use to send string ***/
void UART_sendString(const uint8 *Text);
/*** The prototype of function use to receive string ***/
void UART_receiveString(uint8 *Text);
#endif /* MCAL_UART_UART_INTERFACE_H_ */
