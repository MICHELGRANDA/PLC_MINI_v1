/*
 * ch340.c
 *
 * Created: 17/04/2023 21:34:49
 *  Author: user
 */ 

#include "plc/Board/ChipDriver/include/ch340.h"


void ch340_driver_init(void){
	
usart_configuration ch340_bit_setting;

ch340_bit_setting.baudrate = 9600;	
ch340_bit_setting.data_bit_frame = frame_8bit;
ch340_bit_setting.parity = 	none;
ch340_bit_setting.stop_bit = stop_2bit;
ch340_bit_setting.receive_interruption = Disable;
	
	usart_execute_configuration(USART0,&ch340_bit_setting);
}


void ch340_write(uint8_t _data){
	
	
	usart_write_data(USART0,_data);	
	
}



void ch340_write_text(uint8_t *tab, uint16_t len){
	
	
	 if(len){
		
		usart_write_text(USART0,tab,len); 
		 
	 }
	 else{
		 
		usart_write_text(USART0,tab,0); 
		 
	 }
	
	
	
}



uint8_t ch340_read_byte(void){
	
		
	return usart_read_data(USART0);
			
}


uint8_t ch340_data_ready(void){
	
	return usart_data_ready(USART0);
	
}
