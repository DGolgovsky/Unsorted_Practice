#include <vector>
#include <string>
#include <iostream>
#include <deque>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Path
{
	string From;
	string To;
};

deque <string> getRoute(vector <Path> cityList) {
	deque <string> finalRoute;

	finalRoute.push_front(cityList[0].From);
	finalRoute.push_back(cityList[0].To);
	cityList[0].To = "-";

	string back, front;
	for (unsigned int i = 0; i < cityList.size(); ++i) {
		for (auto &it : cityList) {
			if (it.To == "-") continue;
			front = finalRoute.front();
			back = finalRoute.back();
			if (it.From == back && back != it.To) {
				finalRoute.push_back(it.To);
				it.To = "-";
			}
			if (it.To == front && front != it.From) {
				finalRoute.push_front(it.From);
				it.To = "-";
			}
		}
	}
	return finalRoute;
}

int main() {
	vector <Path> cityList = {{"Омск",         "Екатеринбург"},
							  {"Владивосток",  "Тюмень"},
							  {"Екатеринбург", "Москва"},
							  {"Тюмень",       "Омск"}};
	deque <string> finalRoute;

	auto start = steady_clock::now();
	finalRoute = getRoute(cityList);
	auto finish = steady_clock::now();
	for (const auto &it : finalRoute) {
		cout << it << " ";
	}
	cout << endl << "Function getRoute: "
		 << duration_cast<milliseconds>(finish - start).count()
		 << " ms" << endl;

	return 0;
}
