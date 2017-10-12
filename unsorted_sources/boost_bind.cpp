#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <iostream>
#include <vector>
#include <algorithm>


using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::greater;
//using namespace std;
using namespace boost;

class S {
public:
	const int number;
	S(int i) : number(i) {}
	void print () {
		cout << "S::f " << number << endl;
	}

/*	int f () {
		return number;
	}
*/
};

shared_ptr<S> create() {
	static int i = 0;
	return shared_ptr<S>(new S(i++));
}

int main() {
	vector< shared_ptr<S> > vec(6);
	generate(vec.begin(), vec.end(), create);
	function<void (shared_ptr<S>)> f = bind(&S::print, _1);
	for_each(vec.begin(), vec.end(), f);

	sort(vec.begin(), vec.end(), bind(
		greater<int>(),
/*
		bind(&S::f, _1),
		bind(&S::f, _2)
*/
		bind(&S::number, _1),
		bind(&S::number, _2)
	));

	for_each(vec.begin(), vec.end(), f);
	return 0;
}
