#include <iostream>

using namespace std;

void left_one(int *m, int size) {
    int t = *m;
    for (int i = 1; i < size; ++i) {
        m[i - 1] = m[i];
    }
    m[size - 1] = t;
}

void rotate(int a[], unsigned size, int shift) {
    for (int i = 0; i < shift; ++i)
        left_one(&a[0], size);
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int size = 5;
    int shift = 3;
    for (int i = 0; i < shift; ++i)
        left_one(&a[0], size);
    for (int i = 0; i < size; ++i)
        cout << a[i] << " ";
    cout << "\n";
    return 0;
}
