#include <limits.h>

int foo(int a, int b) {
    return a / b;
}

int main(void) {
    return foo(INT_MIN, -1);
}
