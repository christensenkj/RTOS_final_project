#include "slider.h"

void force_task(uint8_t direction, double *force_data){
    double nominal_force = 100;
    switch (direction) {
        case INACTIVE:
            *force_data = 0;
            break;
        case HARD_LEFT:
            *force_data = -1.5*nominal_force;
            break;
        case SOFT_LEFT:
            *force_data = -1*nominal_force;
            break;
        case SOFT_RIGHT:
            *force_data = nominal_force;
            break;
        case HARD_RIGHT:
            *force_data = 1.5*nominal_force;
            break;
        default:
            break;
    }
}