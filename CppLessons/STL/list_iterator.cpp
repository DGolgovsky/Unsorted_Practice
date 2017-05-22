#include <iostream>
#include <list>

using namespace std;

int main(void)
{
    list<int> numbers;

    for (int i = 10; i < 20; ++i)
        numbers.push_back(i);

    list<int>::iterator ptr;

    for (ptr = numbers.begin(); ptr != numbers.end(); ++ptr)
        cout << *ptr << " ";
    cout << endl;

    /* ERROR
     * for (ptr = numbers.end(); ptr != numbers.begin(); --ptr)
     */

    for (ptr = numbers.end(); ptr != numbers.begin();) {
        ptr--;
        cout << *ptr << " ";
    }
    cout << endl;

    return 0;
}

