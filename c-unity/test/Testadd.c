#include "add.h"
#include "unity.h"

void setUp() {
  // Set up code here (if needed)
}
void tearDown() {
  // Tear down code here (if needed)
}
void test_add() {
  TEST_ASSERT_EQUAL(3, add(1, 2));
  TEST_ASSERT_EQUAL(0, add(0, 0));
  TEST_ASSERT_EQUAL(10, add(0, 0)); // This test will fail
  TEST_ASSERT_EQUAL(-1, add(-1, 0));
  TEST_ASSERT_EQUAL(5, add(2, 3));
  TEST_ASSERT_EQUAL(-5, add(-2, -3));
  TEST_ASSERT_EQUAL(5, add(-2, -3)); // This test will fail
}
void test_add_fail() {
  TEST_ASSERT_EQUAL(5, add(-2, -3)); // This test will fail
}
int main() {
  UNITY_BEGIN();
  RUN_TEST(test_add);
  RUN_TEST(test_add_fail);
  return UNITY_END();
  // return 0;
}
