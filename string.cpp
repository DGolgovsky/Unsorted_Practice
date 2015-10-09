#include "string.hpp"

void String::append(String const &other)
{
    char *_Dest = new char[this->size + other.size + 1];
    strcpy(_Dest, this->str);
    strcat(_Dest, other.str);
    delete [] str;
    this->str = _Dest;
    this->size = strlen(this->str);
    this->str[this->size] = '\0';
}

size_t String::length()
{
    return this->size; //todo
}

bool String::equal(const String &other)
{
    return 0;  //todo
}

void String::swap(String &other)
{
    std::swap(size, other.size);
    std::swap(str, other.str);
}
