/*
 * SEVEN_SEG.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: El-safi
 */

#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_
#include <avr/io.h>

#define ONES_SEG_ON     PORTC|=(1<<PC4)
#define ONES_SEG_OFF    PORTC&=~(1<<PC4)
#define TENS_SEG_ON     PORTC|=(1<<PC5)
#define TENS_SEG_OFF    PORTC&=~(1<<PC5)
#define HUND_SEG_ON     PORTC|=(1<<PC3)
#define HUND_SEG_OFF    PORTC&=~(1<<PC3)
#define THUS_SEG_ON      PORTC|=(1<<PC2)
#define THUS_SEG_OFF     PORTC&=~(1<<PC2)
#define DISPLAY_DATA             PORTB
unsigned char second=0,minutes=8,hours=5;

void segment_init()
{
   /******* data lines ******/

	DDRB|=(1<<PB0)|(1<<PB1)|(1<<PB2)|(1<<PB3);
	DDRC|=(1<<PC2)|(1<<PC3)|(1<<PC4)|(1<<PC5);

}

void MINUTES(unsigned char min)
{
   unsigned char ones=0,tens=0;
   HUND_SEG_OFF;
   THUS_SEG_OFF;
   ONES_SEG_OFF;

   TENS_SEG_ON;
   tens=min/10;
   DISPLAY_DATA=tens;
   _delay_ms(1);

   TENS_SEG_OFF;
   ONES_SEG_ON;
   ones=min%10;
   DISPLAY_DATA=ones;
   _delay_ms(1);




}

void HOURS(unsigned char hour)
{
	   unsigned char hund=0,thus=0;
	   ONES_SEG_OFF;
	   TENS_SEG_OFF;
	   HUND_SEG_OFF;

	   THUS_SEG_ON;
	   thus=hour/10;
	   DISPLAY_DATA=thus;
	   _delay_ms(1);

	   THUS_SEG_OFF;
	   HUND_SEG_ON;
	   hund=hour%10;
	   DISPLAY_DATA=hund;

	   _delay_ms(1);


}


#endif /* SEVEN_SEG_H_ */
