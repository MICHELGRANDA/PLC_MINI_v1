
/********************************************************************
	created:	2023/04/09
	file base:	common
	author:		MICHELGRANDA
	tel:		+237 697 54 49 91
	email:		michelgranda97@gmail.com
	
	purpose:	

*/

#ifndef COMMON_H_
#define COMMON_H_



/******************************************************************************/
//						DEFINITION DES PREPROCESSEUR
/*******************************************************************************/

#define Input		(0x00)
#define Output		(0x01)

#define Low			(0x00)
#define High		(0x01)

#define Toggle		(0x02)
#define On			(0x01)
#define Off			(0x00)

#define Enable		(0x01)
#define Disable		(0x00)	


enum{
		pin0,
		pin1,
		pin2,
		pin3,
		pin4,
		pin5,
		pin6,
		pin7,
		pin8,
		pin9,
		pin10,
		pin11,
		pin12,
		pin13,
		pin14,
		pin15,
		ALL=0xFF
};


//************************** bit operation **************************************

#define write_bit(reg, bit, _state)		( (_state) == High ? set_bit((reg),(bit)) :  ( (_state) == Toggle ? toggle_bit((reg),(bit)) : reset_bit((reg),(bit)))  )

#define set_bit(reg, bit)				( (reg) |= 1 << (bit) )

#define reset_bit(reg, bit)				( (reg) &= ~(1 << (bit) ) )

#define toggle_bit(reg, bit)			( (reg) ^= 1 << (bit) )

#define read_bit(reg, bit)				( ( (reg) & (1 << (bit)) ) >> (bit) )

#define write_register(reg, _data)		( (reg) = (_data) )

#define read_register( reg )			( (reg) )

#define MSB_BYTE(reg)					((reg) >> (0x04))

#define LSB_BYTE(reg)					((reg) & (0x0F))

#define MSB_WORD(reg)					((reg) >> (0x0008))

#define LSB_WORD(reg)					((reg) & (0x00FF))

#define MSB_DWORD(reg)					((reg) >> 16)
#define LSB_DWORD(reg)					((reg) & (0x0000FFFF))


/******************************************************************************/
//						INCLUSIONS DES FICHIERS ENTETE
/*******************************************************************************/

 #include "plc/Board/Freq.h"
 #include <avr/io.h>
 #include <avr/interrupt.h>
 #include <avr/wdt.h>
 #include <util/delay.h>
 #include <util/twi.h>
 #include <stdint.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

/******************************************************************************/
//						DECLARATIONS DES VARIABLES		
/*******************************************************************************/

 typedef uint8_t(*function_var)(void);


/******************************************************************************/
//						DECLARATIONS DES PROTOTYPES		
/*******************************************************************************/










#endif /* COMMON_H_ */