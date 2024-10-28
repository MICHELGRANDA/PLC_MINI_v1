

#include "plc/Board/McuDriver/m328pb/include/usart.h"



//static uint8_t(*function_register[4])(void);

static function_var function_register[4];









/**
 * \brief 
 * 
 * \param volatile uint8_t * channel
 * \param usart_configuration * _usart
 * 
 * \return uint8_t
 */
uint8_t usart_execute_configuration(volatile uint8_t *channel, usart_configuration *_usart){

	uint16_t _baud = 0;
	
	
	_baud = (uint16_t)( ( F_CPU/( (_usart->baudrate) * 16) ) - 1); //calcul la valeur du bauderate
	
	*(channel + 0x05) = (_baud >> 8); // on insere dans UBRRxH
	*(channel + 0x04) = (_baud & 0x00FF); // on insere dans UBRRxL
	
	
	*(channel + 0x01) |= (1 << RXEN0) | (1 << TXEN0); // on active le module de reception et transmission du module USART
	
	
	switch(_usart->parity){// choix des parité
	
		case none:
	
			*(channel + 0x02) &= ~( (1 << UPM01) | (1 << UPM00) );  
	
			break;
	
		case even:
			
			*(channel + 0x02) &= ~( (1 << UPM00) ); 
			*(channel + 0x02) |=  ( (1 << UPM01) ); 
	
			break;
	
		case odd:
		
			*(channel + 0x02) |=  ( (1 << UPM00) );
			*(channel + 0x02) |=  ( (1 << UPM01) );	
	
			break;
	
		default:
		
			*(channel + 0x02) &= ~( (1 << UPM01) | (1 << UPM00) );  // tout autre valeur c'est NONE parity
	
			break;
	
	}
	
	
	
	switch(_usart->data_bit_frame){ // choix de la taille des donnees
		
		case frame_5bit:
			
			*(channel + 0x02) &= ~(0x03 << 1);
			*(channel + 0x02) |=  (frame_5bit << 1);
			
			break;
			
		case frame_6bit:
		
			*(channel + 0x02) &= ~(0x03 << 1);
			*(channel + 0x02) |=  (frame_6bit << 1);
					
		break;
		
		case frame_7bit:
		
			*(channel + 0x02) &= ~(0x03 << 1);
			*(channel + 0x02) |=  (frame_7bit << 1);	
				
			break;
		
		case frame_8bit:

			*(channel + 0x02) &= ~(0x03 << 1);
			*(channel + 0x02) |=  (frame_8bit << 1);
					
			break;
			
		case frame_9bit:
		
		
		
			break;
			
		default:
		
			*(channel + 0x02) &= ~(0x03 << 1);
			*(channel + 0x02) |=  (frame_8bit << 1);	
				
			break;
				
	}
	
	
	switch (_usart->stop_bit){ // choix du nombre de bit de stop
		
		case stop_1bit:
	
			*(channel + 0x02) &= ~(1 << USBS0);
	
			break;
		
		
		case stop_2bit:
		
			*(channel + 0x02) |= (1 << USBS0);	
					
			break;
			
		default:
			
			*(channel + 0x02) &= ~(1 << USBS0);
			
			break;
	}
	
	
	if (_usart->receive_interruption == On){ // ACTIVATION OU NON DE L4INTERRUPTION DE RECEPTION
		
		*(channel + 0x01) |= (1 << RXCIE0);
		
	} 
	else{
		
		*(channel + 0x01) &= ~(1 << RXCIE0);
		
	}
	
	
	return 1;
}


/**
 * \brief 
 * 
 * \param volatile uint8_t * channel
 * \param uint8_t data
 * 
 * \return uint8_t
 */
uint8_t usart_write_data(volatile uint8_t *channel, uint8_t data){

	while( !(*(channel + 0x00) & (1 << UDRE0)) );
	
	*(channel + 06) = data;
	
	
	
	return 1;
}


/**
 * \brief 
 * 
 * \param volatile uint8_t * channel
 * 
 * \return uint8_t
 */
uint8_t usart_read_data(volatile uint8_t *channel){

uint8_t recv = 0;

	recv = *(channel + 0x06);
	
	return recv;
}


/**
 * \brief 
 * 
 * \param volatile uint8_t * channel
 * \param uint8_t * data
 * \param uint16_t len
 * 
 * \return uint8_t
 */
uint8_t usart_write_text(volatile uint8_t *channel, uint8_t *data, uint32_t len){

	uint32_t i = 0;
	
	if(len == 0){
		
		for(i=0; data[i] != 0; i++){
			
			usart_write_data(channel,data[i]);
		}
		
	}
	else{
		
			for(i=0; i<len; i++){
				
				usart_write_data(channel,data[i]);
			}
		
	}

	return 1;
}


/**
 * \brief 
 * 
 * \param volatile uint8_t * channel
 * 
 * \return uint8_t
 */
uint8_t usart_data_ready(volatile uint8_t *channel){
	
	if( ( *(channel + 0x00) & (1 << RXC0)) ){
		
		return 1;
	}
	
	return 0;
}


/**
 * \brief 
 * 
 * \param uint8_t 
 * \param * function
 * \param void 
 * 
 * \return uint8_t
 */
uint8_t usart_callback_function(uint8_t(*function)(void) ){
	
	
	
	return (*function)();
	

}


/**
 * \brief 
 * 
 * \param uint8_t channel
 * \param uint8_t 
 * \param * function
 * \param void 
 * 
 * \return uint8_t
 */
uint8_t usart_callback_add_register(uint8_t channel, uint8_t(*function)(void) ){
	
	
		switch(channel){
			
			
			case 0: //usart0
			
				function_register[0] =  (function);
				
				break;
			
			
			case 1://usart1
			
				function_register[1] =  (function);
				
				break;
				
				
			case 2://usart2
			
				function_register[2] =  (function);
			
				break;
				
				
			case 3://usart3
			
				function_register[3] =  (function);
				
				break;
				
				
			default:
			
			
				break;
		}
	
	
	return 1;	
}


/************************************************************************/
/*                   ROUTINE D'INTERUPTION USART                         */
/************************************************************************/
ISR(USART0_RX_vect){
	
	if(function_register[0] != NULL){
		
		usart_callback_function( function_register[0] );
	}
	else{
		
		usart_read_data(USART0);
		
	}
}

ISR(USART1_RX_vect){
		
	
	if(function_register[1] != NULL){
		
		usart_callback_function( function_register[1] );
	}
	
	else{
		
		usart_read_data(USART1);
		
	}
			
}

/*
ISR(USART2_RX_vect){
	
	
	if(function_register[2] != NULL){
		
		usart_callback_function( function_register[2] );
	}
	else{
		
		usart_read_data(USART2);
		
	}	
}
*/

/*
ISR(USART3_RX_vect){
	
	
	if(function_register[3] != NULL){
		
		usart_callback_function( function_register[3] );
	}
	else{
		
		usart_read_data(USART3);
		
	}	
}
*/