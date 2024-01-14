/****************************************************************************
*****************************************************************************
*****************************************************************************
***************** Author: Mohamed Ashour Hassan *****************************
***************** SW_component: UART Drive ********************
***************** Date:  12/9/2023 ******************************************
*/
#ifndef UART_PRIVTE_H_
#define UART_PRIVTE_H_
#include "../../UTILS/STD_TYPES.h"
/**** Redefine the UART module registers ***/
/*** UART data register use for write ***/
#define UART_TX_WRITE_DATA_REG		  (*((volatile uint8 *)(0x2C)))
/*** UART data register use for read ***/
#define UART_RX_READ_DATA_REG		  (*((volatile uint8 *)(0x2C)))
/*** UART control and status register A ***/
#define UART_CTRL_STATAUS_REG_A       (*((volatile uint8 *)(0x2B)))
/*** UART control and status register B ***/
#define UART_CTRL_STATAUS_REG_B       (*((volatile uint8 *)(0x2A)))
/*** UART control and status register C ***/
#define UART_CTRL_STATAUS_REG_C       (*((volatile uint8 *)(0x40)))
/*** UART baud rate  High register ***/
#define UART_BAUD_RATE_HIGH_REG       (*((volatile uint8 *)(0x40)))
/*** UART baud rate  Low register ***/
#define UART_BAUD_RATE_LOW_REG        (*((volatile uint8 *)(0x29)))

#endif /* MCAL_UART_UART_PRIVTE_H_ */
