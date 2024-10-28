/********************************************************************
	created:	2023/04/09
	filename: 	TIMER.c
	author:		MICHELGRANDA
	email:		michelgranda97@gmail.com
	tel:		+237 697 54 49 91
	
	purpose:	
*********************************************************************/


#include "plc/Board/McuDriver/m328pb/include/timer.h"

volatile static uint32_t	 _counter_timer_[6] = {0,0,0,0};
volatile static uint16_t		 _preload_[6]	= {0,0,0,0}; 
		 static uint32_t	 _timer_limit_[6]	= {0,0,0,0};


static function_var _function_timer_register_[6];


/**
 * \brief 
 * 
 * \param void 
 * 
 * \return uint8_t
 */
uint8_t timer_execute_configuration(uint8_t number_timer, uint8_t _state){
	
	
	switch (number_timer)
	{
		case TIMER0:
		
				TCCR0A = 0x00;
				TCCR0B = DIV_1024;
				TIMSK0 = (_state==1 ? 1 : 0);
				_preload_[TIMER0] = (256-16);
				TCNT0  = _preload_[TIMER0]; // interruption sur 1ms avec F_CPU de 16MHz
				
			break;
		
		
		case TIMER1:
		
				TCCR1A = 0x00;
				TCCR1B = DIV_1024;
				TIMSK1 = (_state==1 ? 1 : 0);
				_preload_[TIMER1] = (0x010000 - 16);
				TCNT1H  = (uint8_t) (_preload_[TIMER1] >> 8); // interruption sur 1ms avec F_CPU de 16MHz
				TCNT1L  = (uint8_t) (_preload_[TIMER1]); // interruption sur 1ms avec F_CPU de 16MHz
				
			break;
			
			
		case TIMER2:
				
				TCCR2A = 0x00;
				TCCR2B = 0x07/*DIV_1024*/;
				TIMSK2 = (_state==1 ? 1 : 0);
				_preload_[TIMER2] = (256 - 16);
				TCNT2  = _preload_[TIMER2];
				
			break;

		case TIMER3:
		
		TCCR3A = 0x00;
		TCCR3B = DIV_1024;
		TIMSK3 = (_state==1 ? 1 : 0);
		_preload_[TIMER3] = (0x010000 - 16);
		TCNT3H  = (uint8_t) (_preload_[TIMER3] >> 8); // interruption sur 1ms avec F_CPU de 16MHz
		TCNT3L  = (uint8_t) (_preload_[TIMER3]); // interruption sur 1ms avec F_CPU de 16MHz
		
		break;			
		
		case TIMER4:
		
		TCCR4A = 0x00;
		TCCR4B = DIV_1024;
		TIMSK4 = (_state==1 ? 1 : 0);
		_preload_[TIMER4] = (0x010000 - 16);
		TCNT4H  = (uint8_t) (_preload_[TIMER4] >> 8); // interruption sur 1ms avec F_CPU de 16MHz
		TCNT4L  = (uint8_t) (_preload_[TIMER4]); // interruption sur 1ms avec F_CPU de 16MHz
		
		break;
		
		default:
		
		
			break;
	}
	
	
	return 1;
}



/**
 * \brief 
 * 
 * \param uint32_t duration_ms
 * \param uint8_t 
 * \param * ma_fonction
 * \param void 
 * 
 * \return uint8_t
 */
uint8_t timer_callback(uint8_t timer_number, uint32_t duration_ms, function_var ma_fonction ){
	
	uint32_t *pt = &_timer_limit_[timer_number];
	
	*pt = duration_ms;
	
	_function_timer_register_[timer_number] = ma_fonction;
	
	return 1;
}




//******************************routine d'interruption******************************

ISR(TIMER0_OVF_vect){ //chaque 1.024ms on entre ici
	
	_counter_timer_[TIMER0]++;

	if(_counter_timer_[TIMER0] >= _timer_limit_[TIMER0]){
		
		
		(*_function_timer_register_[TIMER0])();
		
		_counter_timer_[TIMER0] = 0;
	}	

	
	
TCNT0 = _preload_[TIMER0];	
}




ISR(TIMER1_OVF_vect){
	
	_counter_timer_[TIMER1]++;

	if(_counter_timer_[TIMER1] >= _timer_limit_[TIMER1]){
		
		
		(*_function_timer_register_[TIMER1])();
		
		_counter_timer_[TIMER1] = 0;
	}

	
	
	TCNT1H  = (uint8_t) (_preload_[TIMER1] >> 8); 
	TCNT1L  = (uint8_t) (_preload_[TIMER1]); 	
	
	
}




ISR(TIMER2_OVF_vect){ //chaque 1.024ms on entre ici
	
	_counter_timer_[TIMER2]++;

	if(_counter_timer_[TIMER2] >= _timer_limit_[TIMER2]){
		
		
		(*_function_timer_register_[TIMER2])();
		
		_counter_timer_[TIMER2] = 0;
	}

	
	
	TCNT2 = _preload_[TIMER2];
}



ISR(TIMER3_OVF_vect){
	
	_counter_timer_[TIMER3]++;

	if(_counter_timer_[TIMER3] >= _timer_limit_[TIMER3]){
		
		
		(*_function_timer_register_[TIMER3])();
		
		_counter_timer_[TIMER3] = 0;
	}

	
	
	TCNT3H  = (uint8_t) (_preload_[TIMER3] >> 8);
	TCNT3L  = (uint8_t) (_preload_[TIMER3]);
	
	
}



ISR(TIMER4_OVF_vect){
	
	_counter_timer_[TIMER4]++;

	if(_counter_timer_[TIMER4] >= _timer_limit_[TIMER4]){
		
		
		(*_function_timer_register_[TIMER4])();
		
		_counter_timer_[TIMER4] = 0;
	}

	
	
	TCNT4H  = (uint8_t) (_preload_[TIMER4] >> 8);
	TCNT4L  = (uint8_t) (_preload_[TIMER4]);
	
	
}

