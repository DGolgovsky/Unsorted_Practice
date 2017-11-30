#include <iostream>

struct Singleton {
	static Singleton& instance() {
		static Singleton s;
		return s;
	}

	int data() {
		std::cout << "executed\n";
		return 0;
	}

private:
	Singleton() {}

	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);

	int data_;
};
