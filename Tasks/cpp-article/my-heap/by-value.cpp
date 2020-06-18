#include <vector>
#include <numeric>
#include <iostream>

// std::vector, std::accumulate, std::cout, std::endl
using namespace std;

int sum(int a, const int b) {
	cout << "sum(int, const int)" << endl;
	const int c = a + b;
	++a; // Possible, not const
	// ++b; // Not possible, this would result in a compilation error
	return c;
}

float sum(const float a, float b) {
	cout << "sum(const float, flaot)" << endl;
	return a + b;
}

int sum(vector<int> v) {
	cout << "sum(vector<int>)" << endl;
	return accumulate(v.begin(), v.end(), 0);
}

float sum(const vector<float> v) {
	cout << "sum(const vector<float>)" << endl;
	return accumulate(v.begin(), v.end(), 0.0f);
}

