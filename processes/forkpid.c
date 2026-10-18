#include <unistd.h>
#include <stdio.h>

int main() {
	pit_t pid = fork();
	if (pid == 0) {
		printf("CHILD: PID = %d, 
	}
