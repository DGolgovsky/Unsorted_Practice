#include <iostream>
#include "Counters.hpp"
#include "increment1.hpp"
#include "increment2.hpp"

using namespace std;

int main(int argc, char *argv[]) {
	Counters c;
	increment1(c); // 3 times
	increment1(c);
	increment1(c);
	increment2(c); // 4 times
	increment2(c);
	increment2(c);
	increment2(c);
	cout << "c.get1(): " << c.get1() << endl; // Should be 3
	cout << "c.get2(): " << c.get2() << endl; // Should be 4
#ifndef NDEBUG // For debug builds
	cout << "c.getDebugAllCounters(): " << c.getDebugAllCounters() << endl; // Should be 3 + 4 = 7
#endif
	return 0;
}

