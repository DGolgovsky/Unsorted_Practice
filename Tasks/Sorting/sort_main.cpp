/* Base includes */
#include <iostream>
#include <vector>

/* Sorting includes */
#include "insertion_sort.h"
#include "selection_sort.h"
#include "quick_sort.h"

template<typename C>
void print_output(std::ostream& os, const C& container)
{
    os << "[ ";
    for (auto& it : container)
        os << it << " ";
    os << "]" << std::endl;
}

/* Container passed by value*/
template<typename C>
void test_case(const std::string&& test_name,
               C container,
               void (*Fun)(C&))
{
    std::cout << test_name << ":\t\t";
    Fun(container);
    print_output(std::cout, container);
}

int main(int, char**)
{
    const std::size_t size = 16;
    std::vector<unsigned> sequence(size);

    srand((unsigned)time(NULL));
    for (std::size_t i = 0; i < size; ++i)
        sequence.at(i) = rand() % 100 + 1;

    std::cout << "Original container:\t";
    print_output(std::cout, sequence);

    { /* TEST CASE 01*/
        test_case("Insertion sort", sequence, insertion_sort);
        
    }
    { /* TEST CASE 02*/
        test_case("Selection sort", sequence, selection_sort);
    }
    { /* TEST CASE 03*/
        test_case("Quick sort", sequence, quick_sort);
    }

    return 0;
}
