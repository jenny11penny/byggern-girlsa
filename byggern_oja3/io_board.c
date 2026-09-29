#include "io_board.h"
#include "spi.h"
#include <util/delay.h>
#include <stdio.h>

Buttons IO_Readbuttons(void) {
    Buttons buttons;

    SPI_Select(0); //velger IO_boardet
    SPI_WriteByte(0x04); //send button kommando
    _delay_ms(0.04);

    buttons.right = SPI_ReadByte(); //leser 8 bits = 1 byte
    _delay_ms(0.002);

    buttons.left = SPI_ReadByte();
    _delay_ms(0.002);

    buttons.nav = SPI_ReadByte();
    
    SPI_Deselect(0);

    return buttons
}

void led_test(void) {
    SPI_Select(0); //velger IO_boardet
    SPI_WriteByte(0x05); //send led kommando
    _delay_ms(0.04);

    
}