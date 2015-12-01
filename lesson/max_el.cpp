#include <iostream>
using namespace std;

bool max_element (int * p, int * q, int * res) {
	if (p == q)
		return false;
	*res = *p;
	for (; p != q; ++p)
		if (*p > *res)
			*res = *p;
	return true;
}

int main() {
	int m[10] = {1,2,3,4,5,4,3,2,1,3};
	int max = 0;
	if (max_element(m, m + 10, &max))
		cout << "Maximum = " << max << endl;
	return 0;
}
