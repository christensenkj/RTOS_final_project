/*
 * fifo.h
 *
 *  Created on: Mar 25, 2021
 *      Author: Karston Christensen
 */

#ifndef SRC_FIFO_H_
#define SRC_FIFO_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define FIFO_LEN	10

// Array FIFO function declarations
void fifo_push(uint8_t *fifo, uint8_t *wr_ptr, uint8_t len, uint8_t val);
// Array FIFO function declarations
uint8_t fifo_pop(uint8_t *fifo, uint8_t *rd_ptr, uint8_t len);
bool fifo_isempty(uint8_t *fifo, uint8_t *wr_ptr, uint8_t *rd_ptr);

#endif /* SRC_FIFO_H_ */
