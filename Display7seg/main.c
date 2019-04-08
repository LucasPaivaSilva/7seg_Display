/*
 *
 * Created: 12/03/2019 16:35:41
 *  Author: Aluno
 */ 



#define F_CPU 16000000UL	//define a frequencia do microcontrolador - 16MHz
#include <avr/io.h> 	    //definições do componente especificado
#include <util/delay.h>		//biblioteca para o uso das rotinas de _delay_ms e _delay_us()
#define	set_bit(y,bit)	(y|=(1<<bit))	//coloca em 1 o bit x da variável Y
#define	clr_bit(y,bit)	(y&=~(1<<bit))	//coloca em 0 o bit x da variável Y
#define cpl_bit(y,bit) 	(y^=(1<<bit))	//troca o estado lógico do bit x da variável Y
#define tst_bit(y,bit) 	(y&(1<<bit))	//retorna 0 ou 1 conforme leitura do bit
const unsigned char ScanBytes[]= {0b11111110, 0b11111101, 0b11111011, 0b11110111};
unsigned char PadDigits[4] [4] =   {{0x40, 0x79, 0x24, 0x30},
									{0x19, 0x12, 0x02, 0x78},
									{0x00, 0x18, 0x08, 0x03},
									{0x46, 0x21, 0x06, 0x0E}};

int main(void)
{
	int x = 0;
	int y = 0;
	DDRB  = 0xFF;	//Conigura como saida
	DDRD  = 0xFF;	//Conigura como saida
	DDRC  = 0x00;	//Conigura como entrada
	PORTC = 0xFF;	//Habilita o pull up do port B
	
	
	while(1)
	{
		for (x=0;x<4;x++)
		{
			PORTD = ScanBytes[x]; // Mudo o estado da saida do port para valor em scanbytes
			for (y=0;y<4;y++)
			{
				if (tst_bit(PINC, y)==0)
				{
					PORTB = PadDigits[x][y];
				}
			}
		}
		

	}
	
}