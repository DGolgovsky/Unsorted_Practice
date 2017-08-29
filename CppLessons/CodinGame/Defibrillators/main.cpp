#include <iostream>
#include <string>
#include <vector>

#include "Point.h"
#include "Defibrillator.h"

int main() {
	string user_long, user_lat;

	// Get the user location
	getline(std::cin, user_long);
	getline(std::cin, user_lat);
	Point user(user_long, user_lat);

	// Get the numbers of Defibrillators
	string N_str;
	getline(std::cin, N_str);
	unsigned int N = std::stoi(N_str);

	std::vector<Defibrillator*> list_def;
	for (size_t i = 0; i < N; ++i) {
		string description;
		getline(std::cin, description);
		list_def.push_back (new Defibrillator(description));
	}

	// Find the nearest defibrillator and store its address
	double min = -1.0;
	string ret_addr;
	for (size_t i = 0; i < N; ++i) {
		double dist = Point::distance(user, list_def[i]->get_location());
		if ((min == -1) or (dist < min)) {
			min = dist;
			ret_addr = list_def[i]->get_name();
		}
		delete list_def[i];
	}

	std::cout << ret_addr << std::endl;

	return 0;
}
