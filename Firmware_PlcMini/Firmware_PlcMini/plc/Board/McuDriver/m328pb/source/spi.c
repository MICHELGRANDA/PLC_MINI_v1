/*
 * SPI.c
 *
 * Created: 02/10/2020 13:26:15
 *  Author: Michel
 */ 

#include "plc/Board/McuDriver/m328pb/include/spi.h"


uint8_t spi_execute_configuration(spi_configuration *spi){
	
	DDRB |=   (1 << PB2) | (1 << PB1) | (1 << PB0);
	
	SPCR0 = 0x00;
	
	if(spi->mode == spi_master){ // en mode maitre
	
		DDRB |=  (1 << PB3); // ss en sortie
		
		SPCR0 |= (1 << MSTR); // bit de maitre
		
	}
	else{ // en mode esclave
		
		 DDRB &=  ~(1 << PB3); // ss en entree
		 SPCR0 &=  ~(1 << MSTR); // bit d'esclave
		 
	}
	
	
	
	if (spi->transfer_direction == spi_lsb){
		
		SPCR0 |= (1 << DORD); // bit de LSB
		
	} 
	else{
		
		 SPCR0 &=  ~(1 << DORD); // bit de MSB
		
	}
	
	
	SPCR0 |= (0x03 & spi->speed);
	SPSR0 |= (spi->speed >> 0x02);
	
	SPCR0 |= (1 << SPE);
	
	return 1;
}



uint8_t spi_write_byte(uint8_t _data){

uint8_t recv = 0;
	
	SPDR0 = _data;
	
	while( !(SPSR0 & (1 << SPIF) ) );
	
	recv = SPDR0;
	
	return recv;
}



uint8_t spi_write_tampon(uint8_t *tab, uint16_t len){
	
	uint16_t i = 0;
	
	for(i=0; i<len; i++){
		
		tab[i] = spi_write_byte(tab[i]);
	}
	
	
	return 1;
	
}
