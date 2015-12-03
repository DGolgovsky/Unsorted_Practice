/*
Последовательность состоит из натуральных чисел и завершается числом 0. Определите значение второго по величине элемента в этой последовательности, то есть элемента, который будет наибольшим, если из последовательности удалить наибольший элемент.
*/
// Shitty code :'(

#include <iostream>

int main()
{
	int N = 0, max = 0, i = 0, pre_m = 0;
	int ar[100];
	while (std::cin >> N) {
		if (N == 0)
			break;
		ar[i++] = N;
	}
	for (;--i != -1;) {
		if (ar[i] >= pre_m && pre_m <= max)
			pre_m = ar[i];
		if (ar[i] >= max) { 
			pre_m = max;     
			max = ar[i];
		}
	/* DEBUG (lol)
	std::cout << "i=" << i
			  << ",min=" << pre_m
			  << ",max=" << max << "\n";
	*/
	}

	std::cout << pre_m << "\n";
	return 0;
}

