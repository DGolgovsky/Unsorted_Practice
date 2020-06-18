#include <iostream>

int main() {
	char s = 'a';
	for (int i = 1; i < 27; i++) {
		for (int j = 0; j != i; j++) {
			std::cout << s;
		}
		s++;
	}
	return 0;
}
