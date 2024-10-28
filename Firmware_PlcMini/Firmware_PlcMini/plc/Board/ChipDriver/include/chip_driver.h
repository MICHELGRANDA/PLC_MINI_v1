/*
 * chip_driver.h
 *
 * Created: 10/04/2023 02:27:31
 *  Author: user
 */ 


#ifndef CHIP_DRIVER_H_
#define CHIP_DRIVER_H_

#include "plc/Board/ChipDriver/include/input_interface.h"
#include "plc/Board/ChipDriver/include/output_interface.h"
#include "plc/board/ChipDriver/include/Analog_interface.h"
#include "plc/Board/ChipDriver/include/ch340.h"


void chip_driver_init(void);


#endif /* CHIP_DRIVER_H_ */