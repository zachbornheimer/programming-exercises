/*
Exercise 1-14 in K&R 2nd Edition
Histogram of Character Types
Written by Z. Bornheimer (provided as is without warranty).
*/
#include <stdio.h>

main()
{
    int c, i, ndigit, nwhite, nother;

    nwhite = nother = ndigit = 0;

    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigit;
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;

    printf("\ndigits:\t\t");
    for (i = 0; i < ndigit; ++i)
        printf("=");

    printf("\nwhitespace:\t");
    for (i = 0; i < nwhite; ++i)
        printf("=");

    printf("\nother:\t\t");
    for (i = 0; i < nother; ++i)
        printf("=");

}
