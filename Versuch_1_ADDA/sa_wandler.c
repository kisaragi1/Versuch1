/*
 * sa_wandler.c
 *
 * Created: 27.10.2025 14:40:01
 *  Author: VALIK
 */ 

#include <util/delay.h>
#include <avr/io.h>
#include "os_input.h"


void init_twports(void) {
	DDRA = 0xFF;
	PORTA = 0x00;
	
	DDRB = 0xFF;
	PORTB = 0x00;
	
	DDRC &= ~(1<<1);
	PORTC |= (1<<1);
}

void tracking_wandler(void) {
	uint8_t result = 0; 
	uint8_t komparator;
	
	while(1) {
		PORTB = result;
		PORTA = result;
		_delay_ms(50);
		
		komparator = PINC & (1 << 0);
		if(komparator == 0) {
			if(result < 255) {
				result++;
			}
		} else {
			if (result > 0) {
				result--;
			}
		}
	}
}


void sa_wandler(void) {
	uint8_t result=0;
	uint8_t komparator;
	for (int8_t i=7; i >= 0; i--) {
		uint8_t bit_mask = (1 << i);
		
		result |= bit_mask;
		PORTA = result;
		PORTB = result;
		_delay_ms(50);
		
		//COMP_OUT ablesen
		komparator = PINC & (1 << 0);
		
		// Falls COMP_OUT != 0, ersetze den bit durch 0
		if(komparator!=0) {
			result &= ~bit_mask;
			PORTA = result;
			PORTB = result;
			_delay_ms(10);
		} 
		PORTA = result;
		PORTB = result;
	}
}