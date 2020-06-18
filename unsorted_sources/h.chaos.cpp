#include <iostream>

using namespace std;

int main() {
	int x = 5;
	int &y = x;
	int *z = &y;
	cout << "x = " << x << "\ny = " << y << "\nz = " << z;
	cout << endl;
	return 0;
}

