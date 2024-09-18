#include <stdio.h>
#include <pico/stdlib.h>
#include <stdint.h>
#include <unity.h>
#include "unity_config.h"

#include "hello_lib.h"

void setUp(void) {}

void tearDown(void) {}

void test_capitalization() {

    //Test for de-capitalization at end bounds and a few in between.
    TEST_ASSERT_EQUAL_CHAR(invert_capitalization('A'), 'a');
    TEST_ASSERT_EQUAL_CHAR(invert_capitalization('Z'), 'z');
    TEST_ASSERT_EQUAL_CHAR(invert_capitalization('S'), 's');
    TEST_ASSERT_EQUAL_CHAR(invert_capitalization('M'), 'm');
    TEST_ASSERT_EQUAL_CHAR(invert_capitalization('J'), 'j');

    //Test for capitalization at end bounds and a few in between.
    TEST_ASSERT_EQUAL_CHAR(invert_capitalization('a'), 'A');
    TEST_ASSERT_EQUAL_CHAR(invert_capitalization('z'), 'Z');
    TEST_ASSERT_EQUAL_CHAR(invert_capitalization('s'), 'S');
    TEST_ASSERT_EQUAL_CHAR(invert_capitalization('m'), 'M');
    TEST_ASSERT_EQUAL_CHAR(invert_capitalization('j'), 'J');

    //Test a few non-alphabet characters. Testing some near the bounds of letters.
    TEST_ASSERT_EQUAL_CHAR(invert_capitalization('@'), '@');
    TEST_ASSERT_EQUAL_CHAR(invert_capitalization('['), '[');
    TEST_ASSERT_EQUAL_CHAR(invert_capitalization('\''), '\'');
    TEST_ASSERT_EQUAL_CHAR(invert_capitalization('{'), '{');
    TEST_ASSERT_EQUAL_CHAR(invert_capitalization('?'), '?');
    TEST_ASSERT_EQUAL_CHAR(invert_capitalization(':'), ':');
    TEST_ASSERT_EQUAL_CHAR(invert_capitalization('+'), '+');
}

void test_blink () {
    int result = 0;
    int result_prev = 0;

    for(int i = 0 ; i < 100; i++){
        result = blink(11);
        
        if(i % (11*2+1) == 0) {
            TEST_ASSERT_EQUAL_INT_MESSAGE(result, result_prev, "Blink should not change output.");
        } else {
            TEST_ASSERT_NOT_EQUAL_INT_MESSAGE(result, result_prev, "Blink should change output.");
        }
        
        result_prev = result;
    }
}

int main (void)
{
    stdio_init_all();
    sleep_ms(10000); // Give time for TTY to attach.
    printf("Start tests\n");
    UNITY_BEGIN();
    RUN_TEST(test_capitalization);
    RUN_TEST(test_blink);
    sleep_ms(60000);
    return UNITY_END();
}
