#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "C");
    char C1 = 0, C2 = 0;
    cout << "Введите символ C1: ";
    cin >> C1;
    cout << "Введите символ C2: ";
    cin >> C2;
    cout << endl;
    int first = 0, last = 0;

    if ((int) C1 < (int) C2) {
        first = (int) C1;
        last = (int) C2;
    } else {
        first = (int) C2;
        last = (int) C1;
    }

    for (int i = last - 1; i > first; --i) {
        cout << (char) i << " ";
    }
    cout << endl;
    return 0;
}
