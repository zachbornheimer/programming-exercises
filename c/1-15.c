/*
Exercise 1-15 in K&R 2nd Edition
Functionized Fahrenheit-to-Celcius Conversion
Written by Z. Bornheimer (provided as is without warranty).
*/
#include <stdio.h>

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300; floating-point version */

float celcius(float);

main()
{
    float fahr;
    int lower, upper, step;

    lower = 0;   /* lower limit of temp scale */
    upper = 300; /* upper limit               */
    step = 20;   /* step size                 */

    fahr = lower;
    while (fahr <= upper) {
        printf("%3.0f %6.1f\n", fahr, celcius(fahr));
        fahr = fahr + step;
    }
}

float celcius(float fahr)
{
    float c;
    c = (5.0/9.0) * (fahr - 32.0);
    return c;
}
