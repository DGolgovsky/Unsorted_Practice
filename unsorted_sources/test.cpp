#include <cmath>
#include <iostream>

using namespace std;

int main() {
    long long trn;
    cin >> trn;

    if (trn < 1)
        std::cout << "0";
    else {
        long double s = sqrt(trn * 2);
        if (long(s) *long(s + 1) / 2 == trn)
            std::cout << long(s);
        else
            std::cout << "0";
    }

    std::cout << std::endl;
    return 0;
}
