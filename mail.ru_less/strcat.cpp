#include <iostream>

char* strcat(char*, const char*);

int strlen(const char*);

int main()
{
    char *str1 = new char();
    char *str2 = new char();
    std::cin >> str1;
    std::cin >> str2;

    std::cout << strcat(str1, str2) << "\n"
              << strlen(str1) << "\n";
    delete str2;
    delete str1;
    return 0;
}

char *strcat(char *str1, const char *str2)
{
    char *cp = str1;
    while(*cp) cp++;
    cp--;
    while(*cp++ = *str2++);
    return str1;
}

int strlen(const char *str)
{
    const char *eos = str;
    while(*eos++);
    return (int) (eos - str - 1);
}

