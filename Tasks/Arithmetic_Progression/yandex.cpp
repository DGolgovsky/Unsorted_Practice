#include <iostream>
#include <vector>
#include <array>

int main()
{
    double p, A, B, C, D;
    int x, y, z, N;
    std::cin >> p;
    std::cin >> N;

    std::vector<std::array<int, 3>> base;
    std::vector<std::array<double, 4>> values;

    for (int i = 0; i < N; ++i) {
        std::cin >> x >> y >> z;
        base.push_back({x,y,z});
    }

    double h = 0.0;
    A = 1;
    B = 0;
    C = 0;
    D = 0;

    for (int j = 0; j < N; ++j) {
        x = base[j][0];
        y = base[j][1];
        z = base[j][2];
        h += A*x + B*y + C*z + D;
        std::cout << base[j][0] << " "<< base[j][1] << " "<< base[j][2] << '\n';
    }

    std::cout << h << std::endl;

    return 0;
}