/********************************************************************
	created:	2023/04/09
	filename: 	DRIVER_M328PB.c
	author:		MICHELGRANDA
	email:		michelgranda97@gmail.com
	tel:		+237 697 54 49 91
	
	purpose:	
*********************************************************************/

#include "plc/Board/McuDriver/m328pb/include/Driver_m328pb.h"


void Driver_m328pb_init(void){
	
	spi_configuration _spi;
	
	_spi.mode = spi_master;
	_spi.speed = FOSC_DIV4;
	_spi.transfer_direction = spi_msb;
	
	spi_execute_configuration(&_spi);
	i2c_execute_configuration(100000);
	
	
}