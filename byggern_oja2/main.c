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

    SFIOR |= (1 << XMM2); //

    volatile uint8_t *adc = (uint8_t *)0x1000;
    volatile uint8_t *sram = (uint8_t *)0x1800;

    while (1)
    {
        //Test for å sjekke at CS veksler mellom høy og lav
        *adc = 0x55;
        _delay_ms(1000);

        *sram = 0xAA;
        _delay_ms(1000);

        //*((volatile uint8_t *)0x1000) = 0;
        //_delay_ms(1000);

        //*((volatile uint8_t *)0x1003) = 0;
        //_delay_ms(1000);
    }
}
