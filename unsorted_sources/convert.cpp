#include <iostream>

int convert(int a) {
  if (a < 0)
    a = ( ~a|128 ) + 1;
  return a;
}

int main()
{
	int a;
	std::cin >> a;
	std::cout << "Conv: " << convert(a) << "\n";
	return 0;
}

