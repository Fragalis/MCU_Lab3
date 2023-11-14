/*
 * fsm_display.c
 *
 *  Created on: Nov 10, 2023
 *      Author: ACER
 */

#include "fsm_display.h"

enum DisplayState {
	INIT,
	NORMAL_STATE,
	BLINKY_RED,
	BLINKY_YELLOW,
	BLINKY_GREEN
};

enum DisplayState displayState = INIT;

int editedRED;
int editedYELLOW;
int editedGREEN;

void fsm_display_run(void) {
	switch(displayState) {
		case INIT:
			editedRED = durationRED;
			editedYELLOW = durationYELLOW;
			editedGREEN = durationGREEN;
			displayState = NORMAL_STATE;
			break;
		case NORMAL_STATE:
			//TODO: Implement Normal State
			display_traffic_LEDS();
			if(is_button_pressed(0)) {
				displayState = BLINKY_RED;
			}
			break;
		case BLINKY_RED:
			//TODO: Implement RED State
			if(is_button_pressed(1)) {
				editedRED++;
				editedRED = editedRED % 100;
			}
			if(is_button_pressed(2)) {
				durationRED = editedRED;
			}
			if(is_button_pressed(0)) {
				displayState = BLINKY_YELLOW;
			}
			break;
		case BLINKY_YELLOW:
			//TODO: Implement YELLOW State
			if(is_button_pressed(1)) {
				editedYELLOW++;
				editedYELLOW = editedYELLOW % 100;
			}
			if(is_button_pressed(2)) {
				durationYELLOW = editedYELLOW;
			}
			if(is_button_pressed(0)) {
				displayState = BLINKY_GREEN;
			}
			break;
		case BLINKY_GREEN:
			//TODO: Implement GREEN State
			if(is_button_pressed(1)) {
				editedGREEN++;
				editedGREEN = editedGREEN % 100;
			}
			if(is_button_pressed(2)) {
				durationGREEN = editedGREEN;
			}
			if(is_button_pressed(0)) {
				displayState = INIT;
			}
			break;
		default:
			break;
	}
}
