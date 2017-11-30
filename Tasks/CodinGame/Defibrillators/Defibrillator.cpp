#include "Defibrillator.h"
#include <vector>
#include <sstream>
#include <string>

using std::string;

Defibrillator::Defibrillator(string description)
{
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

string Defibrillator::get_name() const
{
    return name;
}

string Defibrillator::get_address() const
{
    return address;
}

string Defibrillator::get_phone() const
{
    return phone;
}

Point Defibrillator::get_location() const
{
    return location;
}

unsigned Defibrillator::ID = 0;
