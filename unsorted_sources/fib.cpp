#include <cassert>
#include <cstdint>
#include <iostream>
#include <cmath>

class Fibonacci final {
 public:
  static int get_remainder(int64_t n, int m) {
    assert(n >= 1);
    assert(m >= 2);
    int k = (int)(log(m * sqrt(5)) / log((1 + sqrt(5))/2));
    int fibk = (int)(0.5 + pow(((1 + sqrt(5))/2), k)/sqrt(5));
    int fibk1 = (int)(0.5 + pow(((1 + sqrt(5))/2),(k - 1))/sqrt(5));
    int fibprev = fibk1;
    int fibcur = fibk;
    int period = 0;
    int is_k1 = 0;
    while(1) {
      if (is_k1) {
        if (fibcur == fibk)
          break;
        is_k1 = 0;
      }
      if (fibcur == fibk1)
        is_k1 = 1;
      int fibnext = (fibcur + fibprev) % m;
      fibprev = fibcur;
      fibcur = fibnext;
      period++;
    };
    int skip = (n - k) % period;
    fibcur = fibk;
    fibprev = fibk1;
    while (skip) {
      int fibnext = (fibcur + fibprev) % m;
      fibprev = fibcur;
      fibcur = fibnext;
      skip--;
    };
    return fibcur;
  }
};

int main(void) {
  int64_t n;
  int m;
  std::cin >> n >> m;
  std::cout << Fibonacci::get_remainder(n, m) << std::endl;
  return 0;
}
