#ifndef GPIO_PRIVTE_H
#define GPIO_PRIVTE_H
/********************************   Redefine the naming of registers ***********************************/
/******************************** For PORTA Registers **************************************************/
/*********** This register use to determine the mode of each pin in PORTA: *****************************/
#define DDRA_ID_REG						    *((volatile uint8 *)0X3A)
/*********** This register use to write the value for each pin in PORTA: *******************************/
#define PORTA_ID_REG						*((volatile uint8 *)0X3B)
/*********** This register use to read the value of each pin in PORTA: *********************************/
#define PINA_ID_REG						    *((volatile uint8 *)0X39)
/********************************************************************************************************
 * ******************************************************************************************************
 * ******************************************************************************************************
 */
/******************************** For PORTB Registers **************************************************/
/*********** This register use to determine the mode of each pin in PORTB: *****************************/
#define DDRB_ID_REG						    *((volatile uint8 *)0X37)
/*********** This register use to write the value for each pin in PORTB: *******************************/
#define PORTB_ID_REG						*((volatile uint8 *)0X38)
/*********** This register use to read the value of each pin in PORTB: *********************************/
#define PINB_ID_REG						    *((volatile uint8 *)0X36)
/********************************************************************************************************
 * ******************************************************************************************************
 * ******************************************************************************************************
 */
/******************************** For PORTC Registers **************************************************/
/*********** This register use to determine the mode of each pin in PORTC: *****************************/
#define DDRC_ID_REG						    *((volatile uint8 *)0X34)
/*********** This register use to write the value for each pin in PORTC: *******************************/
#define PORTC_ID_REG						*((volatile uint8 *)0X35)
/*********** This register use to read the value of each pin in PORTC: *********************************/
#define PINC_ID_REG						    *((volatile uint8 *)0X33)
/********************************************************************************************************
 * ******************************************************************************************************
 * ******************************************************************************************************
 */
/******************************** For PORTD Registers **************************************************/
/*********** This register use to determine the mode of each pin in PORTD: *****************************/
#define DDRD_ID_REG						    *((volatile uint8 *)0X31)
/*********** This register use to write the value for each pin in PORTD: *******************************/
#define PORTD_ID_REG						*((volatile uint8 *)0X32)
/*********** This register use to read the value of each pin in PORTB: *********************************/
#define PIND_ID_REG						    *((volatile uint8 *)0X30)























#endif
