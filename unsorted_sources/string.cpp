#include <iostream>
#include <string.h>

using namespace std;

int main() {
    setlocale(0, "");
    cout << "Длина 'Улисс' равна:\t";
    cout << strlen("Улисс");
    cout << '\n';
    cout << "Размер 'Улисс' равен:\t";
    cout << sizeof("Улисс");
    cout << endl;
    return 0;
}
