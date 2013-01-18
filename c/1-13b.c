/*
Exercise 1-13b in K&R 2nd Edition
Vertical Histogram
Written by Z. Bornheimer (provided as is without warranty).
*/
#include <stdio.h>

#define MAXLENGTH 1000

/* print a vertical histogram of word lengths from input. */
main()
{
    int c, w;
    int wl[MAXLENGTH];
    w = 0; /* number of words processed */
    wl[w] = 0; /* initialize the first element of a word length arr */

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            ++w;
            wl[w] = 0;
        } else {
            ++wl[w];
        }
    }

    int smallestWL = MAXLENGTH + 1;
    int largestWL = 0;
    int i, j;

    for (i = 0; i <= w; ++i)
        if (wl[i] < smallestWL)
            smallestWL = wl[i];
        else if (wl[i] > largestWL)
            largestWL = wl[i];

    largestWL -= smallestWL;

    for (i = 0; i <= w; ++i)
        wl[i] -= smallestWL;

    while (largestWL != smallestWL) {
        for (i = 0; i <= w; ++i)
            if (wl[i] == largestWL) {
                printf(" | ");
                --wl[i];
            } else {
                printf("   ");
            }
        printf("\n");
        --largestWL;
    }

    for (i = 0; i < smallestWL; ++i) {
        for (i = 0; i <= w; ++i)
            printf (" | ");
        printf("\n");
    }
       
   
}
