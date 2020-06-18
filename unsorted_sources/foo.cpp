#include <iostream>

struct Foo
{
public:
	void say() const {
		std::cout << "Foo says: " << msg << "\n";
	}

protected:
	Foo(const char *msg) : msg(msg) {}

private:
	const char *msg;
};

void foo_says(const Foo &foo) {
	foo.say();
}

Foo get_foo(const char *str) { return *(Foo *) &str; }

int main() {
	foo_says(get_foo("M"));
	//Foo t = Foo("M");

	return 0;
}
