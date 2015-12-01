#include "hello.h"
#include <iostream>

using std::cin;

int main() {
	string in_data = "";
	cin >> in_data;
	int number = (int) in_data;
	hello(number);
	return 0;
}
