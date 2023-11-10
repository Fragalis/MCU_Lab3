/*
 * output_display.h
 *
 *  Created on: Nov 10, 2023
 *      Author: ACER
 */

#ifndef INC_OUTPUT_DISPLAY_H_
#define INC_OUTPUT_DISPLAY_H_

#include "main.h"
#include "global.h"

void display_7SEG(unsigned char num);
void update_7SEG(unsigned char index);
void blinking_LED_RED(void);
void blinking_LED_YELLOW(void);
void blinking_LED_GREEN(void);

#endif /* INC_OUTPUT_DISPLAY_H_ */
