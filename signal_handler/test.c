#include <setjmp.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

jmp_buf buf;

void sigsegv_handler(int signal) {
  if (signal == SIGSEGV) {
    printf("signal SEGSEGV raised\n");
    longjmp(buf, 2);
  }
  exit(-1);
}

int main() {
  signal(SIGSEGV, sigsegv_handler);
  int status;
  if ((status = setjmp(buf)) == 0) {
    int i;
    int *p = &i + 5000;
    *p = 15;
  } else {
    printf("Something went wrong: status=%d\n", status);
  }
  return 0;
}
