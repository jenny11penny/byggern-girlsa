#define F_CPU 4915200UL
#define BAUD 9600
#define MYUBRR 31

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "uart.h"
#include "sram_test.h"
#include "adc.h"
#include "spi.h"
#include "OLED.h"
#include "menu.h"
#include "io_board.h"

int main(void)
{
    USART_Init(MYUBRR);
    fdevopen(uart_putchar, uart_getchar);
    printf("Hei!");

    MCUCR |= (1 << SRE); //aktivere external memomry

    SFIOR |= (1 << XMM2); //
    
    //volatile uint8_t *adc = (uint8_t *)0x1000;
    //volatile uint8_t *sram = (uint8_t *)0x1800;

    ADC_clock_init();
    ADC_calibrate();

    SPI_Init();
    OLED_Init();
    OLED_Clear();

    OLED_Pos(0,0);

    const char *options[] = {"JA", "NEI", "KANSKJE"};
    uint8_t size = sizeof(options) / sizeof(options[0]);

    menu_init(options, size);

    joystick_btn_init();

   

    while (1)
    {


        
        /*

        if (!joystick_btn_pressed()) {
            menu_update(options, size);
           _delay_ms(200);
        }
        
        else {
            menu_close();
            int selected = get_selected();

            OLED_Pos(0,0);
            OLED_Clear();

            switch(selected) {
                case 0:
                OLED_Print("valg 1"); break;
                case 1:
                OLED_Print("valg 2"); break;
                case 2:
                OLED_Print("valg 3"); break;
            } 
                
        }      */    
    }
}
