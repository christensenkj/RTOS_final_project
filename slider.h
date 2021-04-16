#include <stdint.h>
#include <stdbool.h>

#define INACTIVE    255
#define HARD_LEFT   0
#define SOFT_LEFT   1
#define SOFT_RIGHT  2
#define HARD_RIGHT  3

void force_task(uint8_t direction, double *force_data);