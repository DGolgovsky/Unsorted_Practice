#include <iostream>

class customer
{
private:
	friend class get_customer_data;

	std::string name;
public:
	customer(std::string name) {
		this->name = name;
	}
};

class get_customer_data
{
public:
	static std::string get_name(customer &_customer) {
		return _customer.name;
	}
};

int main() {
	customer Tom("Tom");
	get_customer_data getName;

	std::cout << "Name: " <<
			  getName.get_name(Tom) << '\n';

	return 0;
}

