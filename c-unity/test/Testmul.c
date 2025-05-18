#include "mul.h"
#include "unity.h"

void setUp() {
  // Set up code here (if needed)
}
void tearDown() {
  // Tear down code here (if needed)
}
void test_mul() {
  TEST_ASSERT_EQUAL(2, mul(1, 2));
  TEST_ASSERT_EQUAL(0, mul(0, 0));
}
void test_mul_fail() {
  TEST_ASSERT_EQUAL(-6, mul(-2, -3)); // This test will fail
}
int main() {
  UNITY_BEGIN();
  RUN_TEST(test_mul);
  RUN_TEST(test_mul_fail);
  UNITY_END();
  return 0;
}