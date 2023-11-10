/*
 * input_reading.c
 *
 *  Created on: Nov 10, 2023
 *      Author: ACER
 */

#include "input_reading.h"

// The buffer for the final result
static GPIO_PinState buttonBuffer[NO_OF_BUTTONS];

// The buffer for debouncing
static GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS];

// Flag for button hold in 1 second
static uint16_t flagForButtonHold[NO_OF_BUTTONS];

// Counter for button hold in 1 second
static uint16_t counterForButtonHold[NO_OF_BUTTONS];

void button_reading(void)
{
	for(unsigned char i = 0; i < NO_OF_BUTTONS; ++i)
	{
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
		if(debounceButtonBuffer1[i] == debounceButtonBuffer2[i])
		{
			buttonBuffer[i] = debounceButtonBuffer1[i];
			// Reset counter and flag for every button signal
			counterForButtonHold[i] = 0;
			flagForButtonHold[i] = 0;

			// If button is pressed, update the counter
			if(buttonBuffer[i] == BUTTON_IS_PRESSED)
			{
				counterForButtonHold[i]++;

				// If button is on hold for 1 second, update the flag
				if(counterForButtonHold[i] >= DURATION_FOR_HOLD) {
					flagForButtonHold[i] = 1;
					//TODO
				}
			}

		}
	}
}

unsigned char is_button_pressed(unsigned char index) {
	if((index < 0) || (index >= NO_OF_BUTTONS)) return 0xff;
	return (buttonBuffer[index] == BUTTON_IS_PRESSED);

}

unsigned char is_button_hold(unsigned char index) {
	if((index < 0) || (index >= NO_OF_BUTTONS)) return 0xff;
	return (flagForButtonHold[index] == 1);
}
