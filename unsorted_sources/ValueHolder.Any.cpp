/**
 * TODO
 * 1. в операторе присваивания проверку на самого себя
 * 2. в T* cast() проверку ptr на NULL перед dynamic_cast
 */

#include <iostream>
#include <typeinfo>

using namespace std;

struct ICloneable {
    virtual ICloneable *clone() const = 0;

    virtual ~ICloneable() {}
};

template<typename T>
struct ValueHolder : ICloneable {
    ValueHolder(const T &data) : data_(data) {}

    T data_;

    ValueHolder *clone() const {
        return new ValueHolder(*this);
    }
};

class Any {
private:
    ICloneable *ptr;

public:
    Any() : ptr(0) {}

    template<class V>
    Any(const V &v) : ptr(new ValueHolder<V>(v)) {}

    Any(Any const &other) : ptr(other.ptr ? other.ptr->clone() : 0) {}

    Any &operator=(Any const &other) {
        if (this != &other) {
            delete ptr;
            ptr = 0;
            if (other.ptr)
                ptr = other.ptr->clone();
        }
        return *this;
    }

    template<class A>
    Any &operator=(A const &other) {
        delete ptr;
        ptr = 0;
        ptr = new ValueHolder<A>(other);
        return *this;
    }

    ~Any() { delete ptr; }

    template<class T>
    T *cast() {
        if (ptr != 0) {
            ValueHolder<T> *vh = dynamic_cast<ValueHolder<T> *>(ptr);
            if (!vh)
                return 0;
            return &(vh->data_);
        }
    }
};
