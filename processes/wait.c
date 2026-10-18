#include <sys/wait.h>
#include <stdlib.h>
include <sys/syscall.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main() {
  pid_t pid = fork();
  int wstatus = 0;
  if (pid == -1) {
    perror("waitpid");
    exit(EXIT_FAILURE);
  }
  if (pid) {
    // Parent 
    if (waitpid(pid,&wstatus, 0) == -1) {
      perror("waitpid");
      exit(EXIT_FAILURE);
    }
    else {
      if (WIFEXITED(wstatus)) {
        printf("Child done with exit status: %d\n", WEXITSTATUS(wstatus));
      }
      else {
        printf("Child did not exit normally.\n");
      }
      //printf("%s\n", WEXITSTATUS(wstatus));
    }
  }
  else if (pid == 0) {
    // Child
    if (execlp("ls", "ls", "-a", "-l", NULL) == -1) {
      perror("execlp");
      exit(EXIT_FAILURE);
    }
  }
  return 0;
}
