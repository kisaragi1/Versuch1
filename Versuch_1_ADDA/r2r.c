
#include "r2r.h"
#include <avr/io.h>


void init_r2rports(void) {
	//(DIP Schlalter) als Eingang. 
	DDRD = 0x00;
	PORTD = 0xFF;
	
	//(LEDS) als Ausgang 
	DDRA = 0xFF;
	PORTA = 0x00;
	//(R2R) als Ausgang
	DDRB = 0xFF;
	PORTB = 0X00;
}

void r2r(void) {
	uint8_t wert;
	
	while(1) {
		wert = PIND;
		PORTA = ~(wert);
		PORTB = ~(wert);
	}
}