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



String operator+(String s1, String const& s2) {
	return s1 += s2;
}
void String::PreparedString::write(std::ostream& out) const
{
    out << (this->source.str+this->from) << std::endl;
}

String String::PreparedString::operator[](unsigned int to) const
    {
        char *tmp_c_str = new char[to-from+1];
        for(char *at_src = source.str+from, *at_dst = tmp_c_str, *last = source.str+to; at_src != last; ++at_src, ++at_dst)
            *at_dst = *at_src;
        *(tmp_c_str+to-from) = '\0';
        String tmp_string(tmp_c_str);
        delete[] tmp_c_str;

        return tmp_string;
    }

String::PreparedString::PreparedString(const String& source_in, unsigned int from_in): source(source_in), from(from_in)
{
}

String::PreparedString String::operator[](unsigned int from) const
{
    return String::PreparedString(*this,from);
}

void String::write(std::ostream& out) const
{
    out << this->str << std::endl;
}
