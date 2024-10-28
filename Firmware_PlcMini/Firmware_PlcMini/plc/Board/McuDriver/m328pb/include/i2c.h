/*
 * hal_i2c.h
 *
 * Created: 06/08/2020 10:46:32
 *  Author: MICHEL GRANDA
 */ 


#ifndef I2C_H_
#define I2C_H_
//*********************************************************************
//							    INCLUDE
//*********************************************************************
#include "port.h"
#include "common.h"




//*********************************************************************
//								DEFINITION
//*********************************************************************

#define ACK		0x18
#define NACK	0x20


//*********************************************************************
//								DECLARATION DES PROTOTYPES
//*********************************************************************
#ifdef __cplusplus

extern "C"
{
	
#endif


void i2c_execute_configuration(uint32_t _freq);

void I2C_Start(void);

void I2C_Repeated_Start(void);

void I2C_Write(uint8_t data);

uint8_t I2C_Read(uint8_t reponse);

uint8_t I2C_check_device(uint8_t adress);

void I2C_Stop(void);



#ifdef __cplusplus

} //extern "C"

#endif


#endif /* I2C_H_ */