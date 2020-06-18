/*
 * есть список numbers из десяти элементов, которые мы заполняем
 * случайным образом в диапазоне от 0 до 100. Мы хотим найти элемент
 * списка, который больше или равен 50.
 */

#include <iostream>
#include <list>
#include <functional>
#include <algorithm>

using namespace std;

int main(void) {
	list<int> numbers;

	for (int i = 0; i < 10; ++i)
		numbers.push_back(rand() % 100);

	list<int>::iterator ptr;

	for (ptr = numbers.begin(); ptr != numbers.end(); ++ptr)
		cout << *ptr << " ";
	cout << endl;

	ptr = find_if(numbers.begin(), numbers.end(),
				  bind2nd(greater_equal<int>(), 50));

	if (ptr == numbers.end())
		cout << "not found" << endl;
	else
		cout << *ptr << " found" << endl;

	return 0;
}
