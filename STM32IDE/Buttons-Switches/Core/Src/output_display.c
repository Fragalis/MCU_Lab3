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

enum TrafficLightState {
	INIT,
	RED_GREEN,
	RED_YELLOW,
	GREEN_RED,
	YELLOW_RED,
	ERROR_STATE
};

enum TrafficLightState trafficLightState = INIT;

int counterRED = 0;
int counterYELLOW = 0;
int counterGREEN = 0;

void reset_state(unsigned char signal) {
	if(signal) trafficLightState = INIT;
}

void display_traffic_LEDS(void)
{
	switch(trafficLightState)
	{
	case INIT:
		counterRED = durationRED;
		counterYELLOW = durationYELLOW;
		counterGREEN = durationGREEN;
		trafficLightState = RED_GREEN;
		index_led = 0;
		if(counterRED != (counterYELLOW + counterGREEN)) {
			trafficLightState = ERROR_STATE;
		}
		break;
	case RED_GREEN:
		if(timerLED_flag > 0) {
			HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_2_Pin, GPIO_PIN_RESET);

			counterRED--;
			counterGREEN--;

			update_buffer(counterRED, counterGREEN);

			if(counterGREEN <= 0) {
				counterGREEN = durationGREEN;
				trafficLightState = RED_YELLOW;
			}
			set_timerLED(1000);
		}
		break;
	case RED_YELLOW:
		if(timerLED_flag > 0) {

			HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_2_Pin, GPIO_PIN_SET);

			counterRED--;
			counterYELLOW--;
			update_buffer(counterRED, counterYELLOW);

			if(counterYELLOW <= 0) {
				counterRED = durationRED;
				counterYELLOW = durationYELLOW;
				trafficLightState = GREEN_RED;
			}
			set_timerLED(1000);
		}
		break;
	case GREEN_RED:
		if(timerLED_flag > 0) {

			HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin, GPIO_PIN_RESET);

			HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_2_Pin, GPIO_PIN_SET);

			counterGREEN--;
			counterRED--;
			update_buffer(counterGREEN, counterRED);

			if(counterGREEN <= 0) {
				counterGREEN = durationGREEN;
				trafficLightState = YELLOW_RED;
			}
			set_timerLED(1000);
		}
		break;
	case YELLOW_RED:
		if(timerLED_flag > 0) {
			HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_2_Pin, GPIO_PIN_SET);

			counterYELLOW--;
			counterRED--;
			update_buffer(counterYELLOW, counterRED);

			if(counterYELLOW <= 0) {
				counterYELLOW = durationYELLOW;
				counterRED = durationRED;
				trafficLightState = RED_GREEN;
			}
			set_timerLED(1000);
		}
		break;
	case ERROR_STATE:
		if(timerLED_flag > 0) {
			HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin, GPIO_PIN_RESET);

			HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_2_Pin, GPIO_PIN_RESET);

			update_buffer(88, 88);
			set_timerLED(1000);
		}
		break;
	default:
		break;
	}
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

void blinking_LED_GREEN(void) {
	if(timerLED_flag > 0) {
		HAL_GPIO_TogglePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin);
		HAL_GPIO_TogglePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin);
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
