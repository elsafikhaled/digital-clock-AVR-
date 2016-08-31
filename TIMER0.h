/*
 * TIMER0.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: El-safi
 */

#ifndef TIMER0_H_
#define TIMER0_H_
#include <avr/io.h>
#include <avr/interrupt.h>
volatile unsigned over_flow=0;

ISR(TIMER0_OVF_vect)
{
	over_flow++;
	if(over_flow>=31)
			{
				second++;
				over_flow=0;
				TCNT0=0;
				if(second==60)
				{
					minutes++;
					second=0;
					if(minutes==60)
					{
						hours++;
						minutes=0;
						if(hours==12)hours=0;
					}
				}


			}


}

void TIMER0_init()
{

 TCCR0|=(1<<CS00)|(1<<CS02);
 TCNT0=0;
 TIMSK|=(1<<TOIE0);
 sei();


}


#endif /* TIMER0_H_ */
