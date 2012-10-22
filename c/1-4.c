/*
Exercise 1-4 in K&R 2nd Edition
Written by Z. Bornheimer (provided as is without warranty).
*/

#include <stdio.h>
/* print Celsius-Fahrenheit Table
    for celsius = 0, 20, ..., 300; floating-point version */

main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;      /* lower limit of temperature scale */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    celsius = lower;
    printf("Celsius\tFahrenheit\n");
    printf("=======\t==========\n");
    while (celsius <= upper) {
        fahr = (9.0/5.0) * (celsius+32.0);
        printf("%3.0f\t%6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
