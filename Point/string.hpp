#pragma once

#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
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

	void append(String const &other);
	size_t length();
	char &get(size_t pos);
	bool equal(const String &other);
	char *str;
private:
	size_t size;
};
