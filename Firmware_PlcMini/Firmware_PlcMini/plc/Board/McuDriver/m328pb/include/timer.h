/********************************************************************
	created:	2023/04/09
	filename: 	TIMER.h
	author:		MICHELGRANDA
	email:		michelgranda97@gmail.com
	tel:		+237 697 54 49 91
	
	purpose:	
*********************************************************************/

#ifndef TIMER_H_
#define TIMER_H_

//*********************************************************************
//							    INCLUDE
//*********************************************************************
#include "common.h"




//*********************************************************************
//								DEFINITION
//*********************************************************************

#define DIV_1			0x01
#define DIV_8			0x02
#define DIV_64			0x03
#define DIV_256			0x04
#define DIV_1024		0x05


#define TIMER0			0x00
#define TIMER1			0x01
#define TIMER2			0x02
#define TIMER3			0x03
#define TIMER4			0x04




//*********************************************************************
//								DECLARATION DES PROTOTYPES
//*********************************************************************

#ifdef __cplusplus

extern "C"
{
	
#endif

uint8_t timer_execute_configuration(uint8_t number_timer, uint8_t _state);

uint8_t timer_callback(uint8_t timer_number, uint32_t duration_ms, function_var ma_fonction );


#ifdef __cplusplus

} //extern "C"

#endif




#endif /* TIMER_H_ */