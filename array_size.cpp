#include <cstddef> // size_t
#include <iostream>
using std::cout;
using std::endl;

template <typename type, size_t Len>

type array_size(type (&arr)[Len])
{
    /*for (size_t i = 0; i < Len; ++i)
        cout << " "[!i] << arr[i];
    cout << endl;*/
	return Len;
}

int main() {
	int ints[] = {1, 2, 3, 4};
	int *iptr = ints;
	double doubles[] = {3.14};
	
	int i = array_size(ints); // вернет 4
	double d = array_size(doubles); // вернет 1
	//array_size(iptr); // тут должна произойти ошибка компиляции

	std::cout << i <<", " << d << "\n";
return 0;
}
