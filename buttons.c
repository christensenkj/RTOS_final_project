// Buttons accessor functions

#include "buttons.h"

void increase_gain(uint32_t *gain_data) {
    if (*gain_data < 20) {
        *gain_data = *gain_data+1;
    }
}
void decrease_gain(uint32_t *gain_data) {
        if (*gain_data > 0) {
        *gain_data = *gain_data-1;
    }
}
