#include <setjmp.h>
#include <stdio.h>

jmp_buf buf;

void loop_forever() {
  int c;
  while (1) {
    int i = 0;
    while ((c = getchar()) != '\n' && c != EOF) {
      if (c == 's') {
        printf("User enters stop.\n");
        longjmp(buf, 1);
      } else if (c < '0' || c > '9') {
        printf("Invalid character %c\n", c);
        longjmp(buf, -1);
      }
      i *= 10;
      i += c - '0';
    }
    if (c == EOF) {
      return;
    }
    printf("%d\n", 2 * i);
  }
}

int main() {
  int val = setjmp(buf);
  if (val == 0) {
    loop_forever();
  } else if (val > 0) {
    printf("Confirm user enters stop.\n");
    return 0;
  } else if (val < 0) {
    fprintf(stderr, "Exception.\n");
    return 1;
  }
  return 0;
}
