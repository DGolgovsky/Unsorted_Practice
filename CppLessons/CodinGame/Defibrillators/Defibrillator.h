#pragma once
#include <string>
#include "Point.h"

using std::string;

class Defibrillator
{
private:
	static unsigned ID;
	string name;
	string address;
	string phone;
	Point location;
public:
	Defibrillator(string description);

	string get_name() const;
        string get_address() const;
	string get_phone() const;
	Point get_location() const;
};
