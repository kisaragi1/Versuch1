/*
 * sa_wandler.c
 *
 * Created: 27.10.2025 14:40:01
 *  Author: VALIK
 */ 

#include <util/delay.h>
#include <avr/io.h>
#include "os_input.h"


void init_saports(void) {
	DDRA = 0xFF;
	PORTA = 0x00;
	
	DDRB = 0xFF;
	PORTB = 0x00;
	
	DDRC &= ~(1<<1);
	PORTC |= (1<<1);
}

void tracking_wandler(void) {
	uint8_t r = 0; 
	uint8_t komparator;
	
	while(1) {
		PORTB = r;
		PORTA = r;
		_delay_ms(50);
		
		komparator = PINC & (1 << 1);
		if(komparator == 0) {
			if(r < 255) {
				r++;
			} else {
				if (r > 0) {
					r--;
				}
			}
		}
	}
}