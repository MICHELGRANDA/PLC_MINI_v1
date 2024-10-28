/**
	@file		PORT.c
	@brief		
	@author		MICHEL GRANDA
	@version	
	@date		2020/09/27
				
	@commentaires
	
*/

#include "plc/Board/McuDriver/m328pb/include/port.h"




/**
 * \brief 
 * 
 * \param gpio_configuration * port
 * 
 * \return uint8_t
 */
uint8_t gpio_execute_configuration(gpio_configuration *port){
	
	switch(port->direction){
		
		case Input:
		
			if(port->pin != ALL){ 

				*((port->gpio) - 1)  &= ~( 1 << (port->pin) ); 
		
				if(port->pull_up == On){
							
					*(port->gpio) |= ( 1 << (port->pin) );
				}
				else{
							
					*(port->gpio) &= ~( 1 << (port->pin) );
				}
			}
			else{

				*((port->gpio) - 1) = 0x00;  // on configure toutes les pin en entree
				
				}
			return 1;

		break;
		
		
		case Output:
		
			if(port->pin != ALL){

					*((port->gpio) - 1)  |= ( 1 << (port->pin) );  // on configure la broche correspondante en sortie
			
			
					if(port->default_state == High){
				
						*(port->gpio) |= ( 1 << (port->pin) );
					}
					else{
				
						*(port->gpio) &= ~( 1 << (port->pin) ); 
					}
			}
			else{

					*((port->gpio) - 1) = 0xFF;  // on configure toutes les pin en sortie
			}

			return 1;
			
		break;
		
		default:
		
			return 0;
			
			break;
	}
	
	
	return 0;
}


/**
 * \brief 
 * 
 * \param volatile uint8_t * port
 * \param uint8_t pin
 * \param uint8_t state
 * 
 * \return uint8_t
 */
uint8_t gpio_write_pin(volatile uint8_t *port, uint8_t pin, uint8_t state){
	
	if(state == High){
		
		*port |= (1 << pin);
	}
	else if(state == Toggle){
		
		*port ^= (1 << pin);
	}
	else{
		
		*port &= ~(1 << pin);
	}
	
	return 1;
}

/**
 * \brief 
 * 
 * \param volatile uint8_t * port
 * \param uint8_t pin
 * 
 * \return uint8_t
 */
uint8_t gpio_read_pin(volatile uint8_t *port, uint8_t pin){
	
	uint8_t tampon = 0;
	
	tampon = ( *(port - 0x02) & (1 << pin) ) >> pin;
	
	//_delay_ms(3);
	
	return (uint8_t)tampon;
}



/**
 * \brief 
 * 
 * \param volatile uint8_t * port
 * \param uint8_t pin
 * 
 * \return uint8_t
 */
uint8_t gpio_toggle_pin(volatile uint8_t *port, uint8_t pin){
	
	(*port) ^= (1 << pin);
	
	return 1;
}


/**
 * \brief 
 * 
 * \param volatile uint8_t * port
 * \param uint8_t data
 * 
 * \return uint8_t
 */
uint8_t gpio_port_write(volatile uint8_t*port, uint8_t data){
	
	*port = data;
	
	return 1;
}


/**
 * \brief 
 * 
 * \param volatile uint8_t * port
 * 
 * \return uint8_t
 */
uint8_t gpio_port_read(volatile uint8_t *port){
	
	return *(port - 0x02);
	
}


