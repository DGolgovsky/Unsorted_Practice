#include <iostream>
void logic(bool X, bool Y, bool Z)
{
	bool r = (X^Y^Z)^(X&&Y&&Z);
	std::cout << X << " "
		  << Y << " "
		  << Z << " >> " << r << "\n";
}
int main()
{
	logic(0, 0, 1);
	logic(0, 1, 0);
	logic(1, 0, 0);
	logic(0, 0, 0);
	logic(0, 1, 1);
	logic(1, 0, 1);
	logic(1, 1, 0);
	logic(1, 1, 1);
	return 0;
}
