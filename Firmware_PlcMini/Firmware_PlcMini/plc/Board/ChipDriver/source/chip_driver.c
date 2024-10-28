/********************************************************************
	created:	2023/04/10
	filename: 	CHIP_DRIVER.c
	author:		MICHELGRANDA
	email:		michelgranda97@gmail.com
	tel:		+237 697 54 49 91
	
	purpose:	
*********************************************************************/


#include "plc/Board/ChipDriver/include/chip_driver.h"


void chip_driver_init(void){
	
	Input_interface_init();
	Output_interface_init();
	Analog_interface_init();
	ch340_driver_init();
	
	
}