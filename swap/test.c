#include <stdio.h>

void swap(int* a, int* b) {
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

int main() {
  int a = 1, b = 2;
  swap(&a, &b);
  /*
          0 ^ 0 ^ 0 = 0 ^ 0 = 0
          1 ^ 1 ^ 1 = 0 ^ 1 = 1
          *a = (A ^ B)
          *b = B ^ (A ^ B) = A
          *a = (A ^ B) ^ A = B
  */
  printf("Swap different values at different addresses ok? %d\n",
         (a == 2) && (b == 1));
  int c = 1, d = 1;
  swap(&c, &d);
  printf("Swap same value at different addresses ok? %d\n",
         (c == 1) && (d == 1));
  int e = 1;
  swap(&e, &e);
  /*
   *a = A ^ A = 0
   *b = 0 ^ 0 = 0
   *a = 0 ^ 0 = 0
   */
  printf("Swap values at the same address ok? %d\n", e == 1);
  return 0;
}
