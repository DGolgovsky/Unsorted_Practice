#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 2

class Student
{
private:
	char *surname;
	char *name;
	char *faname;
	char *birthday;
	char *adress;
	char *phone;
	char *fac;
	char *year;
public:
	Student() {
		surname = new char[40];
		name = new char[40];
		faname = new char[40];
		birthday = new char[40];
		adress = new char[40];
		phone = new char[40];
		fac = new char[40];
		year = new char[40];
	}

	Student(char *snm, char *nm, char *fnm, char *bthd, char *adr, char *phn, char *fc, char *yr) {
		surname = new char[40];
		strcpy(surname, snm);
		name = new char[40];
		strcpy(name, nm);
		faname = new char[40];
		strcpy(faname, fnm);
		birthday = new char[40];
		strcpy(birthday, bthd);
		adress = new char[40];
		strcpy(adress, adr);
		phone = new char[40];
		strcpy(phone, phn);
		fac = new char[40];
		strcpy(fac, fc);
		year = new char[40];
		strcpy(year, yr);
	}

	Student(const Student &Obj) {
		surname = new char[40];
		strcpy(surname, Obj.surname);
		name = new char[40];
		strcpy(name, Obj.name);
		faname = new char[40];
		strcpy(faname, Obj.faname);
		birthday = new char[40];
		strcpy(birthday, Obj.birthday);
		adress = new char[40];
		strcpy(adress, Obj.adress);
		phone = new char[40];
		strcpy(phone, Obj.phone);
		fac = new char[40];
		strcpy(fac, Obj.fac);
		year = new char[40];
		strcpy(year, Obj.year);
	}

	~Student() {
		delete[] surname;
		delete[] name;
		delete[] faname;
		delete[] birthday;
		delete[] adress;
		delete[] phone;
		delete[] fac;
		delete[] year;
	}

	void setSnm(char *snm) {
		strcpy(surname, snm);
	}

	void setNm(char *nm) {
		strcpy(name, nm);
	}

	void setFnm(char *fnm) {
		strcpy(faname, fnm);
	}

	void setBthd(char *bthd) {
		strcpy(birthday, bthd);
	}

	void setAd(char *ad) {
		strcpy(adress, ad);
	}

	void setPh(char *ph) {
		strcpy(phone, ph);
	}

	void setFc(char *fc) {
		strcpy(fac, fc);
	}

	void setYr(char *yr) {
		strcpy(year, yr);
	}

	void showSnm() {
		std::cout << surname;
	}

	void showNm() {
		std::cout << name;
	}

	void showFnm() {
		std::cout << faname;
	}

	void showBthd() {
		std::cout << birthday;
	}

	void showAd() {
		std::cout << adress;
	}

	void showPhn() {
		std::cout << phone;
	}

	void showFc() {
		std::cout << fac;
	}

	void showYr() {
		std::cout << year;
	}

	char *getFc() {
		return fac;
	}

	char *getYr() {
		return year;
	}

	char *getBthd() {
		return birthday;
	}
};

char *readStudents(char *str, Student std[SIZE]) {
	char *buf = str;
	char *bufs = new char[40];
	char *masbufs[8];
	int tochk = 0;

	int i = 0, k = 0;
	for (int j = 0; j < SIZE; j++) {
		i = 0;
		k = 0;
		tochk = 0;
		for (int i = 0; i < 8; i++) {
			masbufs[i] = new char[40];
		}
		while (tochk < 3 && *buf != '\n' && *buf != '\0') {
			if (*buf == '.') {
				tochk++;
				if (tochk == 3) {
					break;
				}
			}
			if (*buf != ',' && *buf != ' ') {
				bufs[i] = *buf;
			} else if (*buf == ',') {
				strcpy(masbufs[k], bufs);
				k++;
				i = -1;
				memset(bufs, 0, 40);
			} else i--;
			buf++;
			i++;
		}
		buf++;
		strcpy(masbufs[k], bufs);

		std[j].setSnm(masbufs[0]);
		std[j].setNm(masbufs[1]);
		std[j].setFnm(masbufs[2]);
		std[j].setBthd(masbufs[3]);
		std[j].setAd(masbufs[4]);
		std[j].setPh(masbufs[5]);
		std[j].setFc(masbufs[6]);
		std[j].setYr(masbufs[7]);
	}
	return buf;
}

void printStudent(Student std) {
	std.showSnm();
	std::cout << ", ";
	std.showNm();
	std::cout << ", ";
	std.showFnm();
	std::cout << ", ";
	std.showBthd();
	std::cout << ", ";
	std.showAd();
	std::cout << ", ";
	std.showPhn();
	std::cout << ", ";
	std.showFc();
	std::cout << ", ";
	std.showYr();
}

char *printFacStudent(char *str, Student std[SIZE]) {
	int c = 0;
	char *buf = str;
	char bufs[40];
	int i = 0;
	char *facstr = new char[40];
	while (buf) {
		if (*buf != ' ' && *buf != ',') {
			bufs[i] = *buf;
			i++;
		} else if (*buf == ',') {
			strcpy(facstr, bufs);
			break;
		}
		buf++;
	}

	for (int i = 0; i < SIZE; i++) {
		if (!strncmp(std[i].getFc(), facstr, 6)) {
			if (c > 0) {
				std::cout << "; ";
			}
			printStudent(std[i]);
			c++;
		}
	}
	std::cout << ". ";
	return ++buf;
}

char *printYearStudent(char *str, Student std[SIZE]) {
	int c = 0;
	char *buf = str;
	char *bufs = new char[40];
	int i = 0;
	char *facstr = new char[40];
	while (buf) {
		if (*buf != ' ' && *buf != ',') {
			bufs[i] = *buf;
			i++;
		} else if (*buf == ',') {
			strcpy(facstr, bufs);
			break;
		}
		buf++;
	}

	for (int i = 0; i < SIZE; i++) {
		if (!strncmp(std[i].getYr(), facstr, 1)) {
			if (c > 0) {
				std::cout << "; ";
			}
			printStudent(std[i]);
			c++;
		}
	}
	std::cout << ". ";
	return ++buf;
}

void printBirthdayStudent(char *str, Student std[SIZE]) {
	int c = 0;
	char *buf = str;
	char *bufs = new char[40];
	int i = 0;
	char *facstr = new char[40];
	while (buf) {
		if (*buf != ' ' && *buf != ',' && *buf != '\n' && *buf != '\0') {
			bufs[i] = *buf;
			i++;
		} else if (*buf == ',' || *buf == EOF || *buf == '\n' || *buf == '\0') {
			strcpy(facstr, bufs);
			break;
		}
		buf++;
	}

	for (int i = 0; i < SIZE; i++) {
		if (atoi(std[i].getBthd() + 6) > atoi(facstr + 6)) {
			if (c > 0) {
				std::cout << "; ";
			}
			printStudent(std[i]);
			c++;
		}
	}
	std::cout << ".";
}

char *readstr() {
	char buf = getchar();
	char *string = new char[200];
	for (int i = 0; buf != EOF && buf != '\n'; i++) {
		string[i] = buf;
		buf = getchar();
	}
	return string;
}

int main(int argc, char **argv) {
	Student students[SIZE];
	char *string;
	string = readstr();

	string = readStudents(string, students);

	string = printFacStudent(string, students);
	string = printYearStudent(string, students);
	printBirthdayStudent(string, students);
	std::cout << '\n';
	return 0;
}

