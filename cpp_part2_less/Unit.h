#ifndef UNIT_H
#define UNIT_H

#include <iostream>

struct Unit  
{
public:
    explicit Unit(size_t id) 
        : id_(id) {
	std::cout << "Unit created. ID: "
              << id << '\n';
	}

    size_t id() const { return id_; }

private:
    size_t id_;
};

#endif
