/*
Exercise 1-8 in K&R 2nd Edition
Written by Z. Bornheimer (provided as is without warranty).
*/
#include <stdio.h>

/* Count blanks, tabs, and newlines */
main()
{
    int c, blanks, newlines, tabs;
    blanks = newlines = tabs = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++blanks;
        if (c == '\n')
            ++newlines;
        if (c == '\t')
           ++tabs; 
    }
    
    printf("Total number of Blanks: %d, Tabs: %d, Newlines: %d\n", blanks, newlines, tabs);

}
