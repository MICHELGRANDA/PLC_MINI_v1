 
#ifndef BOARD_H_
#define BOARD_H_



/******************************************************************************/
//						DEFINITION DES MACROS
/*******************************************************************************/

#if defined (PLC_MINI_V1)

	
	#include "plc/Board/Freq.h"
	#include "plc/board/McuDriver/m328pb/include/Driver_m328pb.h"
	#include "plc/Board/ChipDriver/include/chip_driver.h"


#elif defined (PLC_MINI_V2)

	//#include "PLC_MINI_V2.h"

#else

	#error " *** CARTE ELECTRONIQUE INCONNU *** "
	#warning " Vous devez choisir la carte a programmer en selectionnant un dans la liste"

#endif
					  




/******************************************************************************/
//						INCLUSIONS DES FICHIERS ENTETE
/*******************************************************************************/



/******************************************************************************/
//						DECLARATIONS DES VARIABLES		
/*******************************************************************************/



/******************************************************************************/
//						DECLARATIONS DES PROTOTYPES		
/*******************************************************************************/







#endif /* BOARD_H_ */