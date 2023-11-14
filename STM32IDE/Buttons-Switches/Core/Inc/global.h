/*
 * global.h
 *
 *  Created on: Nov 10, 2023
 *      Author: ACER
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"

/* DEFINE SECTION */
// TIMER
#define TIMER_CYCLE						10
#define BLINKY_CYCLE					500

// INPUT
#define NO_OF_BUTTONS 					3
#define DURATION_FOR_HOLD				100
#define BUTTON_IS_PRESSED				GPIO_PIN_RESET
#define BUTTON_IS_RELEASED				GPIO_PIN_SET

// OUTPUT
#define NO_OF_LEDS						4

/* VARIABLE SECTION */

#endif /* INC_GLOBAL_H_ */
