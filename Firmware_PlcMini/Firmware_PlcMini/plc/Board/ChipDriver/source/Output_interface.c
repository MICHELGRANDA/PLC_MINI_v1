/********************************************************************
	created:	2023/04/10
	filename: 	OUTPUT_INTERFACE.c
	author:		MICHELGRANDA
	email:		michelgranda97@gmail.com
	tel:		+237 697 54 49 91
	
	purpose:	
*********************************************************************/

 #include "plc/Board/ChipDriver/include/output_interface.h"

void Output_interface_init(void){

	gpio_configuration gpio[_NUMBER_OUTPUT];
	uint8_t i=0;

	gpio[0].gpio = GPIOB;
	gpio[0].pin  = pin0;
	gpio[0].direction = Output;
	gpio[0].pull_up =  Off;
	gpio[0].default_state = Low;

	gpio[1].gpio = GPIOB;
	gpio[1].pin  = pin1;
	gpio[1].direction = Output;
	gpio[1].pull_up =  Off;
	gpio[1].default_state = Low;

	gpio[2].gpio =	GPIOB;
	gpio[2].pin  =	pin2;
	gpio[2].direction =	 Output;
	gpio[2].pull_up = Off;
	gpio[2].default_state = Low;

	gpio[3].gpio = GPIOC;
	gpio[3].pin  = pin0;
	gpio[3].direction = Output;
	gpio[3].pull_up = Off;
	gpio[3].default_state = Low;



	
	for (i=0; i<_NUMBER_OUTPUT; i++){

		gpio_execute_configuration(&gpio[i]);
	}


}



uint8_t Output_interface_write(uint8_t channel,uint8_t _state){

	switch (channel)
	{
		case _OUT1:

			return gpio_write_pin(GPIOB,pin0,_state);

		break;

		case _OUT2:

			return gpio_write_pin(GPIOB,pin1,_state);

		break;

		case _OUT3:

			return gpio_write_pin(GPIOB,pin2,_state);

		break;

		case _OUT4:

			return gpio_write_pin(GPIOC,pin0,_state);

		break;

		
		default:

			return 0;

		break;
	}


	return 0;
}