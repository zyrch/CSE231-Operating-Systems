/* Name: Rupanshu Yadav 
   Roll Number: 2019475 */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdlib.h>


int  x = 10;

int main() {

	pid_t pid = fork();

	if (pid < 0) {
		perror("Fork Failed");
	}

	if (pid == 0) {
		// child processs
		printf("Start Child Ouput: %d\n", x);
		while (x > -90) {
			x--;
			printf("Child Process: %d\n", x);
		}

		printf("Final Child Ouput: %d\n", x);
		exit(0);
	}else {
		// parent process
		printf("Start Parent Ouput: %d\n", x);
		while (x < 100) {
			x++;
			printf("Parent Process: %d\n", x);
		}

		printf("Final Parent Output: %d\n", x);
		waitpid(-1, NULL, WUNTRACED);
	}
}
