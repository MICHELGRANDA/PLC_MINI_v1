/*
 * plc.h
 *
 * Created: 17/04/2023 22:46:08
 *  Author: user
 */ 


#ifndef PLC_H_
#define PLC_H_

#define PLC_MINI_V1

 #include "plc/Board/board.h"
 
 uint16_t  Output_data;
 uint16_t  Input_data;
 
/************************************************************************/
/*                   PREPROCESSEUR                                      */
/************************************************************************/
#define MAX_NUMBER_OUTPUT	0x06
#define MAX_NUMBER_INPUT	0x06

#define READ_ALL_INPUT
#define WRITE_ALL_OUTPUT

#define IN1						read_bit(Input_data,1)
#define IN2						read_bit(Input_data,2)
#define IN3						read_bit(Input_data,3)
#define IN4						read_bit(Input_data,4)
#define IN5						read_bit(Input_data,5)
#define IN6						read_bit(Input_data,6)

#define IN1_up					plc_read_rising_input(1)
#define IN2_up					plc_read_rising_input(2)
#define IN3_up					plc_read_rising_input(3)
#define IN4_up					plc_read_rising_input(4)
#define IN5_up					plc_read_rising_input(5)
#define IN6_up					plc_read_rising_input(6)


#define OUT1_Wr(_data)			write_bit(Output_data,0x01,_data)
#define OUT2_Wr(_data)			write_bit(Output_data,0x02,_data)
#define OUT3_Wr(_data)			write_bit(Output_data,0x03,_data)
#define OUT4_Wr(_data)			write_bit(Output_data,0x04,_data)
#define OUT5_Wr(_data)			write_bit(Output_data,0x05,_data)
#define OUT6_Wr(_data)			write_bit(Output_data,0x06,_data)

#define OUT1_Tog(_data)		    ( (Output_data) ^= ( (_data) << 1) ) 

#define OUT1_Rd     			read_bit(Output_data,0x01)
#define OUT2_Rd     			read_bit(Output_data,0x02)
#define OUT3_Rd     			read_bit(Output_data,0x03)
#define OUT4_Rd     			read_bit(Output_data,0x04)
#define OUT5_Rd     			read_bit(Output_data,0x05)
#define OUT6_Rd     			read_bit(Output_data,0x06)

#define and			&&
#define or			||
#define not			!
#define xor			^

 /************************************************************************/
 /*                                                                      */
 /************************************************************************/ 

   void plc_init(void);
   
   
   uint8_t plc_read_input(uint8_t channel);
   
   void plc_read_all_input(uint16_t *input_value);

   float plc_read_analog(uint8_t _channel);
  
   uint8_t plc_read_rising_input(uint8_t channel);
  
  
   
   void plc_write_output(uint8_t channel,uint8_t _state);
   
   void plc_write_all_output(uint16_t input_value);
 
 
 
   
   void plc_RS232_write_buffer(uint8_t *tab, uint16_t len);
   
   uint8_t plc_RS232_read_data(void);
   
   uint8_t plc_RS232_data_ready(void);
   
   
   

#endif /* PLC_H_ */