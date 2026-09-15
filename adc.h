
#include <stdint.h>

typedef struct {
    uint8_t x;
    uint8_t y;
    uint8_t x_touch;
    uint8_t y_touch;
} Position;


typedef enum {
    LEFT,
    RIGHT,
    UP,
    DOWN,
    NEUTRAL
} Direction;


void ADC_clock_init(void);
Position ADC_read_pos(void);
Direction ADC_read_dir(void);
void adc_test(void);