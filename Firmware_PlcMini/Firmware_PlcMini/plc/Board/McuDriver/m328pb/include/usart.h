/********************************************************************
	created:	2023/04/09
	filename: 	USART.h
	author:		MICHELGRANDA
	email:		michelgranda97@gmail.com
	tel:		+237 697 54 49 91
	
	purpose:	
*********************************************************************/

#ifndef USART_H_
#define USART_H_

//*********************************************************************
//							    INCLUDE
//*********************************************************************

#include "port.h"
#include "common.h"




//*********************************************************************
//								DEFINITION
//*********************************************************************

#define USART0		&UCSR0A
#define USART1		&UCSR1A


enum{
	none,
	reserved,
	even,
	odd
};


enum{
	
	frame_5bit,
	frame_6bit,
	frame_7bit,
	frame_8bit,
	frame_9bit=7
};

enum{
	
	stop_1bit,
	stop_2bit
};
	
typedef struct{

	uint32_t baudrate;
	uint8_t data_bit_frame;
	uint8_t stop_bit;
	uint8_t parity;
	uint8_t receive_interruption;

}usart_configuration;




//*********************************************************************
//								DECLARATION DES PROTOTYPES
//*********************************************************************

#ifdef __cplusplus

extern "C"
{
	
#endif


uint8_t usart_execute_configuration(volatile uint8_t *channel, usart_configuration *_usart);

uint8_t usart_write_data(volatile uint8_t *channel, uint8_t data);  

uint8_t usart_read_data(volatile uint8_t *channel);

uint8_t usart_write_text(volatile uint8_t *channel, uint8_t *data, uint32_t len);

uint8_t usart_data_ready(volatile uint8_t *channel);

uint8_t usart_callback_function( function_var function );

uint8_t usart_callback_add_register(uint8_t channel,function_var  function );


#ifdef __cplusplus

} //extern "C"

#endif



#endif /* USART_H_ */