#include <iostream>
#include <cstddef>

//TODO
template <class type>
struct Array
{
	explicit Array(size_t size)
			: size_(size), data_(new type[size_]) {}

	~Array() {
		delete[] data_;
	}

	type operator[](size_t i) {
		return data_[i];
	}
	/* ... */
private:
	size_t size_;
	type *data_;
};

template <>
struct Array<bool>
{
	static int const INTBITS = 8 * sizeof(int);

	explicit Array(size_t size)
			: size_(size), data_(new int[size_ / INTBITS + 1]) {}

	~Array() {
		delete[] data_;
	}

	bool operator[](size_t i) const {
		return data_[i / INTBITS] & (1 << (i % INTBITS));
	}

private:
	size_t size_;
	int *data_;
};

int main() {
	Array<bool> arb(10);
//	for (int i = 0; i != 10; ++i)
//		arb[i] = i % 2;
	std::cout << "Type sizes (b):" << "\n";
	std::cout << "int    = " << sizeof(int) << "\n";
	std::cout << "double = " << sizeof(double) << "\n";
	std::cout << "float  = " << sizeof(float) << "\n";

	for (int i = 0; i != 10; ++i)
		std::cout << "Array[" << i << "] = " << arb[i] << "\n";
	std::cout << "Size Array[] = " << sizeof(arb) << "\n";
	return 0;
}

