#include <assert.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int IsValidTime(uint64_t t) { return ctime((time_t *)&t) == NULL ? 0 : 1; }

int main() {
  uint64_t low = 0, high = 0xFFFFFFFFFFFFFFFF;
  while (low < high) {
    uint64_t mid = high - (high - low) / 2;
    if (IsValidTime(mid)) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }
  printf("The max local time is approximately: %s", ctime((time_t *)&low));
  printf("And the corresponding time_t is 0x%lX.\n", low);

  uint64_t invalid_time = low + 1;
  assert(ctime((time_t *)(&invalid_time)) == NULL);

  return 0;
}
