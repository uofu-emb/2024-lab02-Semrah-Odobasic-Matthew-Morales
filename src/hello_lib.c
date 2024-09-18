// Takes a character and inverts its capitalization if it is a letter, leaves it unchanged otherwise
char invert_capitalization (char c) {
    if (c <= 'z' && c >= 'a') return c - 32;
    else if (c >= 'A' && c <= 'Z') return c + 32;
    else return c;
}

// Inverts the output every call, for a 50% duty cycle. Skips the nth call
char blink (int n) {
    static int count = 0;
    static char on = 0;

    if (count++ % (n*2+1)) on = !on;

    return on;
}