#define F_CPU 4915200UL

#include "adc.h"
#include <avr/io.h>
#include <util/delay.h>

#define ADC_ADDRESS 0x1000

volatile uint8_t *adc_base = (volatile uint8_t *) ADC_ADDRESS;

void ADC_clock_init(void) {
    DDRD |= (1 << PD5); //Make PD5 output

    TCCR1A = (1 << COM1A0); //

    TCCR1B = (1 << WGM12) | (1 << CS10);

    OCR1A = 0;


    DDRB &= ~(1 << PB0);
    PORTB &= ~(1 << PB0);

}

Position ADC_read_pos(void) {
    Position position;

    *adc_base  = 0; 

    while (PINB & (1 << PB0)) {
    }

    while (!(PINB & (1 << PB0))) {

    }
    
    uint8_t y = *adc_base; //AIN0
    uint8_t x = *adc_base; //AIN1
    uint8_t y_touch = *adc_base; //AIN2
    uint8_t x_touch = *adc_base; //AIN3

    //position.x = ((int16_t)x * 200 / 255) - 100;
    //position.y = ((int16_t)y * 200 / 255) - 100;
    position.y = y;
    position.x = x;
    position.x_touch = x_touch;
    position.y_touch = y_touch;
    
    return position;
}

Direction ADC_read_dir(void) {
    Position position = ADC_read_pos();

    if (position.x < 100) {
        return LEFT;
    }
    if (position.x > 150) {
        return RIGHT;
    }
    if (position.y > 150) {
        return UP;
    }
    if (position.y < 100) {
        return DOWN;
    }

    return NEUTRAL;


}

void adc_test(void) {
    *adc_base  = 0;
}

