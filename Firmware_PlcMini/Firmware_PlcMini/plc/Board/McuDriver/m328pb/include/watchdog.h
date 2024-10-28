/*
 * watchdog.h
 *
 * Created: 15/11/2020 19:55:00
 *  Author: Michel
 */ 


#ifndef WATCHDOG_H_
#define WATCHDOG_H_


//*********************************************************************
//							    INCLUDE
//*********************************************************************

#include "port.h"
#include "common.h"


//*********************************************************************
//								DEFINITION
//*********************************************************************

#define WDT_STOPPED_MODE					0x00
#define WDT_INTERRUPT_MODE					0x01
#define WDT_RESET_MODE						0x02
#define WDT_RESET_AND_INTERRUPT_MODE		0x03


#define WDT_TIMEOUT_16ms			0x00
#define WDT_TIMEOUT_32ms			0x01
#define WDT_TIMEOUT_64ms			0x02
#define WDT_TIMEOUT_125ms			0x03
#define WDT_TIMEOUT_250ms			0x04
#define WDT_TIMEOUT_500ms			0x05
#define WDT_TIMEOUT_1s				0x06
#define WDT_TIMEOUT_2s				0x07
#define WDT_TIMEOUT_4s				0x08
#define WDT_TIMEOUT_8s				0x09



//*********************************************************************
//								DECLARATION DES PROTOTYPES
//*********************************************************************


#ifdef __cplusplus

extern "C"
{
	
#endif


uint8_t watchdog_execute_configuration(uint8_t _mode, uint8_t _timeout);

uint8_t watchdog_callback(function_var function);


inline uint8_t watchdog_clear(void){
	
	wdt_reset();
	return 1;
}




#ifdef __cplusplus

} //extern "C"

#endif


#endif /* WATCHDOG_H_ */