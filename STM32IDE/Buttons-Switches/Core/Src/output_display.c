/*
 * output_display.c
 *
 *  Created on: Nov 10, 2023
 *      Author: ACER
 */

#include "output_display.h"

unsigned char LED_Buffer[NO_OF_LEDS];

void display_7SEG(unsigned char num) {
	switch (num) {
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

void update_7SEG(unsigned char index) {
	switch (index) {
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
		break;
	}
}

