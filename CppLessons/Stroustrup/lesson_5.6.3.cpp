#include <iostream>

int main()
{
	try {
		int a = 2/0;
		return 0;
	}
	catch (exception& e) {
		std::cerr << "error: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		std::cerr << "Unknown exception\n";
		return 2;
	}
}
