#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>

using std::string;

class Point
{
private:
	double longitude;
	double latitude;
public:
	Point() {
		latitude = longitude = 0;
	}
	Point(string p_long, string p_lat) {
		// Replace ',' by '.' to match floats
		int pos = p_lat.find(',');
		p_lat[pos] = '.';
		pos = p_long.find(',');
		p_long[pos] = '.';
		// Convert strings to double
		latitude = std::stod(p_lat);
		longitude = std::stod(p_long);
	}
	double get_longitude() const {
		return longitude;
	}
	double get_latitude() const {
		return latitude;
	}

	static double distance(const Point& a, const Point& b);
};

double Point::distance(const Point& a, const Point& b) {
	double x = (b.longitude - a.longitude)
			   * cos((a.latitude + b.latitude) / 2);
	double y = b.latitude - a.latitude;
	return (sqrt(pow(x,2) + pow(y,2)) * 6371);
}

class Defibrillator
{
private:
	static unsigned ID;
	string name;
	string address;
	string phone;
	Point location;
public:
	Defibrillator(string description) {
		ID++;
		/* Parse the ';' separated string 'description' into
		 * a vector of fields
		 */
		std::vector<string> fields;
		string field;
		std::stringstream ss(description);
		while (getline(ss, field, ';')) {
			fields.push_back(field);
		}
		name = fields[1];
		address = fields[2];
		phone = fields[3];
		string longitude = fields[4];
		string latitude = fields[5];
		location = Point(longitude, latitude);
	}

	string get_name() const {
		return name;
	}
	string get_address() const {
		return address;
	}
	string get_phone() const {
		return phone;
	}
	Point get_location() const {
		return location;
	}
};

unsigned Defibrillator::ID = 0;

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
