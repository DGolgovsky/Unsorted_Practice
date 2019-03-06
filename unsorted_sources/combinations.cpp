#include <iostream>
#include <vector>

int main() {
    std::vector<int> dim = {2, 3, 5};
    std::vector<int> pos(dim.size(), 0);
    while (true) {
        for (size_t d = 0; d < dim.size(); ++d) {
            std::cout << pos[d] << " ";
        }
        std::cout << std::endl;
        bool overflow = true;
        for (size_t d = dim.size(); d > 0; --d) {
            pos[d - 1] += overflow;
            if ((overflow = pos[d - 1] == dim[d - 1])) {
                pos[d - 1] = 0;
            }
        }
        if (overflow) {
            break;
        }
    }

    return 0;
}
