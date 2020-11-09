#include <iostream>
#include <vector>

using namespace std;

vector<int>::const_iterator binarySearch(const vector<int> &container, int element) {
	const vector<int>::const_iterator endIt = end(container);

	vector<int>::const_iterator left = begin(container);
	vector<int>::const_iterator right = endIt;

	if (container.size() == 0
		|| container.front() > element
		|| container.back() < element) {
		return endIt;
	}

	while (distance(left, right) > 0) {
		const vector<int>::const_iterator mid = left + distance(left, right) / 2;

		if (element <= *mid) {
			right = mid;
		} else {
			left = mid + 1;
		}
	}

	if (*right == element) {
		return right;
	}

	return endIt;
}

//! \brief A recursive binary search using STL vectors
//! \param vec The vector whose elements are to be searched
//! \param start The index of the first element in the vector
//! \param end The index of the last element in the vector
//! \param key The value being searched for
//! \return The index into the vector where the value is located,
//! or -1 if the value could not be found.
template<typename T>
int binary_search(const std::vector<T>& vec, int start, int end, const T& key)
{
    // Termination condition: start index greater than end index
    if(start > end)
    {
        return -1;
    }

    // Find the middle element of the vector and use that for splitting
    // the array into two pieces.
    const int middle = start + ((end - start) / 2);

    if(vec[middle] == key)
    {
        return middle;
    }
    else if(vec[middle] > key)
    {
        return binary_search(vec, start, middle - 1, key);
    }

    return binary_search(vec, middle + 1, end, key);
}
//! \brief A helper function for the binary search
template<typename T>
int search(const vector<T>& vec, const T& key)
{
    return binary_search(vec, 0, vec.size()-1, key);
}


int main() {
	const vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // отсортированный контейнер
	const int element = 8; // искомый элемент

	auto foundIt = binarySearch(vec, element);
	if (foundIt != vec.end()) {
		cout << *foundIt << endl;
	}
	
	
	// Use our binary search algorithm to find an element
    int search_vals[] = {1, 5, 19, 21, 92, 43, 103};
    int expected_vals[] = {0, 1, -1, 4, 6, 5, -1};

    for(unsigned i = 0; i < 7; i++)
    {
        assert(expected_vals[i] == search(vec, search_vals[i]));
    }
	
	return 0;
}
