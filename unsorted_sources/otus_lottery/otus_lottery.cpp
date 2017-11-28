#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <thread>
#include <vector>

using pupils_t = std::vector<std::string>;

std::ostream & operator<<(std::ostream &os, pupils_t const &v)
{
    os << "[";
    auto first = std::begin(v);
    for (auto i = first; i != std::end(v); ++i) {
        if (i != first)
            os << ", ";
        os << *i;
    }
    os << "]" << std::flush;
    std::this_thread::sleep_for(std::chrono::seconds(std::min<size_t>(v.size(), 5)));
    return os;
}

template<typename ForwardIt>
ForwardIt by_twos(ForwardIt first, ForwardIt last)
{
    for (ForwardIt i = first; i != last; ++i) {                // 1st place
    //for (ForwardIt i = std::next(first); i != last; ++i) {   // 2nd place
        std::iter_swap(i, first);
        ++first;
        if (++i == last)
            break;
    }
    return first;
}

template<class URGB>
void turn(pupils_t &v, URGB&& g)
{
    std::shuffle(std::begin(v), std::end(v), g);

    std::cout << "*  shuffle: " << v << std::endl << std::endl;

    auto t = by_twos(std::begin(v), std::end(v));
    v.erase(t, v.end());

    std::cout << "*  by twos: " << v << std::endl << std::endl;
}

template<typename T, typename URGB>
typename T::value_type lottery(T &v, URGB&& g)
{
    assert(v.size());

    while (v.size() > 1) {
        turn(v, g);
    }

    return v.front();
}

int main(int argc, char **argv)
{
    // cut -c 1-7 emails.txt > emails.pub
    // cat emails.pub | ./a.out
    // wc -l emails.*

    pupils_t v;
    for (std::string line; std::getline(std::cin, line); )
        v.push_back(line);
    std::sort(std::begin(v), std::end(v));

    std::cout << "* original: " << v << std::endl << std::endl;

    std::mt19937 g;
    g.seed(1511810089); // TIMESTAMP `date +%s`

    std::cout << lottery(v, g) << " wins" << std::endl;

    // winner: grep ^<e-mail> emails.txt

    return 0;
}
