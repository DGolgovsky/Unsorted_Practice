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

#include <iostream>

inline void
print_result( unsigned int sequence
            , unsigned int offset
            , unsigned int needle_offset )
{
    std::cout << "sequence of length = " << sequence
         << " found at haystack offset " << offset
         << ", needle offset " << needle_offset
         << std::endl;
}

inline unsigned int
compire( char const   *p
       , char const   *q
       , unsigned int &needle_offset )
{
    unsigned int sequence = 0;
    needle_offset = 0;
    while (*p != '\0') {
        if (*q == *p) {
            while (*p == *q && (*p != '\0' || *q != '\0')) {
                sequence++;
                p++;
                q++;
            }
            return sequence;
        }
        needle_offset++;
        p++;
    }
    return 0;
}

inline void
search( char const         *haystack
      , char const         *needle
      , unsigned int const threshold )
{
    unsigned int sequence = 0;
    unsigned int offset = 0;
    unsigned int needle_offset = 0;

    while (*(haystack+offset) != '\0') {
        sequence = compire(needle, haystack+offset, needle_offset);
        if (sequence >= threshold) {
            print_result(sequence, offset, needle_offset);
            unsigned int i = 0;
            while((i <= sequence) && (*(haystack+offset)!='\0')) {
                offset++;
                i++;
            }
            continue;
        }
        offset++;
    }
}

int main()
{
    char const
        *haystack = "vnk2435kvabco8awkh125kjneytbcd12qjhb4acd123xmnbqwnw4t";
    char const *needle = "abcd1234";
    unsigned int const threshold = 3;

    search(haystack, needle, threshold);

    return 0;
}
