/*
 * timer.c
 *
 *  Created on: Nov 2, 2023
 *      Author: ACER
 */

#include "main.h"
#include "input_reading.h"

void HAL_TIM_PeriodElapsedCallBack(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM2) {
		button_reading();
	}
}
