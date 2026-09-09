#define F_CPU 4915200UL
#define BAUD 9600
#define MYUBRR 31

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "uart.h"
#include "sram_test.h"

int main(void)
{

    USART_Init(MYUBRR);
    fdevopen(uart_putchar, uart_getchar);
    printf("Hei!");

    MCUCR = (1 << SRE); //

    SFIOR |= (1 << XMM2);

    SRAM_test();

    while (1)
    {
        *((volatile uint8_t *)0x1000) = 0;
        _delay_ms(1000);

        *((volatile uint8_t *)0x1003) = 0;
        _delay_ms(1000);
    }
}
