/*
 * plc.c
 *
 * Created: 17/04/2023 23:02:36
 *  Author: user
 */ 

#include "plc.h"

void plc_init(void){
	 
	 Input_data = 0;
	 Output_data = 0;
	 chip_driver_init();
	 Driver_m328pb_init(); 
	   
	   
   }
   
uint8_t plc_read_input(uint8_t channel){
	
	uint8_t var =0;
	   
	  var = Input_interface_read(channel); 
	  
	   _delay_ms(3);  //anti rebond
	   
	   return var;
   }
   
   
    uint8_t plc_read_rising_input(uint8_t channel){
		
		uint8_t static old_status = 0;
		uint8_t new_status = 0;
		uint8_t data = 0;
		
		new_status = read_bit(Input_data,channel);
		
		if( (new_status == 1) and (old_status == 0) ){
			  
			  data = 1;				
		}

	    old_status = new_status;
		
		return data;	
	}
	
	
   
   void plc_read_all_input(uint16_t *input_value){
	   
	   	uint8_t index=0;
	   	
	   	for (index=1; index < MAX_NUMBER_INPUT+1; index++)
	   	{
		   	write_bit(input_value[0], index, Input_interface_read(index) );
	   	}
		   
	   	  _delay_ms(3);  //anti rebond
   }
   
   
float plc_read_analog(uint8_t _channel){
	   
	   switch(_channel){
		   
		   case  AI1:
		   
		   		 return Analog_interface_Read_voltage(PC2) * 4.0;
		   
		   break;
		   
		   case AI2:
		   
		   		 return Analog_interface_Read_voltage(PC3) * 4.0;
		   
		   break;
		   
		   
		   default:
		   
		   		 return 0.00;
		   break;
		   
	   }
	   
	   
   }
   
void plc_write_output(uint8_t channel, uint8_t _state){
	   
	   	 Output_interface_write(channel,_state);
	   
   }
   
void plc_write_all_output(uint16_t input_value){
		
		uint8_t index=0;
		
	   for (index=0; index < MAX_NUMBER_OUTPUT; index++)
	   {
		   	Output_interface_write(index, read_bit(input_value,index) );
	   }
}
   
void plc_RS232_write_buffer(uint8_t *tab,uint16_t len){
	
	  ch340_write_text(tab,len);
	
}
      
uint8_t plc_RS232_read_data(void){
	
	return ch340_read_byte();	
	
}

      
uint8_t plc_RS232_data_ready(void){
	
	
		if (ch340_data_ready())
		{
			return 1;
			
		}
	
		return 0;
}