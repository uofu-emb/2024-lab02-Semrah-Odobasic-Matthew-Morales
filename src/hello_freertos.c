/**
 * Copyright (c) 2022 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"
#include "hello_lib.h"

#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "pico/cyw43_arch.h"

#define MAIN_TASK_PRIORITY      ( tskIDLE_PRIORITY + 1UL )
#define BLINK_TASK_PRIORITY     ( tskIDLE_PRIORITY + 2UL )
#define MAIN_TASK_STACK_SIZE configMINIMAL_STACK_SIZE
#define BLINK_TASK_STACK_SIZE configMINIMAL_STACK_SIZE

// This code runs in another thread to blink an LED
void blink_task(__unused void *params) {
    hard_assert(cyw43_arch_init() == PICO_OK);
    while (true) {
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, blink(5));
        vTaskDelay(500);
    }
}

// Inverts capitalization of letters passed through UART over USB or leaves them alone if they are not letters.
// Creates a new thread running the blink task.
void main_task(__unused void *params) {
    xTaskCreate(blink_task, "BlinkThread",
            BLINK_TASK_STACK_SIZE, NULL, BLINK_TASK_PRIORITY, NULL);

    char c;
    while(c = getchar()) {
        putchar(invert_capitalization(c));
    }
}

// Spools up a main thread which runs the main class, and starts the scheduler
int main( void )
{
    stdio_init_all();
    const char *rtos_name;
    rtos_name = "FreeRTOS";
    TaskHandle_t task;
    xTaskCreate(main_task, "MainThread",
                MAIN_TASK_STACK_SIZE, NULL, MAIN_TASK_PRIORITY, &task);
    vTaskStartScheduler();
    return 0;
}
