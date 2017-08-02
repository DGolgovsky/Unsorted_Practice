#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int sum(int const * a, int const * const b) {
    cout << "sum(int const *, int const * const)" << endl;
    const int c = *a + *b;
    // *a = 4; // Can't change. The value pointed to is const.
    // *b = 4; // Can't change. The value pointed to is const.
    a = b; // I can make a point to another const int 
    // b = a; // Can't change where b points because the pointer itself is const.
    return c;
}

float sum(float * const a, float * b) {
    cout << "sum(int const * const, float const *)" << endl;
    return *a + *b;
}

int sum(const std::vector<int>* v) {
    cout << "sum(std::vector<int> const *)" << endl;
    // v->clear(); // I can't modify the const object pointed by v
    const int c = accumulate(v->begin(), v->end(), 0);
    v = NULL; // I can make v point to somewhere else
    return c;
}

float sum(const std::vector<float> * const v) {
    cout << "sum(std::vector<float> const * const)" << endl;
    // v->clear(); // I can't modify the const object pointed by v
    // v = NULL; // I can't modify where the pointer points to
    return accumulate(v->begin(), v->end(), 0.0f);
}

