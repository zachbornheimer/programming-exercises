#include <stdio.h>
/* print Fahrenheit-Celsius Table
    for fahr = 300, 280, ..., 0; floating-point version */

main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;      /* lower limit of temperature scale */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    fahr = upper;
    printf("Fahrenheit\tCelsius\n");
    printf("==========\t=======\n");
    while (fahr >= lower) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f\t\t%6.1f\n", fahr, celsius);
        fahr = fahr - step;
    }
}
