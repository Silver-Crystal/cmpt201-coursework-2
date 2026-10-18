// #include POSIX
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

void handlerSigC(int sig) {
  write(STDOUT_FILENO, "CTRL-C pressed\n", 15);
}

int main() {
  struct sigaction act = {0};
  act.sa_handler = handlerSigC;
  act.sa_flags = 0;
  sigemptyset(&act.sa_mask);
  int ret = sigaction(SIGINT, &act, NULL);
  if (ret == -1) {
    perror("Sigaction() failed");
    exit(EXIT_FAILURE);
  }
  while (1) {
    sleep(1);
  }
  return 0;
}
