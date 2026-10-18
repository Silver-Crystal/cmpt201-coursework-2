/*
 * create a child
 * parent:
 * 	call any one of exec functions, executes ls -a
 * child:
 * 	call any exec function that executes ls -a -l -h
 * 		same as ls -alh.
 */
#include <unistd.h>
#include <stdio.h>

int main() {
	pid_t pid = fork();
	if (pid == -1) {
		perror("Fork failed.");
	}
	else if (pid == 0) {
		execlp("ls", "ls", "-a", "-l", "-h", NULL);
	}
	else {
		execl("/bin/ls", "/bin/ls", "-a", NULL);
	}
	printf("%d\n", getpid());
	return 0;
}
