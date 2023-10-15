#include "test.hpp"

#include <assert.h>
#include <iostream>

int main() { test_data(12, 12); };

void test_data(int i, int two) { assert(i == two); };
