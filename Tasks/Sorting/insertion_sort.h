#ifndef _INSERTION_SORT_
#define _INSERTION_SORT_

#include "has_at_method.h"

template<typename T>
void insertion_sort(T& obj)
{
    if constexpr (has_at<T>) {
        auto sz = obj.size();
        for (std::size_t i = 1; i < sz; ++i) {
            for (auto j = i; j > 0 && obj.at(j-1) > obj.at(j); --j) {
                auto key = obj.at(j);
                obj.at(j) = obj.at(j-1);
                obj.at(j-1) = key;
            }
        } 
    }
}

#endif
