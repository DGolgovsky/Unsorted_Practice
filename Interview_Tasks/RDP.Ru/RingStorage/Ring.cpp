/*
 * Предлагается реализовать (письменно) ring со следующими ограничениями.
 * 1. Ring имеет максимальный размер, задаваемый в конструкторе, и не может его превышать.
 * (Попытка добавления при полностью заполненном ring завершается неудачно, не перетирая
 * существующие элементы). Таким образом, это FIFO queue с органичением длины.
 * 2. Для простоты ring хранит данные типа int
 * 3. Функция Add используется для добавления элемента в ring.
 * Если удачно, то возвращает true, неудачно - false.
 * 4. Функция Take используется для того, чтобы забрать элемент из ring.
 * Если удачно, то возвращает true, неудачно - false.
 *
 * Ограничения:
 * A) Аллокация памяти возможна только в конструкторе.
 * Деаллокация памяти, соответсвенно, только в деструкторе
 * Add() и Take() (а также функции, которые они вызывают) не должны её производить
 *
 * B) После того, как Add() успешно положит int в ring, и до того,
 * как Take() заберёт int из ring, этот int не должен перемещаться по памяти.
 *
 * C) Имплементацию делаем ручками, встроенными средствами языка,
 * без использования библиотечных функций (операторы new и delete,
 * в том числе и для массивов считаем встроенными средствами языка).
 * Если вы будете использовать какую-нибудь библиотечную функцию,
 * то вам нужно будет также написать реализацию её и функций,
 * которые она вызывает, пока условие, что делаем,
 * встроенными средствами языка не выполнится.
*/

template <class T = int>
class Ring
{
private:
    long int size_;
    long int start_index_;
    long int end_index_;
    T * start_p_;

public:
    Ring(long int size);
    ~Ring();

    bool isEmpty() const;
    bool isFull() const;

    bool Add(const T &data);
    T Take();
};

template <class T>
Ring<T>::Ring(long int size)
    : size_(size)
    , start_index_(-1)
    , end_index_(-1)
    , start_p_(new T[size])
{ }

template <class T> Ring<T>::~Ring()
{
    delete[] start_p_;
}

template <class T> bool Ring<T>::isEmpty() const
{
    return start_index_ == -1;
}

template <class T> bool Ring<T>::isFull() const
{
    if ((end_index_ + 1 == start_index_) ||
        (start_index_ == 0 && end_index_ == size_ - 1))
        return true;
    else
        return false;
}

template <class T> bool Ring<T>::Add(const T &data)
{
    if (isFull()) {
        return false;
    } else if (isEmpty()) {
        start_index_ = 0;
        end_index_ = 0;
        start_p_[end_index_] = data;
    } else if (end_index_ != size_ - 1)
    {
        start_p_[++end_index_] = data;
    } else {
        end_index_ = 0;
        start_p_[end_index_] = data;
    }
    return true;
}

// Correction.
// Ring<T>::Take returns value, not `true`
template <class T> T Ring<T>::Take()
{
    if (isEmpty()) {
        return false;
    } else if (start_index_ == end_index_) {
        T temp = start_p_[end_index_];
        start_index_ = -1;
        end_index_ = -1;
        return temp;
    } else if (start_index_ == size_ - 1) {
        start_index_ = 0;
        return start_p_[size_ - 1];
    } else {
        return start_p_[start_index_++];
    }
}
