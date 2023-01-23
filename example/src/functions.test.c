#include "test.h"
#include "./functions.c"

void test_add() {
  ASSERT("2 + 2 = 4", add(2, 2) == 4);
  ASSERT_EQUALS(add(3, 3), 6);
}

void test_mult() {
  ASSERT("2 * 2 = 4", mult(2, 2) == 4);
  ASSERT_EQUALS(mult(3, 3), 9);
}

void test_str() {
  ASSERT_STRING_EQUALS("calzone", pizza());
}

int main() {
  RUN(test_add);
  RUN(test_mult);
  RUN(test_str);
  return TEST_REPORT();
}
