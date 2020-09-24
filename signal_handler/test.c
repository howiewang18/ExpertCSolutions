#include <setjmp.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

jmp_buf buf;

void sigsegv_handler(int signal) {
  if (signal == SIGSEGV) {
    /*
          Note calling printf here is a bad practice.
          It is not safe to call all functions, such as printf, from within a
       signal handler. A useful technique is to use a signal handler to set a
       flag and then check that flag from the main program and print a message
       if required.
          */
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
