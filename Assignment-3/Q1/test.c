// Name - Rupanshu  Yadav
// Roll No - 2019475

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <linux/kernel.h>
#include <omp.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/syscall.h>


void loop(){
        for(long i = 0; i<1000000000; i++) {
                // do nothing;
        }
}

int main(){
        double st;
        printf("Without Soft Realtime :\n");
        for (int i = 0; i < 10; ++i) {
                if(fork() == 0) {

                        int pid = getpid();
                        printf("Pid of Process %d\n", pid);

                        st = omp_get_wtime();
                        // execute loop
                        loop();
                        // calculate time difference
                        double time = omp_get_wtime() - st;

                        printf("Time for Process %d : %f \n", ++i,time);
                        --i;
                        exit(0);
                }
        }
        for (int i = 10; i > 0; --i) {
                // wait for child process to complete
                wait(NULL);
        }

        printf("With Soft Realtime :\n");
        for (int i = 0; i < 10; ++i) {
                if(fork() == 0) {
                        long soft_time = 20000000000;
 //                       long soft_time = -1; // to check error handling

                        int pid = getpid();

                        printf("Pid of Process %d\n", pid);

                        long res = syscall(440 , pid , soft_time);
                        perror("Console");
                        if (res < 0) {
                                return 0;
                        }
                        st = omp_get_wtime();
                        // execute loop
                        loop();
                        // calculate time difference
                        double time = omp_get_wtime() - st;

                        printf("Time for Process %d : %f \n", ++i,time);
                        --i;
                        exit(0);
                }
        }
        for (int i = 10; i > 0; --i) {
                // wait for child process to complete
                wait(NULL);
        }
        return 0;
}
