#include <iostream>
/*
 * input:
 * “vnk2435kvabco8awkh125kjneytbcd12qjhb4acd123xmnbqwnw4t”
 * “abcd1234”
 *
 * output:
 * sequence of length = 3 found at haystack offset 9, needle offset 0
 * sequence of length = 5 found at haystack offset 27, needle offset 1
 * sequence of length = 5 found at haystack offset 38, needle offset 2
 */

using std::cout;
using std::endl;

void print_result(int sequence, int offset, int needle_offset)
{
    cout << "sequence of length = " << sequence
         << " found at haystack offset " << offset
         << ", needle offset " << needle_offset
         << endl;
}

int comlen(char *p, char *q, int threshold, int &needle_offset)
{
    int sequence = 0;
    needle_offset = 0;
    while (*p != '\0') {
        if (*q == *p) {
            while ( (*p != '\0' || *q != '\0') && *p == *q) {
                sequence++;
                p++;
                q++;
            }
            if (sequence < threshold)
                return 0;
            else {
                return sequence;
            }
        }
        needle_offset++;
        p++;
    }
    return 0;
}

inline void
search( char const *haystack
      , char const *needle
      , int        threshold )
{
    int sequence = 0;
    int offset = 0;
    int needle_offset = 0;

    char *c_h = const_cast<char*>(haystack);
    char *c_n = const_cast<char*>(needle);
    while (*c_h != '\0') {
        sequence = comlen(c_n, c_h, threshold, needle_offset);
        if (sequence) {
            print_result(sequence, offset, needle_offset);
            int i = 0;
            while((i <= sequence) && (*c_h!='\0')) {
                c_h++;
                offset++;
                i++;
            }
            continue;
        }
        c_h++;
        offset++;
    }
}

int main()
{
    char const
        *haystack = "vnk2435kvabco8awkh125kjneytbcd12qjhb4acd123xmnbqwnw4t";
    char const
        *needle = "abcd1234";
    int threshold = 3;

    search(haystack, needle, threshold);

    return 0;
}
