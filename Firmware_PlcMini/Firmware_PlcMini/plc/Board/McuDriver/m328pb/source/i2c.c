/*
 * hal_i2c.c
 *
 * Created: 06/08/2020 11:12:14
 *  Author: MICHEL GRANDA
 */ 

#include "plc/Board/McuDriver/m328pb/include/i2c.h"



void i2c_execute_configuration(uint32_t _freq){
	
	reset_bit(TWSR0,TWPS0);
	reset_bit(TWSR0,TWPS1);
	
	TWBR0 = (uint8_t)((( F_CPU / _freq) - 16) / 2);
	
	TWCR0 = (1 << TWEN) | (1 << TWIE) | (1 << TWEA); 
	
}

void I2C_Start(void){
	
	TWCR0 = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);  //Send START condition
	while ( !(TWCR0 & (1<<TWINT)) ); // Wait for TWINT flag set. This indicates that the START condition has been transmitted
	
}

void I2C_Repeated_Start(void){
	
	I2C_Start();
	
}

void I2C_Write(uint8_t data){
	
	TWDR0 = data;
	TWCR0 = (1<<TWINT) | (1<<TWEN); //Load SLA_W into TWDR register. Clear TWINT bit in TWCR to start transmission of address
	while ( !(TWCR0 & (1<<TWINT)) ); //Wait for TWINT flag set. This indicates that the SLA+W has been transmitted, and ACK/NACK has been received.
}

uint8_t I2C_Read(uint8_t reponse){
	
	
	if(reponse == 0){
		
		// start receiving without acknowledging reception
		TWCR0 = (1<<TWINT) | (1<<TWEN);
	}
	else{
		
			// start TWI module and acknowledge data after reception
			TWCR0 = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	}
	
		while( !(TWCR0 & (1<<TWINT)) ); // wait for end of transmission
	
		return TWDR0; // return received data from TWDR
		
}

void I2C_Stop(void){
	
	TWCR0 = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO); //Transmit STOP condition
	while ( (TWCR0 & (1<<TWSTO)) ); //on attend que la condition stop soit executé
	
}

uint8_t I2C_check_device(uint8_t adress){
	

	
	I2C_Start();
	I2C_Write(adress);
	I2C_Stop();
	
	
	
	switch(TWSR0){
		
		case TW_MT_SLA_ACK:
		
			return 1;
			
			break;
			
		case TW_MT_SLA_NACK:
		
			return 0;
		
			break;

		case TW_MR_SLA_ACK:
		
			return 1;
		
			break;
		
		case TW_MR_SLA_NACK:
		
			return 0;
			
			break;			
			
		default:
		
			return 0;
		
			break;
	}
}