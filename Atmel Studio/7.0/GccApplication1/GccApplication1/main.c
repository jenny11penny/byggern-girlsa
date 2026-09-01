/*
 * GccApplication1.c
 *
 * Created: 01.09.2026 15:38:10
 * Author : jenng
 */ 


#define F_CPU 4915200UL
#define BAUD 9600
#define MYUBRR 31


#include <avr/io.h>
#include <util/delay.h>

void USART_Init(unsigned int ubrr);
void USART_Transmit(unsigned char data);
unsigned char USART_Receive( void );

int main( void )
{
	unsigned char c;
	USART_Init ( MYUBRR );
	
	USART_Transmit('a');
	
	while (1)
	{
		USART_Transmit('A');
		_delay_ms(1000);
		c = USART_Receive();
		USART_Transmit(c);
	}
}


void USART_Init( unsigned int ubrr )
{
	/* Set baud rate */
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	
	/* Enable receiver and transmitter */
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	
	/* Set frame format: 8data, 2stop bit */
	UCSR0C = (1<<URSEL0)|
			 (1<<USBS0)|
			 (3<<UCSZ00);
}

void USART_Transmit( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) )
	;
	/* Put data into buffer, sends the data */
	UDR0 = data;
	
}

unsigned char USART_Receive( void )
{
	/* Wait for data to be received */
	while ( !(UCSR0A & (1<<RXC0)) )
	;
	/* Get and return received data from buffer */
	return UDR0;
}

