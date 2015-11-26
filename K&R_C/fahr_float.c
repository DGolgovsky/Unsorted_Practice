#include <stdio.h>

/* Temperature table F & C
 * for fahr = 0, 20, ..., 300
 * float version */

main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower edge temp. in table */
    upper = 300;    /* upper edge temp. in table */
    step = 20;      /* step value */

    fahr = lower;
    printf("%2s %5s\n","F", "C");
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr += step;
    }
}
