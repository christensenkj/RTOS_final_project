#include <stdlib.h>
#include "ctest.h"
#include "buttons.h"
#include "physics_model.h"
#include "fifo.h"
#include "slider.h"


// Test the button task logic
CTEST_DATA(button_test_1) {
};

CTEST_SETUP(button_test_1) {
}

CTEST2(button_test_1, test_process1) {
    uint32_t gain_data = 0;
    decrease_gain(&gain_data);
    ASSERT_EQUAL(gain_data, 0);
}

CTEST2(button_test_1, test_process2) {
    uint32_t gain_data = 20;
    increase_gain(&gain_data);
    ASSERT_EQUAL(gain_data, 20);
}

CTEST2(button_test_1, test_process3) {
    uint32_t gain_data = 10;
    increase_gain(&gain_data);
    ASSERT_EQUAL(gain_data, 11);
}

CTEST2(button_test_1, test_process4) {
    uint32_t gain_data = 10;
    decrease_gain(&gain_data);
    ASSERT_EQUAL(gain_data, 9);
}

// Test the slider task logic
CTEST_DATA(slider_test_1) {
};

CTEST_SETUP(slider_test_1) {
}

CTEST2(slider_test_1, test_process1) {
    double force_data = 0.0;
    force_task(INACTIVE, &force_data);
    ASSERT_INTERVAL(0-0.0001, 0+0.0001, force_data);
}

CTEST2(slider_test_1, test_process2) {
    double force_data = 0.0;
    force_task(HARD_LEFT, &force_data);
    ASSERT_INTERVAL(-150-0.0001, -150+0.0001, force_data);
}

CTEST2(slider_test_1, test_process3) {
    double force_data = 0.0;
    force_task(SOFT_LEFT, &force_data);
    ASSERT_INTERVAL(-100-0.0001, -100+0.0001, force_data);
}

CTEST2(slider_test_1, test_process4) {
    double force_data = 0.0;
    force_task(SOFT_RIGHT, &force_data);
    ASSERT_INTERVAL(100-0.0001, 100+0.0001, force_data);
}

CTEST2(slider_test_1, test_process5) {
    double force_data = 0.0;
    force_task(HARD_RIGHT, &force_data);
    ASSERT_INTERVAL(150-0.0001, 150+0.0001, force_data);
}


// Test the fifo logic
CTEST_DATA(fifo_test1) {
    /* Declare a fifo for button actions */
    uint8_t btn0_fifo[FIFO_LEN];
    uint8_t btn0_fifo_rd;
    uint8_t btn0_fifo_wr;
};

CTEST_SETUP(fifo_test1) {
    // Declare the two FIFOs
    data->btn0_fifo_rd = 0;
    data->btn0_fifo_wr = 0;
}

CTEST2(fifo_test1, test_process1) {
    fifo_push(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN, 0);
    ASSERT_EQUAL(data->btn0_fifo[0], 0);
    fifo_push(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN, 1);
    ASSERT_EQUAL(data->btn0_fifo[1], 1);
    fifo_push(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN, 2);
    ASSERT_EQUAL(data->btn0_fifo[2], 2);
    fifo_push(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN, 3);
    ASSERT_EQUAL(data->btn0_fifo[3], 3);
    fifo_push(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN, 4);
    ASSERT_EQUAL(data->btn0_fifo[4], 4);
    fifo_push(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN, 5);
    ASSERT_EQUAL(data->btn0_fifo[5], 5);
    fifo_push(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN, 6);
    ASSERT_EQUAL(data->btn0_fifo[6], 6);
    fifo_push(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN, 7);
    ASSERT_EQUAL(data->btn0_fifo[7], 7);
    fifo_push(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN, 8);
    ASSERT_EQUAL(data->btn0_fifo[8], 8);
    fifo_push(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN, 9);
    ASSERT_EQUAL(data->btn0_fifo[9], 9);
    ASSERT_EQUAL(data->btn0_fifo_wr, 9);
    fifo_push(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN, 10);
    ASSERT_EQUAL(data->btn0_fifo[0], 10);
    ASSERT_EQUAL(data->btn0_fifo_wr, 0);
}

