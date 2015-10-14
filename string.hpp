#pragma once

#include <algorithm> // std::swap
#include <cstddef>   // size_t
#include <cstring>   // strlen, strcpy

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

	char & at(size_t idx)       { return str[idx]; }
	char   at(size_t idx) const { return str[idx+1]; }

	void swap(String &other);
	void append(String const &other);
	size_t length();
	char &get(size_t pos);
	bool equal(const String &other);
	char *str;
	size_t size;
};
