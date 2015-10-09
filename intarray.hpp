#pragma once
#include <algorithm>

struct IntArray
{
public:
	explicit IntArray(size_t size)
		: size_(size), data_(new int[size]) {
		for (size_t i = 0; i != size_; ++i)
			data_[i] = 0;
	}
	IntArray(IntArray const& a)
		: size_(a.size_), data_(new int[size_]) {
		for (size_t i = 0; i != size_; ++i)
			data_[i] = a.data_[i];
	}
	IntArray & operator=(IntArray const& a) {
		if (this != &a) {
			/* Equal code
			 * delete [] data_;
			 * size_ = a.size_;
			 * data_ = new int [size_];
			 * for (size_t i = 0; i != size_; ++i)
			 * data_[i] = a.data_[i];*/
			IntArray(a).swap(*this);
		}
		return *this;
	}
	~IntArray() {
		delete [] data_;
	}
	void swap(IntArray &a);

	int get(size_t i) const {
		return data_[i];
	}

	int & get(size_t i) {
		return data_[i];
	}

	size_t size() const {
		++counter_;
		return size_;
	}

	void resize(size_t nsize);

private:
	size_t size_;
	int * data_;
	mutable size_t counter_;
};
