/*
 * output_display.c
 *
 *  Created on: Nov 10, 2023
 *      Author: ACER
 */

#include "output_display.h"

unsigned char LED_Buffer[NO_OF_LEDS];
unsigned char index_led = 0;

int durationRED = 5;
int durationYELLOW = 3;
int durationGREEN = 2;

void display_7SEG(unsigned char num)
{
	switch (num)
	{
	case 0:
		HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin, GPIO_PIN_RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin|SEG6_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin|SEG2_Pin, GPIO_PIN_RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, SEG2_Pin|SEG5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG3_Pin|SEG4_Pin|SEG6_Pin, GPIO_PIN_RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOB, SEG4_Pin|SEG5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG6_Pin, GPIO_PIN_RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG3_Pin|SEG4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin|SEG2_Pin|SEG5_Pin|SEG6_Pin, GPIO_PIN_RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin|SEG4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG2_Pin|SEG3_Pin|SEG5_Pin|SEG6_Pin, GPIO_PIN_RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin|SEG6_Pin, GPIO_PIN_RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOB, SEG3_Pin|SEG4_Pin|SEG5_Pin|SEG6_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin, GPIO_PIN_RESET);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin|SEG6_Pin, GPIO_PIN_RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG5_Pin|SEG6_Pin, GPIO_PIN_RESET);
		break;
	default:
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin|SEG6_Pin, GPIO_PIN_SET);
		break;
	}
}

void update_7SEG(void)
{
	switch (index_led)
	{
	case 0:
		if(timer7SEG_flag > 0) {
			HAL_GPIO_WritePin(GPIOA, EN0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, EN2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, EN3_Pin, GPIO_PIN_SET);
			display_7SEG(LED_Buffer[index_led]);

			index_led = 1;
			set_timer7SEG(250);
		}
		break;
	case 1:
		if(timer7SEG_flag > 0) {
			HAL_GPIO_WritePin(GPIOA, EN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, EN2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, EN3_Pin, GPIO_PIN_SET);
			display_7SEG(LED_Buffer[index_led]);

			index_led = 2;
			set_timer7SEG(250);
		}
		break;
	case 2:
		if(timer7SEG_flag > 0) {
			HAL_GPIO_WritePin(GPIOA, EN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, EN2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, EN3_Pin, GPIO_PIN_SET);
			display_7SEG(LED_Buffer[index_led]);

			index_led = 3;
			set_timer7SEG(250);
		}
		break;
	case 3:
		if(timer7SEG_flag > 0) {
			HAL_GPIO_WritePin(GPIOA, EN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, EN2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, EN3_Pin, GPIO_PIN_RESET);
			display_7SEG(LED_Buffer[index_led]);

			index_led = 0;
			set_timer7SEG(250);
		}
		break;
	default:
		break;
	}
}
void update_buffer(unsigned char num1, unsigned char num2)
{
	LED_Buffer[0] = num1 / 10;
	LED_Buffer[1] = num1 % 10;
	LED_Buffer[2] = num2 / 10;
	LED_Buffer[3] = num2 % 10;
}

void blinking_LED_RED(void) {
	if(timerLED_flag > 0) {
		HAL_GPIO_TogglePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin);
		HAL_GPIO_TogglePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin);
		set_timerLED(BLINKY_CYCLE);
	}
}

void blinking_LED_YELLOW(void) {
	if(timerLED_flag > 0) {
		HAL_GPIO_TogglePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin);
		HAL_GPIO_TogglePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin);
		set_timerLED(BLINKY_CYCLE);
	}
}

void reset_LEDS(void) {
	HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED_GREEN_2_Pin, GPIO_PIN_SET);
}
