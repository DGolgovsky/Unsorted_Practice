#include <iostream>

int main() {
	char v[6];
	v[3] = 12;
	char* p = &v[3];
	int x = *p;
	std::cout << x;
	return 0;
}

