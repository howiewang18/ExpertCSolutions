#include <stdio.h>

#define IS_UNSIGNED(type) ((type)0 - 1 > 0)

int main() {
  printf("Is char unsigned? %d\n", IS_UNSIGNED(char));
  printf("Is int unsigned? %d\n", IS_UNSIGNED(int));
  printf("Is unsigned int unsigned? %d\n", IS_UNSIGNED(unsigned int));
  return 0;
}
