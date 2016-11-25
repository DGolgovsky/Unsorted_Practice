#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[])
{
    char symbol = 'd';
    char digit = '9';
    char space = ' ';
    char character = '#';

    // функция isalnum() проверяет является ли её аргумент буквой или цифрой
    cout << symbol    << " - it is digit or alpha?: ";
    isalnum(symbol)    ? cout << "true\n": cout << "false\n";
    // функция isalpha() проверяет является ли её аргумент буквой
    cout << symbol    << " - it is alpha?:          ";
    isalpha(symbol)    ? cout << "true\n": cout << "false\n";
    // функция isdigit() проверяет является ли её аргумент цифрой
    cout << digit     << " - it is digit?:          ";
    isdigit(digit)     ? cout << "true\n": cout << "false\n";
    // функция isspace() проверяет является ли её аргумент пробелом
    cout << space     << " - it is space?:          ";
    isspace(space)     ? cout << "true\n": cout << "false\n";
    // функция islower() проверяет является ли её аргумент буквой нижнего регистра
    cout << symbol    << " - it is lower alpha?:    ";
    islower(symbol)    ? cout << "true\n": cout << "false\n";
    // функция isupper() проверяет является ли её аргумент буквой верхнего регистра
    cout << symbol    << " - it is upper alpha?:    ";
    isupper(symbol) ? cout << "true\n": cout << "false\n";

    return 0;
}

