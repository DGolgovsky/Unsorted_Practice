#include <iostream>

int main()
{
	bool S, T, R, A, B;
	std::cout << "For exit use ^C\nS T R >> A : B\n";
	while(true) {
		std::cin >> S >> T >> R;
		B = !S & !(T | R);
		A = !(T|R)|R;
		std::cout << A << ":" << B << "\n";
	}
	return 0;
}
