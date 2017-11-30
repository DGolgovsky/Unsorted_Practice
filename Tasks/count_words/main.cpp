/*
 * Developed by Dmitry Golgovsky <d.westcoast@aol.com>
 *
 * Description of the program
 *
 */

#include <iostream>

#include <vector>
#include <map>
#include <list>
#include <set>

#include <sstream>
#include <string>
#include <cmath>

#include <functional>
#include <algorithm>

using namespace std;

using words_t = std::map<std::string, unsigned int>;

std::string trim(std::string & str)
{
    std::string ret_str = str;
    while(1) {
        int fr = (char)ret_str.front();
        // 33 - 47
        if (fr > 32 && fr < 48)
            ret_str = ret_str.substr(1);

        int ba = (char)ret_str.back();
        if (ba > 32 && ba < 48)
            ret_str = ret_str.substr(0, ret_str.size()-1);
        else
            break;
    }

    return ret_str;
}

int main(int argc, char const ** argv)
{
    std::setlocale(LC_ALL, "Russian");
    words_t wrd;
    std::string word;

    for (std::string line; std::getline(std::cin, line); ) {
        std::istringstream ss(line);
        while (ss >> word) {
            word = trim(word);
            auto ll = word.size()/2;
            if (ll > 3)
                wrd[word]++;
        }
    }

    std::map<int, std::string> output_map;
    for (auto const & it : wrd) {
        auto k = it.second;
        if (k > 1)
            output_map[k] = it.first;
    }

    for (auto const &it : output_map)
        std::cout << "[" << it.second << "] = " << it.first << '\n';


    return 0;
}
