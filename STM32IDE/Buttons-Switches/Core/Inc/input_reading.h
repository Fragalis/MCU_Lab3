/*
 * input_reading.h
 *
 *  Created on: Nov 10, 2023
 *      Author: ACER
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#include "main.h"
#include "global.h"

void button_reading(void);
unsigned char is_button_pressed(unsigned char index);
unsigned char is_button_hold(unsigned char index);
unsigned char is_button_released(unsigned char index);

#endif /* INC_INPUT_READING_H_ */
