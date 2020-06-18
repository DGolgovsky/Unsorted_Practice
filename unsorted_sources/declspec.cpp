// clang -fdeclspec -lstdc++ this.cpp -o a.out

#include <iostream>

class Person
{
private:
	int age_;

public:
	int get_age() const {
		return age_;
	}

	void set_age(int value) {
		age_ = value;
	}

	__declspec(property(get=get_age, put=set_age)) int age;
};

int main() {
	Person person;
	person.age = 20;

	std::cout << person.age << '\n';

	return 0;
}
