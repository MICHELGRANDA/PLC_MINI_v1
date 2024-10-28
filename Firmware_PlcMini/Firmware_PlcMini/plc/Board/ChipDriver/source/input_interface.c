/*
 * input_interface.c
 *
 * Created: 10/04/2023 02:26:20
 *  Author: user
 */ 

#include "plc/Board/ChipDriver/include/input_interface.h"



 void Input_interface_init(void){

   gpio_configuration gpio[_NUMBER_INPUT];
   uint8_t i=0;

	gpio[0].gpio = GPIOD;
	gpio[0].pin  = pin2;
	gpio[0].direction = Input; 
	gpio[0].pull_up =  On;
	gpio[0].default_state = Low; 

	gpio[1].gpio = GPIOD;
	gpio[1].pin  = pin3;
	gpio[1].direction = Input;
	gpio[1].pull_up =  On;
	gpio[1].default_state = Low;

	gpio[2].gpio =	GPIOD;
	gpio[2].pin  =	pin4;
	gpio[2].direction =	 Input;
	gpio[2].pull_up = On;
	gpio[2].default_state = Low;

	gpio[3].gpio = GPIOE;
	gpio[3].pin  = pin1;
	gpio[3].direction = Input;
	gpio[3].pull_up = On;
	gpio[3].default_state = Low;

	gpio[4].gpio = GPIOE;
	gpio[4].pin  = pin0;
	gpio[4].direction =	Input;
	gpio[4].pull_up = On;
	gpio[4].default_state = Low;

	gpio[5].gpio = GPIOD;
	gpio[5].pin  =	pin7;
	gpio[5].direction =	Input;
	gpio[5].pull_up = On;
	gpio[5].default_state = Low;

   
	for (i=0; i<_NUMBER_INPUT; i++){

		 gpio_execute_configuration(&gpio[i]);
	}


}



 uint8_t Input_interface_read(uint8_t channel){

	switch (channel)
	{
		case _IN1:

				return gpio_read_pin(GPIOD,pin2);				

			break;

		case _IN2:

				return gpio_read_pin(GPIOD,pin3);

			break;	

		case _IN3:

				return gpio_read_pin(GPIOD,pin4);

			break;

		case _IN4:

				return gpio_read_pin(GPIOE,pin1);

			break;

		case _IN5:

				return gpio_read_pin(GPIOE,pin0);

			break;

		case _IN6:

				return gpio_read_pin(GPIOD,pin7);

			break;

		default:

			return 0;
		break;
	}


   return 0;
}