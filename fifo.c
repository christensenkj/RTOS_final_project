// FIFO accessor functions
#include "fifo.h"

// Array FIFO function declarations
void fifo_push(uint8_t *fifo, uint8_t *wr_ptr, uint8_t len, uint8_t val) {
	fifo[*wr_ptr] = val;
    *wr_ptr += 1;
    if (*wr_ptr == len) {
    	*wr_ptr = 0;
    }
}

// Array FIFO function declarations
uint8_t fifo_pop(uint8_t *fifo, uint8_t *rd_ptr, uint8_t len) {
	uint8_t val = fifo[*rd_ptr];
    *rd_ptr += 1;
    if (*rd_ptr == len) {
    	*rd_ptr = 0;
    }
    return val;
}

// Array FIFO
bool fifo_isempty(uint8_t *fifo, uint8_t *wr_ptr, uint8_t *rd_ptr) {
	if (*wr_ptr == *rd_ptr) {
		return true;
	}
	else {
		return false;
	}
}