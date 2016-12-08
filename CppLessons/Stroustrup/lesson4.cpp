#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char ** argv)
{
    std::vector<double> temps;
    for (double temp; std::cin >> temp; )
        temps.push_back(temp);

    double sum = 0.0;
    for (int x : temps)
        sum += x;
    std::cout << "Средняя температура: "
              << sum/temps.size() << '\n';

    std::sort(temps.begin(), temps.end());
    std::cout << "Median temp: "
              << temps[temps.size()/2] << '\n';
    return 0;
}

