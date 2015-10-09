#pragma once
#include "person.hpp"

class Student : public Person
{
public:
	Student(string name, int age, string uni)
		: Person(name, age), uni_(uni)
	{}

	string university() const {
		return uni_;
	}
private:
	string uni_;
};
