/*
 * gpio_configuration.h
 *
 *  Created on: May 9, 2023
 *      Author: ACS
 */

#ifndef GPIO_CONFIGURATION_H_
#define GPIO_CONFIGURATION_H_

/***************** Some of definitions Keyword ****************/
typedef enum{
	PIN_INPUT,PIN_OUTPUT
}GPIO_PinDircetonType;
typedef enum{
	PORT_INPUT,PORT_OUTPUT = 0XFF
}GPIO_PortDircetonType;
/***************** Some of definitions ports ****************/
#define PORTA_ID 0
#define PORTB_ID 1
#define PORTC_ID 2
#define PORTD_ID 3
/***************** Some of definitions pins ****************/
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7



#endif /* GPIO_CONFIGURATION_H_ */
