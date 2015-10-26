#include <iostream>
int main() {
  int num = 0, i = 1;
  std::cin >> num;
  while (i <= num) {
    if (num % ++i == 0) {
      std::cout << i << std::endl;
      return 0;
    }
  }
  return 0;
}
