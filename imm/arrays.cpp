#include <cstddef>

using namespace std;

template <class Type,
		  class SizeT = size_t,
		  class CRet = Type>
struct Array {
	explicit Array(SizeT size)
		: data_(new Type[size])
		, size_(size) {}

	~Array() { delete [] data_; }

	SizeT size() const { return size_; }
	CRet operator[](SizeT i) const { return data_[i]; }
	Type & operator[](SizeT i) { return data_[i]; }

private:
	Type *	data_;
	SizeT	size_;
};

void foo ()
{
	Array<int> ai(10);
	Array<float> af(20);
	Array<Array<int>,
		  size_t,
		  Array<int> const&>
		da(30);
}

typedef Array<int> Ints;
typedef Array<Ints, size_t, Ints const&> IInts;

void bar()
{
	IInts da(30);
}

int main()
{
	return 0;
}
