#include <stdio.h>
#include <stdlib.h>

int main() {
  size_t lo = 0;
  size_t hi = 0xFFFFFFFFFFFFFFFF;
  size_t mid;
  void *data;

  while (lo < hi) {
    mid = lo + (hi - lo) / 2;
    data = malloc(mid);
    if (data == NULL) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  printf("malloc can allocate 0x%lx bytes at the maximum for the current setup.\n",
         lo);
  return 0;
}
