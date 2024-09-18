#include "pico/cyw43_arch.h"

// Takes a character and inverts its capitalization if it is a letter, leaves it unchanged otherwise
char invert_capitalization (char c) {
    if (c <= 'z' && c >= 'a') return c - 32;
    else if (c >= 'A' && c <= 'Z') return c + 32;
    else return c;
}

// Inverts the gpio every call, for a 50% duty cycle. Skips the nth blink
bool blink (int n) {
    static int count = 0;
    static bool on = false;

    if (count++ % (n*2+1)) on = !on;
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, on);

    return on;
}