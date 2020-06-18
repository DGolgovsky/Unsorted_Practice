#include <iostream>

int main() {
	double paper = 1.0;
	double pap_mm = 0.1;
	for (unsigned short i = 0; i < 103; ++i) {
		paper = paper * 2.0;
		pap_mm = pap_mm * 2.0;
		std::cout << i + 1 << ":" << paper << "\n";
		std::cout << "\t" << pap_mm << "\n";
	}
	return 0;
}

