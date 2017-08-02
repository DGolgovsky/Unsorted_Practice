#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

struct Duration {
    int hour;
    int min;
};

istream& operator>>(istream& is, Duration& duration) {
    is >> duration.hour;
    is.ignore(1);
    is >> duration.min;
    return is;
}

ostream& operator<<(ostream& os, const Duration& duration) {
    os << setfill('0');
    os << setw(2) << duration.hour << ':'
       << setw(2) << duration.min;
    return os;
}
int main()
{
    // Analogue of std::cin
    stringstream dur_ss("01:50");
    Duration dur1 {0, 0};
    dur_ss >> dur1;
    cout << dur1 << endl;
    operator<<(operator<<(cout, "hello"), " world");

    return 0;
}
