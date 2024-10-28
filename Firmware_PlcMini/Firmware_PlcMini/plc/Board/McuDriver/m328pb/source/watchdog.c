/*
 * WATCHDOG.c
 *
 * Created: 15/11/2020 19:57:54
 *  Author: Michel
 */ 

#include "plc/Board/McuDriver/m328pb/include/watchdog.h"

function_var watchdog_pointer_function;


ISR(WDT_vect){ // routine d'interruption du watchdog
	
	
	(*watchdog_pointer_function)();
	
	watchdog_clear();

}


/**
 * \brief 
 * 
 * \param function_var function
 * 
 * \return uint8_t
 */
uint8_t watchdog_callback(function_var function){
	
	
	watchdog_pointer_function = function;
	
	return 1;
}


/**
 * \brief 
 * 
 * \param uint8_t _mode
 * \param uint8_t _timeout
 * 
 * \return uint8_t
 */
uint8_t watchdog_execute_configuration(uint8_t _mode, uint8_t _timeout){
	
	
	wdt_reset();
	MCUSR = 0;
	
	switch(_mode){
		
		case  WDT_STOPPED_MODE:
		
				WDTCSR |= (1 << WDCE) | (1 << WDE);
				WDTCSR  = 0x00;
			
			break;

		case  WDT_INTERRUPT_MODE:
		
			
			if(_timeout > 0x07){
				
				WDTCSR |= (1 << WDCE) | (1 << WDE);
				WDTCSR = (uint8_t)( (1 << WDIE) | (1 << WDP3 ) | ( (0x07 & _timeout) << 0) );
			}
			else{
				
				WDTCSR |= (1 << WDCE) | (1 << WDE);
				WDTCSR = (1 << WDIE) | ((0x07 & _timeout) << 0);
				
			}
			
			break;
		
		case  WDT_RESET_MODE:

			if(_timeout > 0x07){
				
				WDTCSR |= (1 << WDCE) | (1 << WDE);
				WDTCSR = (uint8_t)( (1 << WDE) | (1 << WDP3 ) | ( (0x07 & _timeout) << 0) );
			}
			else{
				
				WDTCSR |= (1 << WDCE) | (1 << WDE);
				WDTCSR = (1 << WDE) | ((0x07 & _timeout) << 0);
				
			}	


			break;
		
		
		case  WDT_RESET_AND_INTERRUPT_MODE:
		
		
			if(_timeout > 0x07){
				
				WDTCSR |= (1 << WDCE) | (1 << WDE);
				WDTCSR = (uint8_t)( (1 << WDE) | (1 << WDIE) | (1 << WDP3 ) | ( (0x07 & _timeout) << 0) );
			}
			else{
				
				WDTCSR |=  (1 << WDCE) | (1 << WDE);
				WDTCSR  =  (1 << WDE) | (1 << WDIE) | ((0x07 & _timeout) << 0);
				
			}
		
		
			break;
		
		
		default:
		
		
			break;			
		
	}
	
	
	return 1;
}

					

 						
 		