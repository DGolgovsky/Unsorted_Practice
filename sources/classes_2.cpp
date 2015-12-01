// classes.cpp: определяет точку входа для консольного приложения.
 
//#include "stdafx.h"
#include <iostream>
using namespace std;
 
class CppStudio // имя класса
{
private: // спецификатор доступа private
    int day, // день
        month, // месяц
        year; // год
public: // спецификатор доступа public
    void message() // функция (метод класса) выводящая сообщение на экран
    {
        cout << "\nwebsite: cppstudio.comntheme: Classes and Objects in C + +\n";
    }
    void setDate(int date_day, int date_month, int date_year) // установка даты в формате дд.мм.гг
    {
        day   = date_day; // инициализация день
        month = date_month; // инициализация месяц
        year  = date_year; // инициализация год
    }
    void getDate() // отобразить текущую дату
    {
        cout << "Date: " << day << "." << month << "." << year << endl;
    }
}; // конец объявления класса CppStudio
 
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "rus"); // установка локали
    int day, month, year;
    cout << "Введите текущий день месяц и год!\n";
    cout << "день: ";     cin >> day;
    cout << "месяц: ";    cin >> month;
    cout << "год: ";  cin >> year;
    CppStudio objCppstudio; // объявление объекта
    objCppstudio.message(); // вызов функции класса message
    objCppstudio.setDate(day, month, year); // инициализация даты
    objCppstudio.getDate(); // отобразить дату    
    return 0;
}
