/*
Exercise 1-9 in K&R 2nd Edition
Written by Z. Bornheimer (provided as is without warranty).
*/
#include <stdio.h>

/* copy input to output and replace strings of blanks with a single blank */
main()
{
    int c, pc; /* c = character, pc = previous character */
    pc = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (pc != ' ') {
                putchar(c);
            }
        } else {
            putchar(c);
        }
        pc = c;
    }
}
