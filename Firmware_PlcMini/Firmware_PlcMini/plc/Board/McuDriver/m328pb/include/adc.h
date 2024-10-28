


//*********************************************************************
//							    INCLUDE
//*********************************************************************

#include "port.h"
#include "common.h"



//*********************************************************************
//								DEFINITION
//*********************************************************************

#define		vref_AREF			0x00
#define		vref_AVCC			0x01
#define		vref_1v1			0x03



//*********************************************************************
//								DECLARATION DES PROTOTYPES
//*********************************************************************

#ifndef ADC_H_
#define ADC_H_
 
#ifdef __cplusplus

extern "C"
{
	
#endif


uint8_t adc_execute_configuration(void);

uint16_t adc_read_value(uint8_t channel);

uint8_t adc_read_all_voltage(float *tab, uint8_t nombre_voie);

float adc_read_voltage(uint8_t channel);


#ifdef __cplusplus

} //extern "C"

#endif




#endif /* ADC_H_ */