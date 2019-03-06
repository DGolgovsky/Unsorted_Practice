#include <limits>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <exception>
#include <stdexcept>
#include <map>
#include <cstring>
#include <new>

using namespace std;

#pragma warning(disable:4290) // Ошибка - аккаунт не существует

class account_not_exist : public logic_error {
public:
    account_not_exist()
            : logic_error("Аккаунт не существует") {};
};

// Валюты необходимые для задачи

enum currencies {
    RUR,
    USD,
    EUR
};

// Класс-деньги

class money {
public:
    // Конструкторы
    explicit money(double summa = 0.0, currencies currency = RUR) throw(invalid_argument);

    money(unsigned int int_part, unsigned char fract_part, currencies currency = RUR);

    // Тип валюты
    currencies getCurrency();

    void setCurrency(currencies currency);

private:
    // Целая часть суммы
    unsigned int _int_part;
    // Дробная часть суммы(копейки, центы и т.д.)
    unsigned char _fract_part;
    // Тип валюты
    currencies _currency;

    unsigned long long smallChange() const;

    friend money operator+(const money &left, const money &right);

    friend money operator-(const money &left, const money &right) throw(invalid_argument);

    friend money operator*(const money &left, double right);

    friend money operator*(double left, const money &right);

    friend bool operator<(const money &left, const money &right);

    friend bool operator&(const money &left, const money &right);

    friend wostream &operator<<(wostream &stream, const money &right);

    friend wistream &operator>>(wistream &stream, money &right);

    friend class exchanger;
};

// Обменник
class exchanger {
public:
    // Меняет одну валюту на другую
    static money exchange(const money &summa, currencies currency);

private:
    // Курсы обмена
    static map<currencies, double> _rates;
};

// Инициализируем статический член нашего обменного класса
typedef pair<currencies, double> rate_pair;
rate_pair rates_arr[3] = {rate_pair(RUR, 1.0), rate_pair(USD, 30.1851), rate_pair(EUR, 43.4605)};
map<currencies, double> exchanger::_rates(rates_arr, rates_arr + sizeof(rates_arr) / sizeof(rate_pair));

// Для вывода типа валюты будем использовать следующие имена
typedef pair <currencies, wstring> currency_name_pair;
currency_name_pair currencies_names_arr[3] = {currency_name_pair(RUR, L"RUR"), currency_name_pair(USD, L"USD"),
                                              currency_name_pair(EUR, L"EUR")};
map <currencies, wstring> currency_names(currencies_names_arr, currencies_names_arr + sizeof(currencies_names_arr) /
                                                                                      sizeof(currency_name_pair));

// Аккаунт
class account {
public:
    typedef unsigned int acc_num_type;

    // Конструктор
    account(const wstring &surname, acc_num_type account_num, double percent = 0.0,
            const money &cash = money(0.0)) throw(invalid_argument);

    // Меняет владельца
    void setOwner(const wstring &surname);

    // Возвращает владельца
    const wstring &getOwner() const;

    // Снимает деньги
    bool withdrawMoney(const money &summa);

    // Добавляет деньги
    void depositMoney(const money &summa);

    // Начисляет процент
    void thatInterest();

    // Обмен валюты
    void exchangeTo(currencies currency);

    // Сумма
    money getCash() const;

private:
    // Фамилия
    wstring _surname;
    // Номер счета
    acc_num_type _account_num;
    // Процент
    double _percent;
    // Сумма на счету
    money _cash;

    friend wostream &operator<<(wostream &stream, const account &right);
};

// Выбор пользователя в меню
enum user_choice {
    CREATE,
    CHANGE_OWNER,
    WITHDRAW_MONEY,
    DEPOSIT_MONEY,
    THAT_INTEREST,
    EXCHANGE_TO_RUR,
    EXCHANGE_TO_USD,
    EXCHANGE_TO_EUR,
    PRINT,
    EXIT
};

user_choice menu();

void createAccount(account *&);

void changeOwner(account *);

void withdrawMoney(account *);

void depositMoney(account *);

void thatInterest(account *);

void exchangeTo(account *, currencies);

void printAccount(account *);

// К сожалению в linux используя GCC(в отличие от VC++) не возможно комбинировать вывод с использованием
// cout и wcout попеременно. Тогда выводятся кракозябры. Эта функция - один из способов решения вопроса.
// P.S. Зато GCC позволяет использовать не константные значения для указания размера массива.
// Хоть это и не соответствует стандарту но приятно.:)
// Для совместимости сделал по стандарту. Вот так и приходится мудрить для переносимости.

wostream &operator<<(wostream &stream, const exception &right) {
#pragma warning(disable:4996)
    const size_t len = mbstowcs(0, right.what(), 0) + 1;
    try {
        wchar_t *buffer = new wchar_t[len];
        mbstowcs(buffer, right.what(), len);
        stream << buffer;
        delete[] buffer;
    }
    catch (bad_alloc &) {
    }
    return stream;
}

