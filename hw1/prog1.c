#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int status;
	char word[256];
	bool valid = true;
	int forkresult;

	forkresult = fork();

	if (forkresult == -1) {
		perror("bad fork");
		exit(1);
	}

	while (valid) {

		if (forkresult == 0) {

				printf("> ");
				fgets(word, sizeof(word), stdin);

				if (strcmp(word, "exit\n") == 0) {
					valid = false;
				}

				system(word);
				//execl("/bin/", word, NULL);

			} else {
				// Parent waits for child process to finish
				wait(&status);
				printf("I am the parent process, I waited for soo long... Now its time for me to exit \n");
				exit(0);
			}
	}
}
