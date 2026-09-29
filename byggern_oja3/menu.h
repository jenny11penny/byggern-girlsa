#include <stdint.h>

void menu_init(const char *options[], uint8_t size);
void menu_update(const char *options[], uint8_t size);
int get_selected(void);
void menu_close(void);

