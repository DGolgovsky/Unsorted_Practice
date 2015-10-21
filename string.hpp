#pragma once

#include <algorithm> // std::swap
#include <cstddef>   // size_t
#include <cstring>   // strlen, strcpy
#include <iostream>

struct String
{
public:
	String(const char *str = "") {
		this->size = strlen(str);
		char* nw = new char[this->size + 1];
		strcpy(nw, str);
		this->str = nw;
	}

	String(size_t n, char c) {
		char* nw = new char [n + 1];
        for(size_t i = 0; i < n; ++i)
            nw[i] = c;
        this->size = n;
        this->str = nw;
	}

	~String() {
		delete [] str;
	}

	String &operator=(const String &other) {
        if (this != &other)
			String(other).swap(*this);
		return *this;
	}

	String &operator+=(String const& s) {
		return *this;
	}

	char & at(size_t idx)       { return str[idx]; }
	char   at(size_t idx) const { return str[idx+1]; }

	void swap(String &other);
	void append(String const &other);
	size_t length();
	char &get(size_t pos);
	bool equal(const String &other);

	class PreparedString {
    public:
        void write(std::ostream& out) const;

        String operator[](unsigned int to) const;

        PreparedString(const String& source_in, unsigned int from_in);

    private:
        const String& source;
        unsigned int from;
    };

    void write(std::ostream& out) const;

    PreparedString operator[](unsigned int from) const;
	char *str;
	size_t size;
};

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
