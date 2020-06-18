#include <iostream>

using namespace std;

bool max_element(int *p, int *q, int **res) {
	if (p == q)
		return false;
	*res = p;
	for (; p != q; ++p)
		if (*p > **res)
			*res = p;
	return true;
}

int main() {
	int m[10] = {1, 2, 3, 4, 5, 4, 3, 2, 1, 3};
	int *pmax = 0;

	if (max_element(m, m + 10, &pmax))
		cout << "Maximum = " << *pmax << endl;

	return 0;
}
