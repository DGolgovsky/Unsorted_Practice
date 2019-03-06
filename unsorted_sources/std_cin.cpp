#include <iostream>
#include <cstdint>

using namespace std;

int main() {
    double n = 807272713154108620; /* last: 1170806329431379766 */
    for (double i = 1270647640 /* last: 1530232876 */; i < 9223372036854775807; ++i) {
        n = n + i;
        std::cout << n << ":" << i << "\n";
    }
    return 0;
}
