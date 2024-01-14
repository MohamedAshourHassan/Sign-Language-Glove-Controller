#include"gpio.h"
#include"gpio_privte.h"
#include"../../UTILS/common_macro.h"

/*** Implementation of function, use to determine the pin mode***/
void GPIO_setupPinDirection(uint8 port_num,uint8 pin_num,GPIO_PinDircetonType direction)
{
	if(!((port_num > 3) || (pin_num > 7)))
	{
		switch(port_num)
		{
			case PORTA_ID:
				if(direction == PIN_OUTPUT)
				{
					SET_BIT(DDRA_ID_REG,pin_num);
				}
				else
				{
					CLEAR_BIT(DDRA_ID_REG,pin_num);
				}
				break;
			case PORTB_ID:
				if(direction == PIN_OUTPUT)
				{
					SET_BIT(DDRB_ID_REG,pin_num);
				}
				else
				{
					CLEAR_BIT(DDRB_ID_REG,pin_num);
				}
				break;
			case PORTC_ID:
				if(direction == PIN_OUTPUT)
				{
					SET_BIT(DDRC_ID_REG,pin_num);
				}
				else
				{
					CLEAR_BIT(DDRC_ID_REG,pin_num);
				}
				break;
			case PORTD_ID:
				if(direction == PIN_OUTPUT)
				{
					SET_BIT(DDRD_ID_REG,pin_num);
				}
				else
				{
					CLEAR_BIT(DDRD_ID_REG,pin_num);
				}
				break;
		}
	}
}
/*** Implementation of function, use to write the pin value***/
void GPIO_writePin(uint8 port_num,uint8 pin_num,uint8 value)
{
	if(!((port_num > 3) || (pin_num > 7)))
	{
		switch(port_num)
		{
			case PORTA_ID:
				if(value == LOGIC_HIGH)
				{
					SET_BIT(PORTA_ID_REG,pin_num);
				}
				else
				{
					CLEAR_BIT(PORTA_ID_REG,pin_num);
				}
				break;
			case PORTB_ID:
				if(value == LOGIC_HIGH)
				{
					SET_BIT(PORTB_ID_REG,pin_num);
				}
				else
				{
					CLEAR_BIT(PORTB_ID_REG,pin_num);
				}
				break;
			case PORTC_ID:
				if(value == LOGIC_HIGH)
				{
					SET_BIT(PORTC_ID_REG,pin_num);
				}
				else
				{
					CLEAR_BIT(PORTC_ID_REG,pin_num);
				}
				break;
			case PORTD_ID:
				if(value == LOGIC_HIGH)
				{
					SET_BIT(PORTD_ID_REG,pin_num);
				}
				else
				{
					CLEAR_BIT(PORTD_ID_REG,pin_num);
				}
				break;
		}
	}
}
/*** Implementation of function, use to read the pin value***/
uint8 GPIO_readPin(uint8 port_num,uint8 pin_num)
{
	uint8 value = 0;
	if(!((port_num > 3) || (pin_num > 7)))
	{
		switch(port_num)
		{
			case PORTA_ID:
						value = READ_BIT(PINA_ID_REG,pin_num);
				break;
			case PORTB_ID:
				value = READ_BIT(PINB_ID_REG,pin_num);
				break;
			case PORTC_ID:
				value = READ_BIT(PINC_ID_REG,pin_num);
				break;
			case PORTD_ID:
				value = READ_BIT(PIND_ID_REG,pin_num);
				break;
		}
	}
	return value;
}
/*** Implementation of function, use to determine the port mode***/
void GPIO_setupPortDirection(uint8 port_num,GPIO_PinDircetonType direction)
{
	if(!(port_num > 3))
	{
		switch(port_num)
		{
			case PORTA_ID:
				DDRA_ID_REG |= direction;
				break;
			case PORTB_ID:
				DDRB_ID_REG |= direction;
				break;

			case PORTC_ID:
				DDRC_ID_REG |= direction;
				break;
			case PORTD_ID:
				DDRD_ID_REG |= direction;
				break;

		}
	}
}
/*** Implementation of function, use to write the port value***/
void GPIO_writePort(uint8 port_num,uint8 value)
{
	if(!(port_num > 3))
	{
		switch(port_num)
		{
			case PORTA_ID:
				PORTA_ID_REG = value;
				break;
			case PORTB_ID:
				PORTB_ID_REG = value;
				break;

			case PORTC_ID:
				PORTC_ID_REG = value;
				break;
			case PORTD_ID:
				PORTD_ID_REG = value;
				break;

		}
	}
}
/*** Implementation of function, use to read the port value***/
uint8 GPIO_readPort(uint8 port_num)
{
	uint8 value = 0;
	if(!(port_num > 3))
	{
		switch(port_num)
		{
			case PORTA_ID:
				value = PINA_ID_REG;
				break;
			case PORTB_ID:
				value = PINB_ID_REG;
				break;
			case PORTC_ID:
				value = PINC_ID_REG;
				break;
			case PORTD_ID:
				value = PIND_ID_REG;
				break;
		}
	}
	return value;
}
