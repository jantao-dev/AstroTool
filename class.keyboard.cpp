/*
 * class.keyboard.cpp
 * Keyboard class source file
 *
 * Project: AstroTool
 * Created on: 28.07.2016
 * Author: SergSXM (sergsxm@embedded.by)
 */

#include "class.keyboard.h"


Keyboard::Keyboard(Interval * interval) {
	this->interval = interval;
	bounceCounter = 0;
	bounceOldButton = 0;
	currentButton = 0;
	pressStartMs = 0;
	longPressFlag = 0;
	DDRC &= ~(1 << 5);
	PORTC |= (1 << 5);
	DDRD &= ~(1 << 7);
	PORTD |= (1 << 7);
}

uint8_t Keyboard::GetDebouncedButton(void) {
	uint8_t btn = 0;
	if (!(PINC & (1 << 5))) {
		btn |= 1;
	}
	if (!(PIND & (1 << 7))) {
		btn |= 2;
	}
	if (btn != bounceOldButton) {
		if (bounceCounter < KEYBOARD_BOUNCE_FILTER) {
			bounceCounter++;
			return bounceOldButton;
		}
		bounceOldButton = btn;
	}
	bounceCounter = 0;
	return btn;
}

uint8_t Keyboard::GetEvent(void) {
	uint8_t btn, event;
	btn = GetDebouncedButton();

	if ((currentButton == 0) && (btn != 0)) {
		longPressFlag = 0;
		pressStartMs = interval->getMsCounter();
		event = KEYBOARD_DOWN_FLAG | btn;
	} else if ((currentButton != 0) && (btn == 0)) {
		event = KEYBOARD_UP_FLAG | currentButton;
		if (longPressFlag == 0) {
			event |= KEYBOARD_SHORT_FLAG;
		}
	} else if ((btn != 0) && (longPressFlag == 0) && ((interval->getMsCounter() - pressStartMs) > KEYBOARD_LONG_TIME)) {
		longPressFlag = 1;
		event = KEYBOARD_LONG_FLAG | btn;
	} else {
		event = btn;
	}
	currentButton = btn;
	return event;
}

