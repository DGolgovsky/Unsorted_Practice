/*
Шаблонные классы можно наследовать. Реализуйте шаблонную структуру ValueHolder с одним типовым параметром T, унаследованную от интерфейса ICloneable. Интерфейс ICloneable содержит всего один виртуальный метод ICloneable* clone() const, который должен вернуть указатель на копию объекта, на котором он был вызван (объект должен быть создан в куче). Шаблон ValueHolder, как говорит его название, хранит всего одно значение (назовите его data_) типа T (для типа T определен конструктор копирования). Не делайте поле data_ закрытым (поэтому в данном случае мы явно пишем, что ValueHolder должна быть структурой).
*/

struct ICloneable
{
    virtual ICloneable* clone() const = 0;
    virtual ~ICloneable() { }
};

template <typename T>
struct ValueHolder : ICloneable {
    ValueHolder(const T& data): data_(data){}
    T data_;
    ValueHolder * clone() const {
        return new ValueHolder(*this);
    }
};

class Any
{
private:
    ICloneable * ptr;

public:
    Any() : ptr(0) { }
    template <class V>
    Any(const V& v) : ptr(new ValueHolder<V>(v)) { }
    Any(Any const & other) : ptr(other.ptr ? other.ptr->clone() : 0) {}
    Any& operator=(Any const & other)
    {
        delete ptr;
        ptr = 0;
        if (other.ptr)
        {
            ptr = other.ptr->clone();
        }
        return *this;
    }
    template <class A>
    Any& operator=(A const& other)
    {
        delete ptr;
        ptr = 0;
        ptr = new ValueHolder<A>(other);
        return *this;
    }
    ~Any() { delete ptr; }
    template <class T>
    T* cast()
    {
        ValueHolder<T> * vh = dynamic_cast<ValueHolder<T>*>(ptr);
        if (!vh)
            return 0;
        return &(vh->data_);
    }
};
