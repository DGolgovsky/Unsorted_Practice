#include <iostream>
using namespace std;

void strcat(char *to, const char *from) {
	for (; *to; ++to)
		while(*to++ = *from++);
}

int main() {
	char a[100] = "AAA";
	cout << a << "\n";
	strcat(a, "BBB");
	cout << a << "\n";
	return 0;
}
