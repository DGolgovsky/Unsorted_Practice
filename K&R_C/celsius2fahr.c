#include <stdio.h>

/* Temperature table C & F
 * for cels = 0, 20, ..., 300
 * float version */

main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower edge temp. in table */
    upper = 300;    /* upper edge temp. in table */
    step = 20;      /* step value */

    celsius = lower;
    printf("%2s %4s\n","C", "F");
    while (celsius <= upper) {
        fahr = (9.0/5.0) * celsius + 32.0;
        printf("%3.0f %4.0f\n", celsius, fahr);
        celsius += step;
    }
}
