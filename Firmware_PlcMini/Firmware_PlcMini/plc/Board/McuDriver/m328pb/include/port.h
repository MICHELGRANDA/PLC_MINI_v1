/********************************************************************
	created:	2023/04/07
	file base:	Driver_m328pb
	author:		MICHELGRANDA
	tel:		+237 697 54 49 91
	email:		michelgranda97@gmail.com
	
	purpose:	


******************************************************************************/

#ifndef PORT_H_
#define PORT_H_


//*********************************************************************
//							    INCLUDE
//*********************************************************************


#include "common.h"



//*********************************************************************
//								DEFINITION
//*********************************************************************


#define GPIOB		&PORTB
#define GPIOC		&PORTC
#define GPIOD		&PORTD
#define GPIOE		&PORTE





//****************************************************************************************

typedef struct{
	
	volatile uint8_t *gpio;
	uint16_t pin;
	uint16_t direction:1;
	uint16_t default_state:1;
	uint16_t pull_up:1;

}gpio_configuration;


//*********************************************************************
//								DECLARATION DES PROTOTYPES
//*********************************************************************

#ifdef __cplusplus

extern "C"
{
	
#endif

uint8_t gpio_execute_configuration(gpio_configuration *port);

uint8_t gpio_write_pin(volatile uint8_t *port, uint8_t pin, uint8_t state);

uint8_t gpio_read_pin(volatile uint8_t *port, uint8_t pin);

uint8_t gpio_toggle_pin(volatile uint8_t *port, uint8_t pin);

uint8_t gpio_port_write(volatile uint8_t*port, uint8_t data);

uint8_t gpio_port_read(volatile uint8_t *port);


#ifdef __cplusplus

} //extern "C"
	
#endif

#endif /* PORT_H_ */