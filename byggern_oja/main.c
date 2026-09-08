#define F_CPU 4915200UL
#define BAUD 9600
#define MYUBRR 31

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "uart.h"


int main(void)
{
    unsigned char c;
    USART_Init(MYUBRR);

    USART_Transmit('a');

    fdevopen(uart_putchar, uart_getchar);

    printf("Hei!\r\n");

    while (1)
    {
    c = USART_Receive();
    USART_Transmit(c);
    }
}
