/*
   Exercise 1-18 in K&R 2nd Edition
   Removes trailing blanks & tabs & blank lines from each line of input
   Written by Z. Bornheimer (provided as is without warranty).
*/

#include <stdio.h>
#define MAXLINE 1000

/* removes trailing blanks and tabs...deletes null lines */
main()
{
    int len; /* current line length */
    int i = -1, j; /* two counters */
    int c; /* current char */
    char line[MAXLINE]; /* current input line */

    while ((c=getchar()) != EOF) {
        line[++i] = c;
        if (c == '\n') {
            j = i + 1;
            while (line[--j] == ' ' || line[j] == '\n' || line[j] == '\t')
                line[j] = '\0';

            printf("%s", line);

            for (j = 0; j <= i; j++)
                line[j] = '\0';

            i = -1;
        }
    }
    return 0;
}
