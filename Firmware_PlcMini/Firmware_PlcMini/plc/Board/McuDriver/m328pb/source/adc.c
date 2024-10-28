/*
 * ADC.c
 *
 * Created: 01/10/2020 19:20:30
 *  Author: Michel
 */ 

#include "plc/Board/McuDriver/m328pb/include/adc.h"

/**
 * \brief 
 * 
 * \param void 
 * 
 * \return uint8_t
 */
uint8_t adc_execute_configuration(void){
	
	reset_bit(DDRC,PC2); // on configure la broche PC2 en entree 
	reset_bit(DDRC,PC3); // on configure la broche PC3 en entree 
	
	ADMUX = (vref_AVCC << 6); // on selectionne la tension de reference
	
	ADCSRB = 0x00; //on met le convertisseur ADC en mode free running
	
	set_bit(DIDR0,PC2);    // on met la broche 2 du port C en mode analogique
	set_bit(DIDR0,PC3);    // on met la broche 3 du port C en mode analogique
	

	ADCSRA = 0x06; // on choisit un prescaler de div128
	
	return 1;
}


/**
 * \brief 
 * 
 * \param uint8_t channel
 * 
 * \return uint16_t
 */
uint16_t adc_read_value(uint8_t channel){
	
	uint16_t resultat = 0;
	
	ADMUX &= ~(0x1F);
	ADMUX |= channel; // on selectionne la voie de conversion
	
	ADCSRA |= (1 << ADEN) | (1 << ADSC); // on lance la conversion
	
	while( !(ADCSRA & (1 << ADIF)) );  //on attend que la conversion se termine
	
	resultat  = (uint16_t)(ADCL);
	resultat |= (uint16_t)(ADCH << 8);
	
	return resultat; // on retourne le resultat de la conversion
	
}


/**
 * \brief 
 * 
 * \param uint8_t channel
 * 
 * \return float
 */
float adc_read_voltage(uint8_t channel){
	
	float voltage = 0;
	
	voltage =  ( ( (float)(adc_read_value(channel) ) * 5.0) / (1024.0) );
	
	return voltage;
}


/**
 * \brief 
 * 
 * \param float * tab
 * \param uint8_t nombre_voie
 * 
 * \return uint8_t
 */
uint8_t adc_read_all_voltage(float *tab, uint8_t nombre_voie){
	
	uint8_t i = 0;
	
	for(i=0; i<nombre_voie; i++){
		
		tab[i] = adc_read_voltage(i);
	}
	
	return 1;
	
}