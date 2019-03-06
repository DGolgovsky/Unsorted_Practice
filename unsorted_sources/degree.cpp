#include <iostream>
#include <math.h>

using namespace std;

int main() {
    const int f_var = 8;
    for (int i = 0; i < 10; i++) {
        cout << (float) pow(f_var, i) << endl;
    }
    return 0;
}