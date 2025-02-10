#include "test.hpp"

int main() { test_data(12, 12); };

void test_data(int first, int second) { assert(first == second); };
