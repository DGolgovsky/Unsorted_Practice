#include <iostream>

using namespace std;

struct date {
public:
    int day, month, year;
    char s;

    date()
            : day(0), month(0), year(0) {}
};

int main(void) {
    date d1;
    cout << "Enter date 31/12/2015: ";
    cin >> d1.day
        >> d1.s
        >> d1.month
        >> d1.s
        >> d1.year;
    cout << endl;

    cout << d1.day << '/'
         << d1.month << '/'
         << d1.year;
    cout << endl;

    return 0;
}
