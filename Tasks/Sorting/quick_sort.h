#ifndef _QUICK_SORT_
#define _QUICK_SORT_

#include "has_at_method.h"

template <typename C, typename I>
void quick_sort_helper(C &cont, I left, I right) {
	auto size = std::distance(left, right);
	if (size <= 1)
		return;

	auto pivot = std::next(right, -1);
	if (size == 2 && *pivot < *left)
		std::iter_swap(left, pivot);

	auto wall = left;
	auto curr = left;

	while (curr != right) {
		if (*curr < *pivot) {
			std::iter_swap(wall, curr);
			wall++;
		}
		curr++;
	}

	std::iter_swap(pivot, wall);
	quick_sort_helper(cont, left, wall);
	quick_sort_helper(cont, wall + 1, right);
}

template <typename T>
void quick_sort(T &obj) {
	if constexpr (has_at<T>) {
		quick_sort_helper(obj, std::begin(obj), std::end(obj));
	}
}

#endif
