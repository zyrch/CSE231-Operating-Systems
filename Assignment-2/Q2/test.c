// Name - Rupanshu
// Roll Number - 2019475

#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#define SYS_sh_task_info 440

int main(int argc, char **argv)
{
  if (argc <= 2) {
    printf("Incorrect Arguments\n");
    return -1;
  }

  int arg = atoi(argv[1]);
  printf("Making system call with %d %s\n", arg, argv[2]);

  long res = syscall(SYS_sh_task_info, arg, argv[2]);
  printf("System call returned %ld.\n", res);
  perror("Console Output");

  return res;
}

