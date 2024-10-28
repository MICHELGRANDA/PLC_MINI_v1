/*
 * ch340.h
 *
 * Created: 17/04/2023 20:54:57
 *  Author: user
 */ 

#include "plc/Board/McuDriver/m328pb/include/usart.h"

#ifndef CH340_H_
#define CH340_H_


void ch340_driver_init(void);

void ch340_write(uint8_t _data);

void ch340_write_text(uint8_t *tab, uint16_t len);

uint8_t ch340_read_byte(void);

uint8_t ch340_data_ready(void);






#endif /* CH340_H_ */