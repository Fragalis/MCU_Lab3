/*
 * timer.h
 *
 *  Created on: Nov 10, 2023
 *      Author: ACER
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "main.h"
#include "global.h"
#include "input_reading.h"

extern int timerLED_flag;
extern int timer7SEG_flag;

void set_timerLED(int duration);
void set_timer7SEG(int duration);
void timer_run(void);

#endif /* INC_TIMER_H_ */
