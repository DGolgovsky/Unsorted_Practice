#pragma once
#include "person.hpp"

struct Student : Person
{
	Student(string name, int age, string uni)
		: Person(name, age), uni_(uni)
	{}

	string university() const {
		return uni_;
	}
private:
	string uni_;
};
