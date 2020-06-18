/*
 * An instance of std::exception_ptr holding a reference to the exception object,
 * or a copy of the exception object,
 * or to an instance of std::bad_alloc or to an instance of std::bad_exception.
 */

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

void handle_eptr(std::exception_ptr eptr) // passing by value is ok
{
	try {
		if (eptr) {
			std::rethrow_exception(eptr);
		}
	} catch (const std::exception &e) {
		std::cout << "Caught exception \"" << e.what() << "\"\n";
	}
}

int main() {
	std::exception_ptr eptr;

	try {
		std::string().at(1); // this generates an std::out_of_range
	} catch (...) {
		eptr = std::current_exception(); // capture
	}

	handle_eptr(eptr);

	return 0;
} // destructor for std::out_of_range called here, when the eptr is destructed

