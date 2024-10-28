/**
	@file		SPI.h
	@brief		
	@author		MICHEL GRANDA
	@version	1.0
	@date		2020/10/01
				
	@commentaires
	
*/


#ifndef SPI_H_
#define SPI_H_

//*********************************************************************
//							    INCLUDE
//*********************************************************************
#include "port.h"
#include "common.h"



//*********************************************************************
//								DEFINITION
//*********************************************************************

#define spi_master		0x01
#define spi_slave		0x00

#define spi_lsb			0x01
#define spi_msb			0x00

enum{
	
	FOSC_DIV4,
	FOSC_DIV16,
	FOSC_DIV64,
	FOSC_DIV128,
	FOSC_DIV2,
	FOSC_DIV8,
	FOSC_DIV32,
};

typedef struct{
	
	uint8_t mode;
	uint8_t transfer_direction;
	uint8_t speed;
	
}spi_configuration;


//*********************************************************************
//								DECLARATION DES PROTOTYPES
//*********************************************************************



#ifdef __cplusplus

extern "C"
{
	
#endif

uint8_t spi_execute_configuration(spi_configuration *spi);

uint8_t spi_write_byte(uint8_t _data);

uint8_t spi_write_tampon(uint8_t *tab, uint16_t len);


#ifdef __cplusplus

} //extern "C"

#endif


#endif /* SPI_H_ */