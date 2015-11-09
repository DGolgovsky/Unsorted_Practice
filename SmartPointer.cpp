template <class T>
class SmartPointer {
public:
    SmartPointer(T * ptr) {
        ref = ptr;
        ref_count = (unsigned*)malloc(sizeof(unsigned));
        *ref_count = 1;
    }
 
    SmartPointer(SmartPointer<T> & sptr) {
        ref = sptr.ref;
        ref_count = sptr.ref_count;
        ++(*ref_count);
    }
 
    /* Перезаписываем оператор равенства (equal), поэтому когда вы установите
     * один интеллектуальный указатель в другой, количество ссылок старого указателя
     * будет уменьшено, а нового - увеличено. 
     */
    SmartPointer<T> & operator=(SmartPointer<T> & sptr) {
        /* Если уже присвоено объекту, удаляем одну ссылку. */
        if (*ref_count > 0) {
            remove();
        }
        if (this != &sptr) {
            ref = sptr.ref;
            ref_count = sptr.ref_count;
            ++(*ref_count);
        }
        return *this;
    }
 
    ~SmartPointer() {
        remove(); // удаляем одну ссылку на объект.
    }
 
    T operator*() {
        return *ref;
    }
 
    protected:
    void remove() {
        --(*ref_count);
        if (ref_count == 0) {
            delete ref;
            free(ref_count);
            ref = NULL;
            ref_count = NULL;
        }
    }
 
    T * ref;
    unsigned * ref_count;
};

