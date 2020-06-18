#include <sstream>
#include <iostream>

#include <gtest/gtest.h>

#include "hello.h"

TEST(print_hello, simple
) {
std::stringstream ss;
print_hello(ss);
ASSERT_EQ("Hello, World!\n", ss.

str()

);
}
