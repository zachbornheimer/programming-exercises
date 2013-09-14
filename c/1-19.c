/*
   Exercise 1-19 in K&R 2nd Edition
   String Reversal
   Written by Z. Bornheimer (provided as is without warranty).
*/

#include <stdio.h>
#define MAXLINE 1000

void reverse(char s[]);

/* Calls reverse */
main()
{
    int len; /* current line length */
    int i = -1, j; /* two counters */
    int c; /* current char */
    char line[MAXLINE]; /* current input line */

    while ((c=getchar()) != EOF)
        if (c == '\n') {
            reverse(line);
            i = 0;
            while(line[i] != '\0')
                line[i++] = '\0';
            i = -1;
        } else
            line[++i] = c;
    return 0;
}

void reverse(char s[]) {
    /* Why wont this return s[] ? */

    char revLine[MAXLINE]; /* reversed line storage */
    int i = 0, j;

    while(s[i++] != '\0');

    for (j = 0; j<= i; j++)
        revLine[j] = s[i-j];

    for (j = 0; j <= i; j++) {
        s[j] = revLine[j];
        putchar(s[j]);
        putchar('\n');
    }
}

