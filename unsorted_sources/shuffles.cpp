#include <iostream>
#include <vector>

template <typename T>
std::vector <T> shuffle(std::vector < T >
const &array)
{
size_t half = array.size() / 2;
std::vector <T> tmp_array(array.size());
for (
size_t i = 0;
i<half;
++i) {
tmp_array[i*2] = array[i+half];
tmp_array[i*2+1] = array[i];
}
return
tmp_array;
}

int main() {
	std::vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::cout << "Original:\n";
	for (auto const &it : array)
		std::cout << it << " ";

	array = shuffle(array);

	std::cout << "\nConverted:\n";
	for (auto const &it : array)
		std::cout << it << " ";

	std::cout << std::endl;

	return 0;
}
