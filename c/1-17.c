/*
   Exercise 1-17 in K&R 2nd Edition
   Prints all lines over 80 chars
   Written by Z. Bornheimer (provided as is without warranty).
*/

#include <stdio.h>
#define MAXLINE 1000
#define MINCHAR 80

int my_getline(char s[], int lim);

/* print lines longer than MINCHAR */
main()
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = my_getline(line, MAXLINE)) > 0)
        if (len > MINCHAR)
            printf("%s", line);
    return 0;
}

/* my_getline: read a line into s, return length */
int my_getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n' && (s[i] = c); ++i);
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}
