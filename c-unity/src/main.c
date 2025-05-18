#include "add.h"
#include "mul.h"
#include <stdio.h>
int main() {
  printf("10 + 2 = %d\n", add(10, 2));
  printf("10 * 2 = %d\n", mul(10, 2));
  return 0;
}