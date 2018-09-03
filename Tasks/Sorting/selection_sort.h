#ifndef _SELECTION_SORT_
#define _SELECTION_SORT_

#include "has_at_method.h"

template<typename T>
void selection_sort(T& obj)
{
    if constexpr (has_at<T>) {
	    auto sz = obj.size() - 1;
    	for (std::size_t i = sz; i > 0; --i) {
	        for (std::size_t j = 0; j < i; ++j) {
	            if (obj.at(j) > obj.at(i))
	                std::swap(obj.at(j), obj.at(i));
	        }
	    }
    }
}

#endif
