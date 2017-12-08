#pragma once
#include <string>
#include <sstream>
#include <set>
#include <list>

namespace cracker {
std::string crack(unsigned int N, std::string &&passwds, std::string &&login_attempts);
}
