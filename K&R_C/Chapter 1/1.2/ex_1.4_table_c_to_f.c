#include <stdio.h>

/** 
 * вывод таблицы температур по Фаренгейту и Цельсию
 * для fahr = 0, 20, ..., 300
 * with float arithmetics
 */

int main(void)
{
    float fahr, celsius;
    int lower, upper, step;

    lower = -30;      /* нижняя граница температру в таблице */
    upper = 60;    /* верхняя граница */
    step = 5;      /* величина шага */

    celsius = lower;
    printf("%s\n", "Celsius Fahrengeit");
    while (celsius <= upper) {
        fahr = (9.0 / 5.0) * celsius + 32.0;
        printf("%3.0f\t %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }

    return 0;
}
