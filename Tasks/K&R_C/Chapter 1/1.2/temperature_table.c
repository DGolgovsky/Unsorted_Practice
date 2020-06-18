#include <stdio.h>

/** 
 * вывод таблицы температур по Фаренгейту и Цельсию
 * для fahr = 0, 20, ..., 300
 * with float arithmetics
 */

int main(void) {
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;      /* нижняя граница температру в таблице */
	upper = 300;    /* верхняя граница */
	step = 20;      /* величина шага */

	fahr = lower;
	while (fahr <= upper) {
		celsius = (5.0 / 9.0) * (fahr - 32);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}

	return 0;
}
