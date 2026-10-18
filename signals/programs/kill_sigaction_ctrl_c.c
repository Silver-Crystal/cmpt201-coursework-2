
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
  struct sigaction oact = {0};
  int ret = sigaction(SIGINT, &act, &oact);
  if (ret == -1) {
    perror("Sigaction() failed");
    exit(EXIT_FAILURE);
  }
  pid_t pid = fork();
  if (pid == -1) {
    perror("fork");
    exit(EXIT_FAILURE);
  }
  if (pid == 0) {
    sigaction(SIGINT, &oact, NULL);
    if (ret == -1) {
      perror("Sigaction() failed");
      exit(EXIT_FAILURE);
    }
    while (1) {
      sleep(2);
      printf("HEY parent!");
      if (kill(getppid(), SIGINT) == -1) {
        perror("Unable to send signal to parent.");
        exit(EXIT_FAILURE);
      }
    }
  }
  else {
  while (1) {
    printf("Parent now dozing");
    sleep(1);
  }
  }
  return 0;
}
