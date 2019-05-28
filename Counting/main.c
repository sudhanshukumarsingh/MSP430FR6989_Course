#include <msp430.h> 
#define DEVELOPMENT 0x5A80

/*
 * main.c
 */
int main(void) {
    WDTCTL = DEVELOPMENT;	// Stop watchdog timer
	long count = 0;
	while(count<20)
	{
		count = count + 1;
	}
	while(1);
}
