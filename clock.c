/*
 * clock.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: El-safi
 */
#include <avr/io.h>
#include <util/delay.h>
#include "SEVEN_SEG.h"
#include "TIMER0.h"





int main(void)
{
    TIMER0_init();
    segment_init();

	while (1)
	{

		MINUTES(minutes);
		HOURS(hours);
        PORTD|=(1<<PD5);

	}

	return 0;
}



