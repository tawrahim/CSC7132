#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

//	int parentPid = getpid();
	int forkresult;
	int status;

	forkresult = fork();

	if (forkresult == -1) {
		perror("bad fork");
		exit(1);
	}

	if (forkresult == 0) {
		for (int i = 1; i < argc; i++) {
			// execute the command in the list
			execl(argv[i], argv[i], NULL);
		}
	} else {
		// Parent waits for child process to finish
		wait(&status);
	}
}
