/*
Exercise 1-20 in K&R 2nd Edition
detab: clarified here: http://stackoverflow.com/questions/7178201/kr-exercise-1-20-need-some-clarification
Written by Z. Bornheimer (provided as is without warranty).
*/
#include <stdio.h>

#define MAXLEN 10000
#define TABSTOP 4

int detab(char c, char str[], int i);

/* calls detab with appropriate data */
main()
{
    int i = 0;
    char c, str[MAXLEN];
    while ((c = getchar()) != EOF)
       i = detab(c, str, i);
    printf("%s\n", str);
    return 0;
}

/* replaces tabs w/ spaces in accordance to TABSTOP */
int detab(char c, char str[], int i)
{
    if (c == '\t')
        do
            str[i++] = ' ';
        while ((i % TABSTOP) != 0);
    else
        str[i++] = c;
    return i;
}
