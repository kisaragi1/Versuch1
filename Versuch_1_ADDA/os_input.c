#include "os_input.h"

#include <avr/io.h>
#include <stdint.h>

/*! \file
 * Everything that is necessary to get the input from the Buttons in a clean format.
 */


/*!
 *  A simple "Getter"-Function for the Buttons on the evaluation board.\n
 *
 *  \returns The state of the button in the lower bits of the return value.\n
 *  example: Button C1: -pushed:   00000001
 *                      -released: 00000000
 */
// For AD/DA Wandlung check the first button 
uint8_t os_getInput(void) {
	return ((PINC >> 1 ) & 1);
}

/*!
 *  Initializes DDR and PORT for input
 */
 // For AD/DA DDR1 auf 0, PORT1 auf 1
void os_initInput() {
	DDRC &= ~(1<<0);
	PORTC |= (1<<0);
}

/*!
 *  Endless loop as long as at least one button is pressed.
 */
void os_waitForNoInput() {
	while(1) {
		if(os_getInput() == 1) {
			return;
		}
	}
}

/*!
 *  Endless loop until at least one button is pressed.
 */
void os_waitForInput() {
	while(1) {
		if(os_getInput() != 0) {
			return;
		}
	}
}
