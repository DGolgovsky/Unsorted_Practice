#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream &os, std::vector<int> const &vec) {
    for (auto it : vec)
        os << "[" << it << "]";
    os << std::endl;
    return os;
}

int main(void)
{
    std::vector<int> sequence = {29,72,98,13,87,66,52,51,36};
	std::cout << "Before:\t" << sequence;

    int vec_size = sequence.size() - 1;
    for (int i = vec_size; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (sequence[j] > sequence[i])
                std::swap(sequence[j],sequence[i]);
        }
    }

	std::cout << "After:\t" << sequence;

    return 0;
}
