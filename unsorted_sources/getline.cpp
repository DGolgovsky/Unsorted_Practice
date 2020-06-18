#include <iostream>
#include <cstring>

using namespace std;

char *getline() {
	const size_t INITIAL_SIZE = 100; //размер буфера
	const size_t ALLOCATION_STEP = 10; //размер шага для увеличения буфера

	size_t current_size = INITIAL_SIZE; //текущий размер буфера
	char *buffer = new char[current_size]; // создание буфера

	size_t n = 0; //счётчик для контроля переполнения
	char c = 0; //переменная для считывания символов

	while (cin.get(c) && c != '\n') { //запуск цикла считывания символов
		if (n + 1 > current_size) { //проверка переполнения буфера
			current_size += ALLOCATION_STEP; //увеличеваем размер буфера
			char *new_buffer = new char[current_size]; //создаём новый буфер увеличенного размера
			memcpy(new_buffer, buffer, n); //копируем в новый буфер данные из старого буфера
			delete[] buffer; //удаляем память по адресу buffer
			buffer = new_buffer; //назначаем переменной buffer адрес нового увеличенного адреса памяти
		}
		buffer[n++] = c; //заносим все символы в буфер
	}

	char *final_buffer = new char[n + 1]; //выделяем память окончательного размера
	memcpy(final_buffer, buffer, n); //копируем в неё данные
	final_buffer[n] = '\0'; //вставляем в конце символ окончания строки
	delete[] buffer; //удаляем старый буфер
	return final_buffer; //возвращаем финальный

}

int main() {
	return 0;
}
