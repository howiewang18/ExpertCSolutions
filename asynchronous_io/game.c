#include <signal.h>
#include <sys/ioctl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stropts.h>

uint64_t iteration = 0;

void poll_handler(int signal) {
  int c = getchar();
  /* Bad practice.*/
  printf("got char %c at iteration %lu\n", c, iteration);
  exit(1);
  if (c == 'q') {
    system("stty sane");
    exit(0);
  }
}

/* This program does not work.*/
int main() {
  /*Set up the handler.*/
  signal(SIGPOLL, poll_handler);

  /* Disable echo back the character.*/
  system("stty raw -echo");

  /* Ask for interrupt driven input.*/
  ioctl(0, I_SETSIG, S_RDNORM);

  while (1) {
    ++iteration;
  }
  return 0;
}
