#include <stdio.h>
#include <pico/stdlib.h>
#include <stdint.h>
#include <unity.h>
#include "unity_config.h"

#include "hello_lib.h"

void setUp(void) {}

void tearDown(void) {}

void test_capitalization () {
    TEST_ASSERT_EQUAL_CHAR(invert_capitalization('a'), 'A');
    TEST_ASSERT_EQUAL_CHAR(invert_capitalization('B'), 'b');
    TEST_ASSERT_EQUAL_CHAR(invert_capitalization('1'), '1');
}

void test_blink () {
    TEST_ASSERT_FALSE(blink(2));
    TEST_ASSERT_FALSE(blink(2));
    TEST_ASSERT_TRUE(blink(2));
    TEST_ASSERT_FALSE(blink(2));
    TEST_ASSERT_TRUE(blink(2));
    TEST_ASSERT_FALSE(blink(2));
}

int main (void)
{
    stdio_init_all();
    sleep_ms(5000); // Give time for TTY to attach.
    printf("Start tests\n");
    UNITY_BEGIN();
    RUN_TEST(test_capitalization);
    RUN_TEST(test_blink);
    sleep_ms(5000);
    return UNITY_END();
}
