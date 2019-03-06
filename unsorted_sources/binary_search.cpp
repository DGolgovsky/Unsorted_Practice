#include <iostream>
#include <vector>

using namespace std;

vector<int>::const_iterator binarySearch(const vector<int> &container, int element) {
    const vector<int>::const_iterator endIt = end(container);

    vector<int>::const_iterator left = begin(container);
    vector<int>::const_iterator right = endIt;

    if (container.size() == 0
        || container.front() > element
        || container.back() < element) {
        return endIt;
    }

    while (distance(left, right) > 0) {
        const vector<int>::const_iterator mid = left + distance(left, right) / 2;

        if (element <= *mid) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    if (*right == element) {
        return right;
    }

    return endIt;
}

int main() {
    const vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // отсортированный контейнер
    const int element = 8; // искомый элемент

    auto foundIt = binarySearch(vec, element);
    if (foundIt != vec.end()) {
        cout << *foundIt << endl;
    }
    return 0;
}
