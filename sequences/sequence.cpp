/*
 * Напишите на языке C/C++ программу поиска максимальной по длине монотонно
 * неубывающей подпоследовательности во входной последовательности вещественных
 * чисел. Если таких подпоследовательностей несколько, выведите первую из них
 * (найденную при просмотре входного потока первой).
 * Примечание: искомая подпоследовательность является «плотной», в ней нет
 * разрывов и посторонних элементов, включая числовые значения.
 *
 * Вход: одно целое N (длина последовательности; возможно, со знаком «плюс»),
 * за которым следует k вещественных чисел в любой разрешенной форме записи
 * (и, возможно, символ «перевод строки» /n). Если k = N, анализируется входная
 * последовательность вещественных целиком; если k > N, анализируется только
 * N первых (расположенных в традиционной записи слева) членов этой
 * последовательности. Если k < N (возможно, k = 0) или N < 2,
 * входная последовательность некорректна.
 *
 * Выход: два целых (натуральных), первое из которых L соответствует длине,
 * а второе — порядковому номеру i первого элемента найденной
 * подпоследовательности (принять i = 1, 2, 3, ...).
 * Если входная последовательность корректна, но искомая подпоследовательность
 * не обнаружена, вывести символ 0 (ноль). Во всех случаях подачи на вход
 * некорректных, в том числе символьных/строковых данных,
 * вывести строку [error] (вместе с квадратными скобками).
 *
 * Sample Input:
 * 7 1 2 3 4 5 6 7
 * Sample Output:
 * 7 1
 */

#include <iostream>

int main(void)
{
	double n;
	long double k, pk;

	std::cin >> n;
	if ((n - (long long)n) != 0) {
		std::cout << "[error]\n";
		return 0;
	}
	long long i = 0, len = 0, j = 0, ii = 0, len_max = 0;

	while (j < n && std::cin >> k) {
		++j;
		if (i == 0) {
			i = j;
			len = 1;
		} else if (pk <= k)
			++len;
		else {
			if (len > len_max) {
				ii = i;
                len_max = len;
            }
            i = j;
            len = 1;
        }
        pk = k;
    }

    if (std::cin && j == n && n >= 2) {
        if (len > len_max) {
            ii = i;
            len_max = len;
        }

        if (len_max > 1)
            std::cout << len_max << ' ' << ii << '\n';
        else
            std::cout << 0 << '\n';
    } else
        std::cout << "[error]\n";

    return 0;
}

