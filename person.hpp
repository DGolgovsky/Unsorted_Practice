#pragma once
#include <cstring>
using std::string;

struct Person
{
	Person(string name, int age)
		: name_(name), age_(age)
	{}

	string name() const {
		return name_;
	}
	int age() const {
		return age_;
	}
private:
	string name_;
	int age_;
};

