/****************************************************************************
*****************************************************************************
*****************************************************************************
***************** Author: Mohamed Ashour Hassan *****************************
***************** SW_component: UART Drive ********************
***************** Date:  12/9/2023 ******************************************
*/
#ifndef UART_CONFIGURATION_H_
#define UART_CONFIGURATION_H_
/**** Redefine the Bits of UART module registers ***/
/*** For control register A ***/
#define UART_RECEIVER_FLAG_BIT           		 0x80
#define UART_TRANSMITTER_FLAG_BIT           	 0x40
#define UART_DATA_EMPTY_FLAG_BIT            	 0x20
#define UART_FRAME_ERROR_FLAG_BIT     		     0x10
#define UART_OVERRUN_FLAG_BIT          		     0x08
#define UART_PARTIY_ERROR_FLAG_BIT               0x04
#define UART_DOUBLE_TRANS_SPEED_BIT              0x02
/*** For control register B ***/
#define UART_RECEIVER_INTERRUPT_ENABLE_BIT       0x80
#define UART_TRANSMITTER_INTERRUPT_ENABLE_BIT    0x40
#define UART_DATA_EMPTY_INTERRUPT_ENABLE_BIT     0x20
#define UART_RECEIVER_ENABLE_BIT				 0x10
#define UART_TRANSMITTER_ENABLE_BIT				 0x08
#define UART_SELE_DATA_SIZE_BIT2                 0x04
/*** For control register C ***/
#define UART_SELE_REG                            0x80
#define UART_SELE_MODE_BIT                       0x40
#define UART_SELE_PARITY_MODE_BIT1               0x20
#define UART_SELE_PARITY_MODE_BIT0               0x10
#define UART_SELE_STOP_BIT_MODE_BIT              0x08
#define UART_SELE_DATA_SIZE_BIT1                 0x04
#define UART_SELE_DATA_SIZE_BIT0                 0x02
/*** Some of UART definitions ***/
/*** UART select speed mode ***/
#define UART_DOUBLE_SPEED_MODE 				(UART_DOUBLE_TRANS_SPEED_BIT)
#define UART_NORMAL_SPEED_MODE				0x00
/*** UART select interrupt state for UART_TX ***/
#define UART_TX_INTERRUPT_ENABLE			(UART_TRANSMITTER_INTERRUPT_ENABLE_BIT)
#define UART_TX_INTERRUPT_DISABLE			0x00
/*** UART select interrupt state for UART_RX ***/
#define UART_RX_INTERRUPT_ENABLE			(UART_RECEIVER_INTERRUPT_ENABLE_BIT)
#define UART_RX_INTERRUPT_DISABLE			0x00
/*** UART select interrupt state for UART_EMTY_REG ***/
#define UART_EMPTY_REG_INTERRUPT_ENABLE 	(UART_DATA_EMPTY_INTERRUPT_ENABLE_BIT)
#define UART_EMPTY_REG_INTERRUPT_DISABLE    0x00
/*** UART select the state for UART_RX ***/
#define UART_RX_ENABLE_MODULE				(UART_RECEIVER_ENABLE_BIT)
#define UART_RX_DISABLE_MODULE				0x00
/*** UART select the state for UART_TX ***/
#define UART_TX_ENABLE_MODULE			    (UART_TRANSMITTER_ENABLE_BIT)
#define UART_TX_DISABLE_MODULE				0x00
/*** UART select the Parity mode ***/
#define UART_PRTIY_DISABLE_MODE			    0x00
#define UART_PRTIY_EVEN_MODE			    (UART_SELE_PARITY_MODE_BIT1)
#define UART_PRTIY_ODD_MODE					((UART_SELE_PARITY_MODE_BIT1) | (UART_SELE_PARITY_MODE_BIT0))
/*** UART select the Stop bit mode ***/
#define UART_1TH_STOP_BIT_MODE				0x00
#define UART_2TH_STOP_BIT_MODE				(UART_SELE_STOP_BIT_MODE_BIT)
/*** UART select the Stop bit mode ***/
#define UART_8TH_DATA_SIZE_MODE             ((UART_SELE_DATA_SIZE_BIT1) | (UART_SELE_DATA_SIZE_BIT0))
/*** Select the register ***/
#define UART_ENABLE_CTR_REG_C				(UART_SELE_REG)
#define UART_ENABLE_BAUD_RATE_REG			(0x00)
#endif /* MCAL_UART_UART_CONFIGURATION_H_ */
