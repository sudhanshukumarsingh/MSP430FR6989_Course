#include <msp430.h>             // Allows us to use short-cut names to make our code easier to read

#define RED 0x0001              // Specifies the red light for us
#define RED_OFF 0x00FE          // Use to turn the red LED off
#define ENABLE_RED 0xFFFE       // Use to enable microcontroller's pins
#define DEVELOPMENT 0x5A80      // Use to disable some of the security features while we are still learning

/*
 * main.c
 */
int main(void) {
    WDTCTL  = DEVELOPMENT;	    // Disable some security features
	PM5CTL0 = ENABLE_RED;       // Enable the pins to the outside world
	P1DIR   = RED;              // Make a pin an output
	long x = 0;                 // Will be used to slow down blinking
	
	while(1)                    // Continuously repeat everything below
	{
		for(x=0;x<10000;x=x+1); // Count from 0 to 30,000 for a delay
		P1OUT = RED;            // Turn RED Light on
		for(x=0;x<10000;x=x+1); // Count from 0 to 30,000 for a delay
		P1OUT = RED_OFF;        // Turn RED Light OFF
	}
}
