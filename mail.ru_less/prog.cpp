#include <iostream>
#include <cstring>

int main()
{
    char *word = new char();
    std::cin >> word;
    char ent_str[1024];
	std::cin.getline(ent_str, sizeof(ent_str));
/*
    std::cout << word << "\n";
    std::cout << ent_str << "\n";
*/
    char *pch = strtok (ent_str,".!?");
    char *sentence[1024];
	int i = 0;
    while (pch != NULL) {
        sentence[i++] = pch;
        pch = strtok (NULL, ".!?");
    }
    double count = 0.0;
    delete pch;
	double cnt_snt = 0.0;
    for (int j = 0; j < i; ++j) {
		bool cur_j = false;
        char *pch = strtok (sentence[j]," ");
        while (pch != NULL) {
            if (strcmp(word, pch) == 0) {
                count++;
				if (!cur_j) {
					cur_j = true;
					cnt_snt++;
				}
			}
            pch = strtok (NULL, " ");
        }
    }
    count = count / cnt_snt;
    std::cout << count << "\n";
    return 0;
}
