#include <iostream>
#include <cstddef>

template<typename T>
class Array {
private:
    size_t size_;
    T *data_;
public:
    explicit Array(size_t size = 0, const T &value = T())
            : data_(new T[size]), size_(size) {
        for (int i = 0; i != size; ++i)
            data_[i] = value;
    }

    Array(const Array &a)
            : data_(new T[size_]), size_(a.size()) {
        for (int i = 0; i != size_; ++i)
            data_[i] = a.data_[i];
    }

    ~Array() { delete[] data_; }

    Array &operator=(const Array &a) {
        if (this != &a) {
            delete[] data_;
            size_ = a.size();
            data_ = new T[size_];
            for (int i = 0; i != size_; ++i)
                data_[i] = a.data_[i];
        }
        return *this;
    }

    size_t size() const { return size_; }

    /* две версии оператора доступа по индексу. */
    T &operator[](size_t i) { return data_[i]; }

    const T &operator[](size_t i) const { return data_[i]; }


};

template<typename T>
void flatten(const Array<T> &array, std::ostream &out) {
    int sz = array.size();
    for (size_t i = 0; i != sz; ++i) {
        Array<int> tmp(sz);
        tmp = array[i];
        for (size_t j = 0; j != tmp.size(); ++j) {
            out << tmp[j] << " ";
        }
    }
    std::cout << "\n";
//	std::cout << "\n FIRST!" << sizeof(array) << "\n";
}

template<>
void flatten(const Array<int> &array, std::ostream &out) {
    for (size_t i = 0; i != array.size(); ++i) {
        out << array[i] << " ";
    }
    std::cout << "\n";
//	std::cout << "\n HERE!" << sizeof(array) << "\n";
}

template<>
void flatten(const Array<double> &array, std::ostream &out) {
    for (size_t i = 0; i != array.size(); ++i) {
        out << array[i] << " ";
    }
    std::cout << "\n";
//	std::cout << "\n HERE!" << sizeof(array) << "\n";
}

int main(void) {
    Array<int> ints(2, 0);
    ints[0] = 10;
    ints[1] = 20;
    flatten(ints, std::cout); // выводит на экран строку "10 20"
    Array<Array<int>> array_of_ints(2, ints);
    flatten(array_of_ints, std::cout); // выводит на экран строку "10 20 10 20"
    Array<double> doubles(10, 0.0);
    flatten(doubles, std::cout); // работать должно не только для типа int
    return 0;
}
