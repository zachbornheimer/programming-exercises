/*
Exercise 1-13a in K&R 2nd Edition
Horizontal Histogram
Written by Z. Bornheimer (provided as is without warranty).
*/
#include <stdio.h>

#define MAXLENGTH 1000

/* print a horizontal histogram of word lengths from input. */
main()
{
    int c, w;
    int wl[MAXLENGTH];
    w = 0; /* number of words processed */
    wl[w] = 0; /* initialize the first element length */

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            ++w;
            wl[w] = 0;
        } else {
            ++wl[w];
        }
    }
    int i, j;
    for (i = 0; i <= w; ++i) {
        for (j = 0; j < wl[i]; ++j)
            printf("=");
        printf("\n");
    }
}
