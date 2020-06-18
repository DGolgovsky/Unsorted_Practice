/*
 * main.cpp
 *
 * Copyright 2015 D. Golgovsky <d.westcoast@aol.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */
#include <iostream>
#include "segment.hpp"
#include "array.hpp"
#include "string.hpp"
#include "person.hpp"

using std::cout;
using std::endl;

typedef Array<int> Ints;
typedef Array<Ints, size_t, Ints const &> IInts;

int main(int argc, char **argv) {
	Segment s(Point(0.4, 1.4), Point(1.2, 6.3));
	Segment s2(10); // (0,0),(10,0)

	Array<int> ai(10); // array of int
	Array<float> af(20); // array of float
	IInts da(30);

	String string_("First");
	string_.append(String("_added"));

	cout << "Before shift: " << s.length();
	s.p1.shift(0.1, 0.2);
	cout << "\nAfter shift: " << s.length()
		 << "\nString: " << string_.str
		 << endl;

	Student stud("John Doe", 20, "MIT");
	/* Person now is abstract class
	Person & l = stud;		// Student & -> Person &
	Person * r = &stud;		// Student * -> Person *
	Person p = stud;		// Person("John Doe", 20);
	*/

	cout << "\nStudent info:\n> Name: " << stud.name()
		 << "\n> Age: " << stud.age()
		 << "\n> Uni: " << stud.university()
		 << endl;

	String greet("Hello");
	char ch1 = greet.at(0);
	cout << ch1 << endl;

	String const const_greet("Const, Hello!");
	char const &ch2 = const_greet.at(0);
	cout << ch2 << endl;

	Professor p("Stroustrup", 63, "C++", "The C++ language");

	return 0;
}
