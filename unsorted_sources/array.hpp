#pragma once

#include <algorithm>

template <class Type,
		class SizeT = size_t,
		class CRet = Type>
struct Array
{
private:
	Type *data_;
	SizeT size_;
	mutable SizeT counter_;

public:
	explicit Array(SizeT size)
			: data_(new Type[size]), size_(size) {
		for (SizeT i = 0; i != size_; ++i)
			data_[i] = 0;
	}

	Array(Array const &a)
			: data_(new Type[size_]), size_(a.size_) {
		for (SizeT i = 0; i != size_; ++i)
			data_[i] = a.data_[i];
	}

	Array &operator=(Array const &a) {
		if (this != &a) {
			// Equal code
			// delete [] data_;
			// size_ = a.size_;
			// data_ = new int [size_];
			// for (size_t i = 0; i != size_; ++i)
			// data_[i] = a.data_[i];
			Array(a).swap(*this);
		}
		return *this;
	}

	~Array() { delete[] data_; }

	void swap(Array &a) {
		std::swap(size_, a.size_);
		std::swap(data_, a.data_);
	}

	Type get(SizeT i) const {
		return data_[i];
	}

	Type &get(SizeT i) {
		return data_[i];
	}

	SizeT size() const {
		++counter_;
		return size_;
	}

	void resize(SizeT nsize) {
		Array t(nsize);
		SizeT n = nsize > size_ ? size_ : nsize;
		for (SizeT i = 0; i != n; ++i)
			t.data_[i] = data_[i];
		swap(t);
	}

	CRet operator[](SizeT i) const { return data_[i]; }

	Type &operator[](SizeT i) { return data_[i]; }
};
