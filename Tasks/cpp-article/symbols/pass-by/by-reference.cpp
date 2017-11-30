#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

int sum(const int& a, int& b) {
    cout << "sum(const int&, int&)" << endl;
    const int c = a + b;
    ++b; // Will modify caller variable
    // ++a; // Not allowed, but would also modify caller variable
    return c;
}

float sum(float& a, const float& b) {
    cout << "sum(float&, const float&)" << endl;
    return a + b;
}

int sum(const std::vector<int>& v) {
    cout << "sum(const std::vector<int>&)" << endl;
    return accumulate(v.begin(), v.end(), 0);
}

float sum(const std::vector<float>& v) {
    cout << "sum(const std::vector<float>&)" << endl;
    return accumulate(v.begin(), v.end(), 0.0f);
}

