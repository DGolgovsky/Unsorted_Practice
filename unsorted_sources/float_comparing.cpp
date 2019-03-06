#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float f_value1 = 1.1;
    cout << "f_value1 = 1.1 ";

    if (f_value1 == 1.1) {
        cout << "equal 1.1;" << endl;
    } else {
        cout << "not equal 1.1;" << endl;
    }

    cout << setprecision(10) << f_value1 << endl;

    if (f_value1 < 1.1000001) {
        cout << "lt 1.1000001;" << endl;
    } else {
        cout << "float type is suck;" << endl;
    }

    return 0;
}

