/* Name: Rupanshu
   Roll_Number: 2019475 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int x = 10;
void *func(void* arg) {
	printf("Start Child: %d\n", x);
	while(x > -90) {
		x--;
		printf("In Child: %d\n", x);
	}
	printf("Child Thread Answer: %d\n", x);
	pthread_exit(NULL);
}


int main() {


	pthread_t ptid;

	pthread_create(&ptid, NULL, func, NULL);

	// Parent
	printf("Start Parent: %d\n", x);
	while (x < 100) {
		x++;
		printf("In Parent: %d\n", x);
	}
	printf("Parent Thread Answer: %d\n", x);

	pthread_join(ptid, NULL);

}
