/*
Exercise 1-10 in K&R 2nd Edition
Written by Z. Bornheimer (provided as is without warranty).
*/
#include <stdio.h>

/* copy input to output and replace tabs with \t, backspaces with \b, and backslashes with \\ */
main()
{
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
        } else if (c == '\b') {
            putchar('\\');
            putchar('b');
        } else if (c == '\\') {
            putchar('\\');
            putchar('\\');
        } else
            putchar(c);
    }
}
