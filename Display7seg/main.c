/*
 *
 * Created: 12/03/2019 16:35:41
 *  Author: Aluno
 */ 


#define F_CPU 16000000UL
#include "avr/io.h"
#include "util/delay.h"
#define SET_BIT(p,bit)  ((p)|=(1<<(bit)))
#define CLR_BIT(p,bit)  ((p)&=~(1<<(bit)))
#define TST_BIT(p,bit)  ((p)&(1<<(bit)))
#define CPL_BIT(p,bit)  ((p)^=(1<<(bit)))
int x = 0;

int main(void)
{
	DDRD  = 0xFF;
	PORTD = 0xFF;
	DDRC  = 0xFF;
	PORTC = 0xFF;
	DDRB  = 0x00;
	PORTB = 0xFF;
    while(1)
    {
			CLR_BIT(PORTC, 0);
			if (TST_BIT(PINB, PB0)==0){
			PORTD = 0x79;}
			if (TST_BIT(PINB, PB1)==0){
			PORTD = 0x24;}
			if (TST_BIT(PINB, PB2)==0){
			PORTD = 0x30;}
			SET_BIT(PORTC, 0);
			_delay_ms(50);
			CLR_BIT(PORTC, 1);
			if (TST_BIT(PINB, PB0)==0){
			PORTD = 0x19;}
			if (TST_BIT(PINB, PB1)==0){
			PORTD = 0x12;}
			if (TST_BIT(PINB, PB2)==0){
			PORTD = 0x02;}
			SET_BIT(PORTC, 1);
			_delay_ms(50);
			CLR_BIT(PORTC, 2);
			if (TST_BIT(PINB, PB0)==0){
			PORTD = 0x78;}
			if (TST_BIT(PINB, PB1)==0){
			PORTD = 0x00;}
			if (TST_BIT(PINB, PB2)==0){
			PORTD = 0x18;}
			SET_BIT(PORTC, 2);
			_delay_ms(50);
			CLR_BIT(PORTC, 3);
			if (TST_BIT(PINB, PB0)==0){
			PORTD = 0x08;}
			if (TST_BIT(PINB, PB1)==0){
			PORTD = 0x40;}
			if (TST_BIT(PINB, PB2)==0){
			PORTD = 0x;}
			SET_BIT(PORTC, 3);
			_delay_ms(50);
			
					

	}
		
}

