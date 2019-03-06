#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
    char s1[20] = "C++ forever a ever!";
    char s2[16];
    cout << "strncpy(s2, s1, sizeof(s2)) = " << strncpy(s2, s1, sizeof(s2)) << endl;
    cout << "sizeof(s2) = " << sizeof(s2) << endl;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    char s3[8];
    cout << "strncpy(s3, s1, 7) = " << strncpy(s3, s1, 7) << endl;

    cout << '\n';

    char str_c_1[30] = "I am ";
    char str_c_2[] = "programmer on the C++!!!!";
    cout << strcat(str_c_1, str_c_2) << '\n';
    char str_c_3[23] = "I am a good ";
    cout << strncat(str_c_3, str_c_2, 10) << "!!!" << '\n';

    return 0;
}

