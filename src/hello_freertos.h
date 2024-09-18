#ifndef HELLO_FREERTOS_H
#define HELLO_FREERTOS_H

void blink (int n);
char invert_capitalization (char c);

void main_task(__unused void *params);
void blink_task(__unused void *params);

#endif