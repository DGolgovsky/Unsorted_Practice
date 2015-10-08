#pragma once
#include <algorithm>

class IntArray {
public:
	IntArray(IntArray const& a) : size_(a.size_), data_(new int[size_]) {
		for (size_t i = 0; i != size_; ++i)
			data_[i] = a.data_[i];
	}

	IntArray & operator=(IntArray const& a) {
		if (this != &a) {
			/*delete [] data_;
			size_ = a.size_;
			data_ = new int [size_];
			for (size_t i = 0; i != size_; ++i)
				data_[i] = a.data_[i];*/
			IntArray(a).swap(*this);
		}
		return *this;
	}

	explicit IntArray(size_t size)
		: size_(size), data_(new int[size])	{}

	~IntArray() {
		delete [] data_;
	}

	void swap(IntArray &a) {
		std::swap(size_, a.size_);
		std::swap(data_, a.data_);
	}

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
