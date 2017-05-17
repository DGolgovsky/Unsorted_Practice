#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using namespace boost;

class S {
public:
	S() {
		cout << "S::S" << endl;
	}

	~S() {
		cout << "S::~S" << endl;
	}
};

weak_ptr<S> copy(shared_ptr<S> t) {
	return t;
}

int main() {
	shared_ptr<S> s(new S);
	cout << "refs=" << s.use_count() << endl;
	weak_ptr<S> ws = copy(s);
	cout << "refs=" << s.use_count() << endl;

	shared_ptr<S> s2 = ws.lock();
	cout << "refs=" << s.use_count() << endl;
	return 0;
}
