/*
Exercise 1-16 in K&R 2nd Edition
Revision of the Longest-Line routine to print the length of long input lines and as much of the text as possible.
Written by Z. Bornheimer (provided as is without warranty).
*/



#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[], int maxline); /* changed to avoid redclaration error */
void copy(char to[], char from[]);

/* print the longest input line */
main()
{
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line saved here */

    max = 0;
    while ((len = my_getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0) /* there was a line */
        printf("CHARS: %d, STRING: %s", max, longest);
    return 0;
}

/* my_getline: read a line into s, return length */
int my_getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n' && (s[i] = c); ++i);
        /* NOTE TO SELF: s[i] can be defined in the loop */
    if (c == '\n') {
        s[i++] = c; /* s[i] = c; ++i ? */
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[0], char from[])
{
    int i;

    i = -1;
    while ((to[++i] = from[i]) != '\0'); /* i = 0, while ((to[i] = from[i]) != '\0') ++i;  NOTE TO SELF: ++i in the for loop effect the i next ot it */
}
