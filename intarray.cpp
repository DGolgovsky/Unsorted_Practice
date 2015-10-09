#include "intarray.hpp"

void IntArray::resize(size_t nsize)
{
	/* Old realization
	 * int * ndata = new int[nsize];
	 * size_t n = nsize > (unsigned)this->data_[0] ? this->data_[0] : nsize;
	 * for (size_t i = 0; i != n; ++i)
	 *     ndata[i] = data_[i];
	 * delete [] data_;
	 * data_ = ndata;
	 * this->data_[0] = nsize;*/
	 IntArray t (nsize);
	 size_t n = nsize > size_ ? size_ : nsize;
	 for (size_t i = 0; i != n; ++i)
		t.data_[i] = data_[i];
	swap(t);
}

void IntArray::swap(IntArray &a)
{
	std::swap(size_, a.size_);
	std::swap(data_, a.data_);
}
