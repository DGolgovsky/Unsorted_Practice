#include <cstddef>

template <typename T>
class Array
{
public:
    explicit Array(size_t size = 0, const T& value = T())
        : data_(new T[size])
        , size_(size) {
        for(int i = 0; i != size; ++i)
            data_[i] = value;
    }

    Array(const Array &a)
		: data_(new T[size_])
		, size_(a.size()) {
		for (int i = 0; i != size_; ++i)
			data_[i] = a.data_[i];
	}

    ~Array() { delete [] data_; }

    Array& operator=(const Array & a) {
		if (this != &a) {
            delete [] data_;
			size_ = a.size();
			data_ = new T[size_];
			for (int i = 0; i != size_; ++i)
			data_[i] = a.data_[i];
        }
		return *this;
	}

    size_t size() const { return size_; }

    //   две версии оператора доступа по индексу.
    T& operator[](size_t i) { return data_[i]; }
    const T& operator[](size_t i) const { return data_[i]; }
private:
    size_t    size_;
    T *       data_;
};
