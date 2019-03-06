/*
 * Java developers laughting of you
 * A+=++A+++++A++;
 */

#include <iostream>

int main(void) {
    int i = 10;
    i += ++i++ ++ + i++;
    std::cout << i << std::endl;
    return 0;
}