CTEST_DATA(fifo_test2) {
    /* Declare a fifo for button actions */
    uint8_t btn0_fifo[FIFO_LEN];
    uint8_t btn0_fifo_rd;
    uint8_t btn0_fifo_wr;
};

CTEST_SETUP(fifo_test2) {
    // Declare the two FIFOs
    data->btn0_fifo_rd = 0;
    data->btn0_fifo_wr = 0;
    fifo_push(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN, 0);
    fifo_push(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN, 1);
    fifo_push(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN, 2);
    fifo_push(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN, 3);
    fifo_push(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN, 4);
    fifo_push(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN, 5);
    fifo_push(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN, 6);
    fifo_push(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN, 7);
    fifo_push(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN, 8);
    fifo_push(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN, 9);
}

CTEST2(fifo_test2, test_process1) {
    uint8_t fifo_data;
    ASSERT_EQUAL(data->btn0_fifo_wr, 9);
    ASSERT_EQUAL(data->btn0_fifo_rd, 0);
    fifo_data = fifo_pop(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN);
    ASSERT_EQUAL(fifo_data, 0);
    ASSERT_EQUAL(data->btn0_fifo_rd, 1);
    fifo_data = fifo_pop(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN);
    ASSERT_EQUAL(fifo_data, 1);
    ASSERT_EQUAL(data->btn0_fifo_rd, 2);
    fifo_data = fifo_pop(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN);
    ASSERT_EQUAL(fifo_data, 2);
    ASSERT_EQUAL(data->btn0_fifo_rd, 3);
    fifo_data = fifo_pop(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN);
    ASSERT_EQUAL(fifo_data, 3);
    ASSERT_EQUAL(data->btn0_fifo_rd, 4);
    fifo_data = fifo_pop(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN);
    ASSERT_EQUAL(fifo_data, 4);
    ASSERT_EQUAL(data->btn0_fifo_rd, 5);
    fifo_data = fifo_pop(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN);
    ASSERT_EQUAL(fifo_data, 5);
    ASSERT_EQUAL(data->btn0_fifo_rd, 6);
    fifo_data = fifo_pop(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN);
    ASSERT_EQUAL(fifo_data, 6);
    ASSERT_EQUAL(data->btn0_fifo_rd, 7);
    fifo_data = fifo_pop(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN);
    ASSERT_EQUAL(fifo_data, 7);
    ASSERT_EQUAL(data->btn0_fifo_rd, 8);
    fifo_data = fifo_pop(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN);
    ASSERT_EQUAL(fifo_data, 8);
    ASSERT_EQUAL(data->btn0_fifo_rd, 9);
    fifo_data = fifo_pop(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN);
    ASSERT_EQUAL(fifo_data, 9);
    ASSERT_EQUAL(data->btn0_fifo_rd, 0);
    fifo_data = fifo_pop(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN);
    ASSERT_EQUAL(fifo_data, 0);
    ASSERT_EQUAL(data->btn0_fifo_rd, 1);
}

// Test the physics model
CTEST_DATA(physics_test) {
    /* Declare a fifo for button actions */
    uint8_t btn0_fifo[FIFO_LEN];
    uint8_t btn0_fifo_rd;
    uint8_t btn0_fifo_wr;
};

CTEST_SETUP(fifo_test2) {
    // Declare the two FIFOs
    data->btn0_fifo_rd = 0;
    data->btn0_fifo_wr = 0;
    fifo_push(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN, 0);
    fifo_push(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN, 1);
    fifo_push(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN, 2);
    fifo_push(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN, 3);
    fifo_push(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN, 4);
    fifo_push(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN, 5);
    fifo_push(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN, 6);
    fifo_push(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN, 7);
    fifo_push(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN, 8);
    fifo_push(data->btn0_fifo, &(data->btn0_fifo_wr), FIFO_LEN, 9);
}