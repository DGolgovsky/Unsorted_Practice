#include <Windows.h>
#include <time.h>
#include<iostream>
#include<string.h>
using namespace std;
class Transport{
    char  NameTrans[30], skorost[30];
public:
    Transport();//конструктор безпараметра
    Transport(char *NameTr,char *skor);//конструкор с двумя параметрами
    void Print();
    ~Transport();
    char *Get_NameTrans();
    char *Get_skorost();
    Transport &operator=(const Transport &B);
};
template<class T>
class List{
    T Object;
    List<T> *next = NULL;
    List<T> *first = NULL;
    List<T> *Get_last();
    int Size;
public:
    List();
    List(T *B, int n);
    List(const List<T> &B);
    void Input(T object);
    void Print();
    T operator[](int i);
    List<T> operator+(List<T> B);
    bool operator==(List<T> B);
    List<T> &operator=(const List<T> &B);
    ~List();
};
 
template<class T>
List<T> *List<T>::Get_last() {
    if (first) {
        List<T> *cur = first;
        while (cur->next) cur = cur->next;
        return cur;
    }
    else return NULL;
}
 
template<class T>
List<T>::List() {
    Object = NULL;
    next = NULL;
    first = NULL;
    Size = 0;
}
List<Transport>::List() {
    Transport Object;
    next = NULL;
    first = NULL;
    Size = 0;
}
template<class T>
List<T>::List(T *B, int n) {
    List<T> *cur;
    for (int i = 0; i < n; i++) {
        List<T> *Add = new List<T>;
        Add->Object = B[i];
        Add->next = 0;
        if (first) {
            cur->next = Add;
            cur = cur->next;
        }
        else {
            first = Add;
            cur = first;
        }
    }
    Size = n;
}
template<class T>
List<T>::List(const List<T> &B) {
    List<T> *cur2 = B.first;
    List<T> *cur = first;
    for (int i = 0; i < B.Size; i++) {
        List<T> *Add = new List<T>;
        Add->Object = cur2->Object;
        Add->next = 0;
        if (first) {
            cur->next = Add;
            cur = cur->next;
        }
        else {
            first = Add;
            cur = first;
        }
        cur2 = cur2->next;
    }
    Size = B.Size;
}
 
template<class T>
void List<T>::Input(T object) {
    List<T> *Add = new List<T>;
    List<T> *last = Get_last();
    Add->next = 0;
    Add->Object = object;
    Size++;
    if (last) last->next = Add;
    else first = Add;
}
 
template<class T>
void List<T>::Print() {
    if (first) {
        List<T> *cur = first;
        while (cur) {
            cout << cur->Object << " ";
            cur = cur->next;
        }
    }
    else cout << "Список пуст";
    cout << endl << "-----------------------" << endl;
}
void List<Transport>::Print() {
    List<Transport> *cur = first;
    if (first) {
        while (cur) {
            cout << "Название транспорта: " << cur->Object.Get_NameTrans() << " Скорость: " << cur->Object.Get_skorost() << endl;
            cur = cur->next;
        }
    }
    else cout << "Список пуст";
    cout << endl << "-----------------------" << endl;
}
 
template<class T>
T List<T>::operator[](int i) {
    if (i > 0 && i <= Size) {
        List<T> *cur = first;
        int pos = 1;
        while (i != pos) {
            cur = cur->next;
            pos++;
        }
        return cur->Object;
    }
    else throw 1;
}
 
template<class T>
List<T> List<T>::operator+(List<T> B) {
    List<T> Temp;
    List<T> *cur = Temp.first;
    List<T> *cur1 = first;
    List<T> *cur2 = B.first;
    for (int i = 0; i < Size; i++) {
        List<T> *Add = new List<T>;
        Add->Object = cur1->Object;
        Add->next = 0;
        if (Temp.first) {
            cur->next = Add;
            cur = cur->next;
        }
        else {
            Temp.first = Add;
            cur = Temp.first;
        }
        cur1 = cur1->next;
    }
    for (int i = 0; i < B.Size; i++) {
        List<T> *Add = new List<T>;
        Add->Object = cur2->Object;
        Add->next = 0;
        if (Temp.first) {
            cur->next = Add;
            cur = cur->next;
        }
        else {
            Temp.first = Add;
            cur = Temp.first;
        }
        cur2 = cur2->next;
    }
    Temp.Size = Size + B.Size;
    return Temp;
}
template<class T>
List<T> &List<T>::operator=(const List<T> &B) {
    List<T> Temp;
    List<T> *cur1 = B.first;
    List<T> *cur = first;
    if (this != &B) {
        if (Size) {
            List<T> *del = first;
            while (del) {
                first = first->next;
                delete del;
                del = first;
            }
        }
        for (int i = 0; i < B.Size; i++) {
            List<T> *Add = new List<T>;
            Add->Object = cur1->Object;
            Add->next = 0;
            if (first) {
                cur->next = Add;
                cur = cur->next;
            }
            else {
                first = Add;
                cur = first;
            }
            cur1 = cur1->next;
        }
        Size = B.Size;
    }
    return *this;
}
 
