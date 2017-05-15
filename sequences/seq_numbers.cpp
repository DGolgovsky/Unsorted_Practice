/*
 * Find the missing number in sequence
 * Using:
 * ./seq_numbers < seq_numbers_data.txt 1> seq_numbers_out.txt 2> seq_numbers_debug.txt
 */
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

int main(void)
{
    char ent_str[40960];
    std::cin.getline(ent_str, sizeof(ent_str));

    char *pch = strtok (ent_str," ,.!?");
    char *sentence[8000];

    int i = 0;
    while (pch != NULL) {
        sentence[i++] = pch;
        pch = strtok (NULL, " ,.!?");
    }

    int check_n = 0;
    int check_m = 0;
    for (int j = 0; j < i; ++j) {
        check_n = atoi(sentence[j]);
        std::cerr << check_n << ":" << check_m << "\n"; //debug
        if (check_n != check_m) {
            std::cout << check_n << "\n";
            check_m++;
        }

        check_m++;
    }

	return 0;
}