int main() {
    locale::global(locale(""));

    // Аккаунт
    account *acc = 0;
    bool is_exit = false;

    while (!is_exit) {
        try {
            switch (menu()) {
                case CREATE:
                    createAccount(acc);
                    break;
                case CHANGE_OWNER:
                    changeOwner(acc);
                    break;
                case WITHDRAW_MONEY:
                    withdrawMoney(acc);
                    break;
                case DEPOSIT_MONEY:
                    depositMoney(acc);
                    break;
                case THAT_INTEREST:
                    thatInterest(acc);
                    break;
                case EXCHANGE_TO_RUR:
                    exchangeTo(acc, RUR);
                    break;
                case EXCHANGE_TO_USD:
                    exchangeTo(acc, USD);
                    break;
                case EXCHANGE_TO_EUR:
                    exchangeTo(acc, EUR);
                    break;
                case PRINT:
                    printAccount(acc);
                    break;
                case EXIT:
                    is_exit = true;
                    break;
            }
        }
        catch (exception &ex) {
            wcout << ex << endl;
        }
    }

    if (acc) {
        delete acc;
        acc = 0;
        wcout << L"Счет уничтожен" << endl;
    }

    return 0;
}

wostream &line(wostream &stream) {
    stream << L"----------------------------------------------" << endl;
    return stream;
}

//Меню

user_choice menu() {
    while (true) {
        wcout << line
              << L"Меню:" << endl
              << L"1 - Создать счет" << endl
              << L"2 - Сменить владельца" << endl
              << L"3 - Снять деньги" << endl
              << L"4 - Положить деньги:" << endl
              << L"5 - Начислить процент" << endl
              << L"6 - Обменять на RUR" << endl
              << L"7 - Обменять на USD" << endl
              << L"8 - Обменять на EUR" << endl
              << L"9 - Напечатать информацию об аккаунте" << endl
              << L"0 - Выход" << endl
              << L"Сделайте свой выбор:";
        wchar_t choice = wcin.get();
        wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
        wcout << line;
        switch (choice) {
            case L'0':
                return EXIT;
            case L'1':
                return CREATE;
            case L'2':
                return CHANGE_OWNER;
            case L'3':
                return WITHDRAW_MONEY;
            case L'4':
                return DEPOSIT_MONEY;
            case L'5':
                return THAT_INTEREST;
            case L'6':
                return EXCHANGE_TO_RUR;
            case L'7':
                return EXCHANGE_TO_USD;
            case L'8':
                return EXCHANGE_TO_EUR;
            case L'9':
                return PRINT;
            default:
                wcout << L"Будьте внимательней!" << endl;
        }
    }
}

template<class T>
T input(wstring msg) {
    while (true) {
        wcout << msg;
        T result;
        wcin >> result;
        if (wcin.fail()) {
            wcout << L"Ошибочный ввод!" << endl;
            wcin.clear();
            wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
        } else {
            wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
            return result;
        }
    }
}

// Создает аккаунт
void createAccount(account *&acc) {
    wstring surname;
    wcout << L"Введите фамилию владельца счета:";
    getline(wcin, surname);

    account::acc_num_type accountNum = input<account::acc_num_type>(L"Номер счета:");

    double percent = input<double>(L"Процент:");

    money summa = input<money>(L"Сумма денег на счету:");

    try {
        account *new_acc = new account(surname, accountNum, percent, summa);
        if (acc) {
            delete acc;
            acc = 0;
            wcout << L"Старый аккаунт удален" << endl;
        }
        acc = new_acc;
    }
    catch (exception &ex) {
        wcout << ex << endl;
    }
}

// Меняет владельца

void changeOwner(account *acc) {
    if (acc) {
        wstring surname;
        wcout << L"Введите фамилию нового владельца счета:";
        getline(wcin, surname);
        acc->setOwner(surname);
        wcout << *acc << endl;
    } else {
        throw account_not_exist();
    }
}

// Снимает деньги

void withdrawMoney(account *acc) {
    if (acc) {
        money summa = input<money>(L"Какую сумму желаете снять?:");

        summa.setCurrency(acc->getCash().getCurrency());
        if (acc->withdrawMoney(summa)) {
            wcout << L"Операция прошла успешно" << endl
                  << *acc << endl;
        } else {
            wcout << L"Невозможно снять требуемую сумму" << endl;
        }
    } else {
        throw account_not_exist();
    }
}

// Ложит деньги на счет

void depositMoney(account *acc) {
    if (acc) {
        money summa = input<money>(L"Какую сумму желаете положить?:");
        summa.setCurrency(acc->getCash().getCurrency());
        acc->depositMoney(summa);
        wcout << *acc << endl;
    } else {
        throw account_not_exist();
    }
}

// Начисляет процент

