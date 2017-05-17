#include <iostream>
#include <cmath>

using namespace std;

class Transport
{
private:
    string NameTrans;
    int skorost;
public:
    void set_NameTrans (string Name) {
        NameTrans = Name;
    }
    void set_skorost (int sk) {
        skorost = sk;
    }
    Transport (string NameTrans = "slomai_sebe_komp", int skorost = 13)
        : NameTrans(NameTrans)
        , skorost(skorost)
    { }
    /* friend ostream& operator<<(ostream& os, const Transport& v) {
        os << "(" << v.NameTrans << ", " << v.skorost << ")";
        return os;
    };*/
    /* friend istream& operator>>(istream& in, Transport& v) {
        cout << "NameTrans1: "; in >> v.NameTrans;
        cout << "skorost1: "; in >> v.skorost;
        return in;
    }*/
};

template <class T>
struct Element
{
    T val;
    Element<T>* next;
    Element() {
        next = NULL;
    }
};
 
template <class T>
class List
{
public:
    //конструктор без параметра
    List<T> () {
        p_first = NULL;
        p_last = NULL;
        size = 0;
    }
    //конструктор копирования
    List<T> (const List& old_list) {
        p_first = NULL;
        p_last = NULL;
        size = 0;
        Element<T> *p = old_list.p_first;
        while (p != NULL) {
            this->append(p->val);
            p = p->next;
        }
    };
    //функция размер
    size_t get_size() const { return size; }
    //деструктор
    ~List<T>() {
        Element<T>* temp;
        while (p_first != NULL) {
            temp = p_first;
            p_first = p_first->next;
            delete temp;// Удаление указателя
        }
    }
    //функция добавления
    void append(T& val) {
        if (p_first == NULL) {
            p_last = new Element<T>;
            p_first = p_last;
        } else {
            p_last->next = new Element<T>;
            p_last = p_last->next;
        }
        p_last->val = val;// Присваиваем новое значение
        size++;
    }
    //функция вывода  
    void show_all() {
        static Element<T> *temp_p; // Временный указатель
        temp_p = p_first;
        cout << "[";
        while (temp_p != NULL) {
            cout << temp_p->val << ", ";
            temp_p = temp_p->next;
        }
        cout << "]" << endl;
    }
    //перегрузка оператора <<
    friend std::ostream& operator<< (std::ostream& os, const List<T>& list) 
    {
        Element<T>* temp_p;
        temp_p = list.p_first;
        os << "[";
        while (temp_p != NULL) {
            os << temp_p->val << ", ";
            temp_p = temp_p->next;
        }
        os << "]";
        return os;
    }
    //перегрузка оператора >>
    friend std::istream& operator>> (std::istream &in, List<T>& list) {
        T temp;
        in >> temp;
        list.append(temp);
        return in;
    }
    List<T> &operator() (int i) { //Перегрузка операции удаление по номеру
        if (i > size) {
            cout << "Введённый индекс превышает размер списка!";
            return *this;
        }
        if (p_first == NULL) return *this;
        if (p_first == p_last) 
        {
            p_first = NULL;
            delete p_last;
            p_last = NULL;
            size = 0;
            return *this;
        }
        int ind=0; Element<T>* p;
        if (ind=i)
        {
            p = p_first->next;// 1 Запоминание удаляемого звена для операции delete
          p_first->next = p->next; // 2 Проведение новой связи в обход удаляемого звена
          delete p;
        }
        else {p_first = p_first->next; ind++;}
        --size;
        return *this;
    }
  List<T>& operator++ (T c,int i)//Перегрузка операции добавления по номеру  
    {
        if (size == 0) 
        {
            append(c);
            return;
        }
        Element<T>* p = new Element<T>;
         p->c = c;int ind=0;
        if (ind=i)
        {  
            p->next = p_first->next; // 3 Проведение связи от нового звена к следующему
           p_first->next = p;       // 4 Проведение связи от "старого" звена к новому
                       
        }
        else {p_first = p_first->next; ind++;}
         ++size;
          return *this;
    }
    bool operator!=(const List<T>& L) const {
        if (size != L.size)
            cout<<"Списки не равны!";
        if (size == L.size) {
 
            Element<T>* p1 = p_first;
            Element<T>* p2 = L.p_first;
            while (p1 != NULL) {
                if (p1->val != p2->val)
                    return false;
                p1 = p1->next;
                p2 = p2->next;
            }
            return true;
        }
        return false;
    }
 
private:
    Element<T>* p_first;
    Element<T>* p_last;
    size_t size;
};

int main ()
{
    List<Transport> L;
    //Transport(2, 5) + L; // Proverka 1 peregruzki
    cin >> L; // Zapolnim eshe
    cout << L << endl;
    List<Transport> L2 = L;
    cout << "(L != L2): " << (L != L2) << endl; // 3 peregruzka, doljno true
    //--L; // Proverka vtoroy
    cout << "(L != L2): " << (L != L2) << endl; // 3 peregruzka eshe raz, teper' false
    return 0;
}

