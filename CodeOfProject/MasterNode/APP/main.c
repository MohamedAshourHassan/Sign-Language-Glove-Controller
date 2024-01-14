#include <util/delay.h>
#include <string.h>
#include "../MCAL/ADC/adc_interface.h"
#include "../MCAL/GPIO/gpio.h"
#include "../MCAL/UART/uart_interface.h"
#include "mux8to1_interface.h"
#include "sw_component.h"
#include "avr/io.h"
int main(void) {

	/**** Array  to store the sensor's data ***/
	uint16  ArrayOfDataSensor[ARRAY_SIZE] = {LOGIC_LOW};
	/**** Create the variable to realate to each sensor in the next loop ***/
    uint8 ObjectIndex = LOGIC_LOW;
    /*** Setup the ADC peripheral ***/
    ADC_init();
    /*** Setup the UART peripheral, and set the baud rate to 9600 ***/
	UART_init(9600);
	DDRC = 0XFF;
	//MUX_initAndSetPinDirectionOfSelectionBits(PORTC_ID,0X07);
    while (1) {
 /**************** This code without ht e MUX *****************************************************/
    	/*********************** The readings of all Sensor **************************
        for (ObjectIndex = SENSOR_1; ObjectIndex <= SENSOR_5; ObjectIndex ++) {
        	/*** Read the Sensor channel according to index of each cycle ****
        	ADC_readChannel(ObjectIndex);
        	/*********** Remap the value for each sensor to 0 to 180 , then store it in each index in array ***
        	ArrayOfDataSensor[ObjectIndex] = REMAP_valueFromAngleRangeToASCIILevel(REMAP_valueFromVoltageLevelToAngleLevel(g_adcResult));

        }
        */
    	/**************** This code with the MUX *****************************************************/
    	/*********************** The readings of all Sensor **************************/
        for (ObjectIndex = SENSOR_1; ObjectIndex <= SENSOR_5; ObjectIndex ++) {
        	/*** Select the channel index of MUX *****/
        	PORTC = ObjectIndex;
        	//MUX_setValueOfItsSelectionBits(PORTC_ID,ObjectIndex);
        	/*** Read the Sensor channel according to index of each cycle ****/
        	ADC_readChannel(CH0);
        	/*********** Remap the value for each sensor to 0 to 180 , then store it in each index in array ***/
        	ArrayOfDataSensor[ObjectIndex] = REMAP_valueFromAngleRangeToASCIILevel(REMAP_valueFromVoltageLevelToAngleLevel(g_adcResult));
        	_delay_ms(50);
        }
        /**** Convert analog values to a string for transmission ***/
        sprintf(ArrayOfDataSensor, "%c%c%c%c%c\n",(ArrayOfDataSensor[0]) + '0', (ArrayOfDataSensor[1]) + '0', (ArrayOfDataSensor[2]) + '0', (ArrayOfDataSensor[3]) + '0',(ArrayOfDataSensor[4]) + '0');
        /**** Send the array of data to Arduino ****/
        UART_sendString(ArrayOfDataSensor);
        /*** Delay for 2 second before sending the next set of values ***/
        _delay_ms(1000);
    }

    return 0;
}
