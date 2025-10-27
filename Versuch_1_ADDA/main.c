#include <avr/io.h>
#include "r2r.h"
#include "os_input.h"
#include "sa_wandler.h"

void manuell (void);
void tracking(void);
int main(void) {
    manuell();
    }
	
	
void manuell(void) {
	init_r2rports();
	r2r();
	}
void tracking(void) {
	os_initInput();
	init_twports();
	while(1) {
		os_waitForInput();
		os_waitForNoInput();
		tracking_wandler();
	}
}
