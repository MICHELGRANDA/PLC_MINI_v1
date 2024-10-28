/********************************************************************
	created:	2023/04/10
	filename: 	OUTPUT_INTERFACE.h
	author:		MICHELGRANDA
	email:		michelgranda97@gmail.com
	tel:		+237 697 54 49 91
	
	purpose:	
*********************************************************************/


#ifndef OUTPUT_INTERFACE_H_
#define OUTPUT_INTERFACE_H_

/******************************************************************************/
//						DEFINITION DES PREPROCESSEUR
/*******************************************************************************/
   #define _NUMBER_OUTPUT 0x04


/******************************************************************************/
//						INCLUSIONS DES FICHIERS ENTETE
/*******************************************************************************/

#include "plc/board/McuDriver/m328pb/include/port.h"


/******************************************************************************/
//						DECLARATIONS DES VARIABLES		
/*******************************************************************************/
   	enum{
	   	
	   	_OUT1 = 1,
	   	_OUT2,
	   	_OUT3,
	   	_OUT4
   	};



/******************************************************************************/
//						DECLARATIONS DES PROTOTYPES		
/*******************************************************************************/

    void Output_interface_init(void);

    uint8_t Output_interface_write(uint8_t channel,uint8_t _state);




#endif /* OUTPUT_INTERFACE_H_ */