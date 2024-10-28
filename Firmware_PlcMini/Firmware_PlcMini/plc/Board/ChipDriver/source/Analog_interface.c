/********************************************************************
	created:	2023/04/10
	filename: 	ANALOG_INTERFACE.c
	author:		MICHELGRANDA
	email:		michelgranda97@gmail.com
	tel:		+237 697 54 49 91
	
	purpose:	
*********************************************************************/

#include "plc/Board/ChipDriver/include/Analog_interface.h"



void Analog_interface_init(void){
	
	   adc_execute_configuration();
	
}

float Analog_interface_Read_voltage(uint8_t channel){
	
	return	adc_read_voltage(channel);
	
}

