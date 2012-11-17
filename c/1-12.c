/*
Exercise 1-12 in K&R 2nd Edition
Written by Z. Bornheimer (provided as is without warranty).
*/
#include <stdio.h>

/* print each word given from input on its own line */
main() {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t')
            putchar('\n');
        else
            putchar(c);
    }
}
