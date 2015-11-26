#include <stdio.h>

/* Temperature table F & C
 * for fahr = 0, 20, ..., 300 */
main()
{
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower edge temp. in table */
    upper = 300;    /* upper edge temp. in table */
    step = 20;      /* step value */

    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%3d %6d\n", fahr, celsius);
        fahr += step;
    }
}
