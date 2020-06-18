#include <iostream>

using namespace std;

int main() {
	setlocale(0, "");
	cout << "введите число от 0 до 255 ";
	int i;
	cin >> i;
	for (int n = 7; n >= 0; n--) {
		cout << (i & (1 << n) ? 1 : 0);
/* Equal:
		if (i & (1 << n)) {
			cout << 1;
		} else {
			cout << 0;
		}
*/
	}
	cout << endl;
	return 0;
}
