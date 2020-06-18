/*
 * Получить сортированный список из 10 человек
 * с балансом на счету близким к медиане.
 *
 * => отсортировать всех по балансу и выбрать 10 человек из середины
 */
#include <algorithm>

template <typename It>
auto balance_median(It const &v) // ~O(N*log(N))
{
	auto it = v.begin() + v.size() / 2 - 5;

	const auto f = [](const auto &v1, const auto &v2) {
		return v1.balance() < v2.balance();
	};

	std::nth_element(v.begin(), it, v.end(), f);
	std::partial_sort(it + 1, it + 10, v.end(), f);

	return it;
}
