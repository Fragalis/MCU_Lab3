/*
 * timer.c
 *
 *  Created on: Nov 10, 2023
 *      Author: ACER
 */

#include "timer.h"

int timerLED_duration = 0;
int timer7SEG_duration = 0;
int timerLED_flag = 0;
int timer7SEG_flag = 0;

void set_timerLED(int duration) {
	timerLED_duration = duration;
	timerLED_flag = 0;
}

void set_timer7SEG(int duration) {
	timer7SEG_duration = duration;
	timer7SEG_flag = 0;
}

void timer_run() {
	if(timerLED_duration > 0) {
		--timerLED_duration;
		if(timerLED_duration <= 0) timerLED_flag = 1;
	}

	if(timer7SEG_duration > 0) {
		--timer7SEG_duration;
		if(timer7SEG_duration <= 0) timer7SEG_flag = 1;
	}
}

void HAL_TIM_PeriodElapsedCallBack(TIM_HandleTypeDef *htim) {
	if(htim->Instance == TIM2) {
		timer_run();
		//button_reading();
	}
}
