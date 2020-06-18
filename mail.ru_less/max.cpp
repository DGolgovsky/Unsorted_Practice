/*
#include <iostream>

int main() {
    int n, pre = 0, count = 1, max = 0;
    while (n) {
		//std::cout << "max = " << max << "\nn = ";
        std::cin >> n;
        if (n == pre)
            count++;
        else
            count = 1;
		max = (count > max) ? count : max;
        pre = n;
    }
    std::cout << max << "\n";
    return 0;
}
*/
/*
#include <iostream>

int main() {
    int a[100] = {};
    int size = 0;
    std::cin >> a[size];
    while (a[size] != 0) {
        size++;
        std::cin >> a[size];        
    }
    int count = 0;
	if (size < 3) {
		std::cout << count;
		return 0;
	}
    for (int *p = a+1; p <= a + size-2; ++p) {
		if (*(p-1) < *p && *p > *(p+1))
	        count++;
		std::cout << "*p     = " << *p     << "\n"
				  << "*(p-1) = " << *(p-1) << "\n"
				  << "*(p+1) = " << *(p+1) << "\n"
				  << "p      = " << p      << "\n";

	}
    std::cout << count;
    return 0;
}
*/
/*
#include <iostream>

int main() {
	int m[10] = {};
	for (int *p = m; p <= m + 9; ++p) {
		*p = (p - m) + 1;
		std::cout << "*p  = " << *p    << "\n"
				  << "p   = " << p     << "\n"
				  << "m   = " << m     << "\n"
				  << "p-m = " << p - m << "\n";
	}
	return 0;
}
*/
#include <iostream>

int main() {
	double p, x, y;
	std::cin >> p >> x >> y;
	x = x * 100 + y;
	std::cout << "x=" << x << "\n";
	x = x + x * (p / 100);
	std::cout << "x=" << x << "\n";
	y = (int) (x - ((int) (x / 100)) * 100);
	std::cout << "y=" << y << "\n";
	x = (x - y) / 100;
	std::cout << "x=" << x << "\n";
	std::cout << x << " " << y;
	return 0;
}
