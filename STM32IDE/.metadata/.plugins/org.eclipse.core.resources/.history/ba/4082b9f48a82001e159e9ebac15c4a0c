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

void update_7SEG(unsigned char index)
{
	switch (index)
	{
	case 0:
		HAL_GPIO_WritePin(GPIOA, EN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, EN3_Pin, GPIO_PIN_SET);
		display_7SEG(LED_Buffer[index]);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOA, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, EN1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, EN3_Pin, GPIO_PIN_SET);
		display_7SEG(LED_Buffer[index]);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOA, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, EN2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, EN3_Pin, GPIO_PIN_SET);
		display_7SEG(LED_Buffer[index]);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOA, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, EN3_Pin, GPIO_PIN_RESET);
		display_7SEG(LED_Buffer[index]);
		break;
	default:
		HAL_GPIO_WritePin(GPIOA, EN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, EN1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, EN2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, EN3_Pin, GPIO_PIN_RESET);
		display_7SEG(8);
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

void scan_7SEG(void) {
	if(timer7SEG_flag == 1) {
		update_7SEG(index_led++);
		index_led = index_led % NO_OF_LEDS;
	}
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

void display_traffic_LEDS(void)
{
	switch(trafficLightState)
	{
	case INIT:
		counterRED = durationRED;
		counterYELLOW = durationYELLOW;
		counterGREEN = durationGREEN;
		trafficLightState = RED_GREEN;
		if(counterRED != (counterYELLOW + counterGREEN)) {
			trafficLightState = ERROR_STATE;
		}
		break;
	case RED_GREEN:
		HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_2_Pin, GPIO_PIN_RESET);

		update_buffer(timerLED_flag, 0);
		update_7SEG(1);
		if(timerLED_flag > 0) {
			counterRED--;
			counterGREEN--;
			update_buffer(counterRED, counterGREEN);
			//set_timerLED(1000);
		}

		if(counterGREEN <= 0) {
			counterGREEN = durationGREEN;
			trafficLightState = RED_YELLOW;
		}
		break;
	case RED_YELLOW:
		HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_2_Pin, GPIO_PIN_SET);

		if(timerLED_flag > 0) {
			counterRED--;
			counterYELLOW--;
			update_buffer(counterRED, counterYELLOW);
			set_timerLED(1000);
		}

		if(counterYELLOW <= 0) {
			counterRED = durationRED;
			counterYELLOW = durationYELLOW;
			trafficLightState = GREEN_RED;
		}
		break;
	case GREEN_RED:
		HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin, GPIO_PIN_RESET);

		HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_2_Pin, GPIO_PIN_SET);

		if(timerLED_flag > 0) {
			counterGREEN--;
			counterRED--;
			update_buffer(counterGREEN, counterRED);
			set_timerLED(1000);
		}

		if(counterGREEN <= 0) {
			counterGREEN = durationGREEN;
			trafficLightState = YELLOW_RED;
		}
		break;
	case YELLOW_RED:
		HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_2_Pin, GPIO_PIN_SET);

		if(timerLED_flag > 0) {
			counterYELLOW--;
			counterRED--;
			update_buffer(counterYELLOW, counterRED);
			set_timerLED(1000);
		}

		if(counterYELLOW <= 0) {
			counterYELLOW = durationYELLOW;
			counterRED = durationRED;
			trafficLightState = RED_GREEN;
		}
		break;
	case ERROR_STATE:
		//blinking_LED_RED();
		//blinking_LED_YELLOW();
		//blinking_LED_GREEN();
		update_buffer(88, 88);
		break;
	default:
		break;
	}
}