template<class T>
bool List<T>::operator==(List<T> B) {
    List<T> *cur1 = first;
    List<T> *cur2 = B.first;
    if (Size == B.Size) {
        while (cur1 && cur2) {
            if (cur1->Object != cur2->Object) return false;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
    }
    else return false;
    return true;
}
 
bool List<Transport>::operator==(List<Transport> B) {
    List<Transport> *cur1 = first;
    List<Transport> *cur2 = B.first;
    if (Size == B.Size) {
        while (cur1 && cur2) {
            if (strcmp(cur1->Object.Get_NameTrans(), cur2->Object.Get_NameTrans()) || strcmp(cur1->Object.Get_skorost(),cur2->Object.Get_skorost())) return false;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
    }
    else return false;
    return true;
}
template<class T>
List<T>::~List() {
    List<T> *del = first;
    while (del) {
        first = first->next;
        delete del;
        del = first;
    }
}
Transport::Transport(){
    NameTrans[0] = '\0';
    skorost[0] = '\0';
}
Transport::Transport(char *NameTr, char *skor){
        strcpy(NameTrans, NameTr);
        strcpy(skorost, skor);
}
 
void Transport::Print(){
    if (strlen(NameTrans) && strlen(skorost)){
        cout << "Название транспорта: " << NameTrans << endl;
        cout << "Скорость: " << skorost << endl;
    }
    else throw 1;
}
 
Transport::~Transport(){
}
 
char *Transport::Get_NameTrans(){
    return NameTrans;
}
char *Transport::Get_skorost(){
    return skorost;
}
 
Transport &Transport::operator=(const Transport &B){
    if (this != &B){
        strcpy(NameTrans, B.NameTrans);
        strcpy(skorost, B.skorost);
    }
    return *this;
}
int main() {
    srand(time(0));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n, random;
    char NameTrans[100], skorost[100];
    List<int> A;
    List<int> B;
    cout << "Введите размерность списка 1: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        random = rand() % 100 - 50;
        A.Input(random);
    }
    cout << "Введите размерность списка 2: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        random = rand() % 100 - 50;
        B.Input(random);
    }
    system("cls");
    A.Print();
    B.Print();
    List<int> C = A + B;
    C.Print();
    if (A == B) cout << "Списки равны" << endl;
    else cout << "Списки не равны" << endl;
    cout << "Введите элемент списка А, который нужно вывести: ";
    cin >> n;
    try {
        cout << A[n] << endl;
    }
    catch (int)
    {
        cout << "Элемента с данным индексом не существует" << endl;
    }
    cout << "Введите элемент списка B, который нужно вывести: ";
    cin >> n;
    try {
        cout << B[n] << endl;
    }
    catch (int)
    {
        cout << "Элемента с данным индексом не существует" << endl;
    }
    system("pause");
    system("cls");
    cout << "Переход к пользовательскому типу" << endl;
    List<Transport> A1;
    List<Transport> A2;
    cout << "Введите размерность списка 1: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Введите название государства: ";
        cin >> NameTrans;
        cout << "Введите название дату основания: ";
        cin >> skorost;
        Transport Gos(NameTrans, skorost);
        A1.Input(Gos);
    }
    cout << "Введите размерность списка 2: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Введите название транспорта: ";
        cin >> NameTrans;
        cout << "Введите скорость: ";
        cin >> skorost;
        Transport Gos(NameTrans, skorost);
        A2.Input(Gos);
    }
    A1.Print();
    A2.Print();
    List<Transport> A3 = A1 + A2;
    A3.Print();
    cout << "Введите элемент списка 1, который нужно вывести: ";
    cin >> n;
    try {
        A1[n].Print();
    }
    catch (int)
    {
        cout << "Элемента с данным индексом не существует" << endl;
    }
    cout << "Введите элемент списка 2 компл. чисел, который нужно вывести: ";
    cin >> n;
    try {
        A2[n].Print();
    }
    catch (int)
    {
        cout << "Элемента с данным индексом не существует" << endl;
    }
    if (A1 == A2) cout << "Списки равны" << endl;
    else cout << "Списки не равны" << endl;
    system("pause>>void");
}