void thatInterest(account *acc) {
    if (acc) {
        acc->thatInterest();
        wcout << *acc << endl;
    } else {
        throw account_not_exist();
    }
}

// Обмен валют

void exchangeTo(account *acc, currencies currency) {
    if (acc) {
        acc->exchangeTo(currency);
        wcout << *acc << endl;
    } else {
        throw account_not_exist();
    }
}

// Вывод информации

void printAccount(account *acc) {
    if (acc) {
        wcout << *acc << endl;
    } else {
        throw account_not_exist();
    }
}

#pragma region Все, относящееся к class money

money::money(double summa, currencies currency) throw(invalid_argument) {
    if (summa < 0) {
        throw invalid_argument("Сумма не может быть отрицательной");
    }
    _int_part = static_cast<unsigned int> (summa);
    _fract_part = static_cast<unsigned char> ((summa - _int_part) * 100);
    _currency = currency;
}

money::money(unsigned int int_part, unsigned char fract_part, currencies currency) {
    if (fract_part > 99) {
        throw invalid_argument("Количество мелочи не может быть больше 99");
    }
    _int_part = int_part;
    _fract_part = fract_part;
    _currency = currency;
}

currencies money::getCurrency() {
    return _currency;
}

void money::setCurrency(currencies currency) {
    _currency = currency;
}

inline unsigned long long money::smallChange() const {
    return _int_part * 100ULL + _fract_part;
}

// Оператор сложения

money operator+(const money &left, const money &right) {
    if (left._currency != right._currency) {
        throw invalid_argument("Тип валюты не совпадает");
    }
    unsigned int fract_part = left._fract_part + right._fract_part;
    return money(left._int_part + right._int_part + fract_part / 100, fract_part % 100, left._currency);
}

// Оператор вычитания

money operator-(const money &left, const money &right) throw(invalid_argument) {
    if (left < right) {
        throw invalid_argument(
                "Сумма слева не может быть меньше суммы справа. Результат операции не может быть отрицательным");
    }
    if (left._currency != right._currency) {
        throw invalid_argument("Тип валюты не совпадает");
    }

    unsigned long long resultSum = (left._int_part - right._int_part) * 100ULL + left._fract_part - right._fract_part;
    return money(static_cast<unsigned int> (resultSum / 100), resultSum % 100, left._currency);
}

// Оператор умножения(необходим для взятия процента)

money operator*(const money &left, double right) {
    unsigned long long resultSum = static_cast<unsigned long long> ((left._int_part * 100 + left._fract_part) * right);
    return money(static_cast<unsigned int> (resultSum / 100), resultSum % 100, left._currency);
}

inline money operator*(double left, const money &right) {
    return right * left;
}

// Операторы сравнения

bool operator<(const money &left, const money &right) {
    return left.smallChange() < right.smallChange();
}

bool operator>(const money &left, const money &right) {
    return left.smallChange() > right.smallChange();
}

// Операторы ввода-вывода

wostream &operator<<(wostream &stream, const money &right) {
    stream << right._int_part << L"," << setw(2) << setfill(L'0') << right._fract_part << L'('
           << currency_names[right._currency] << L')';
    return stream;
}

wistream &operator>>(wistream &stream, money &right) {
    double sum;
    stream >> sum;
    try {
        right = money(sum);
    }
    catch (exception &) {
        stream.setstate(ios::badbit);
    }
    return stream;
}

#pragma endregion Все, относящееся к class money

money exchanger::exchange(const money &summa, currencies currency) {
    double rate = _rates[summa._currency] / _rates[currency];
    money result = summa * rate;
    result._currency = currency;
    return result;
}

#pragma region Все, относящееся к class account

account::account(const wstring &surname, acc_num_type account_num, double percent, const money &cash)
throw(invalid_argument): _surname(surname), _account_num(account_num), _cash(cash) {
    if (percent < 0) {
        throw invalid_argument("Процент не может быть отрицательным");
    }
    _percent = percent;
}

void account::setOwner(const wstring &surname) {
    _surname = surname;
}

const wstring &account::getOwner() const {
    return _surname;
}

bool account::withdrawMoney(const money &summa) {
    try {
        _cash = _cash - summa;
        return true;
    }
    catch (exception &) {
        return false;
    }
}

void account::depositMoney(const money &summa) {
    _cash = _cash + summa;
}

void account::thatInterest() {
    _cash = _cash * (1.0 + _percent / 100.0);
}

void account::exchangeTo(currencies currency) {
    _cash = exchanger::exchange(_cash, currency);
}

money account::getCash() const {
    return _cash;
}

wostream &operator<<(wostream &stream, const account &right) {
    stream << L"Информация об аккаунте:" << endl
           << L"Владелец:" << right._surname << endl
           << L"Номер счета:" << right._account_num << endl
           << L"Процент:" << fixed << setprecision(2) << right._percent << endl
           << L"Сумма:" << right._cash;
    return stream;
}

#pragma endregion Все, относящееся к class account

